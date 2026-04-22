/*
  Use an ESP32-C6 microcontroller to act as a Zigbee Coordinator for multiple
  Zigbee Thermometer end devices.

  The example is based on the original Zigbee Thermometer example, but is modified for
  our needs. For displaying status changes, the onboard RGB LED is used.

  Hardware: ESP32-C6 with minimum 4MB Flash memory
            Zigbee Thermometer end device (indoor or outdoor, with or without display) -or-
            ESP32-C6 Zigbee Thermometer end devices

  I copy/paste the original ZigbeeThermostat.h/.cpp files into the sketch folder, renamed the
  class to ZigbeeThermostatOwn.h/.cpp and added two methods for the battery management. The 
  class is now receiving the battery voltage and remaining capacity percentage from the end device.
  Original source:
  https://github.com/espressif/arduino-esp32/blob/00e8ab428d4305436de1befad3afc1a3e83e4023/libraries/Zigbee/src/ep/ZigbeeThermostat.h
  https://github.com/espressif/arduino-esp32/blob/00e8ab428d4305436de1befad3afc1a3e83e4023/libraries/Zigbee/src/ep/ZigbeeThermostat.cpp

*/

/*
  Version Management

21.04.2026 V01 Initial version that is based on the 'single' Thermostat sketch
               ("Esp32_C6_16MB_Zigbee_Coordinator_Thermostat_OLED_v01").

21.04.2026 V05   
21.04.2026 V04 Saves the result of the router ZDO access (lqi, ieee) to a vector for a
               temporary storage, display now all lqi, for end devices reporting via a router
               the device type is now "I" = indirect
19.04.2026 V03 Tries to retrieve the LQI from all devices of the router but crashes
18.04.2026 V02 Boot button click is checked by interrupt instead of simple digitalRead  
17.04.2026 V01 Initial programming, takes up to 5 sensor values, sorted by their short address  
*/

/*
A4:C1:38:A8:3F:D4:A0:B8 real with display
A4:C1:38:A7:E0:F2:57:3E real w/o display
*/

/*
  RGB LED flashing code
during setup():
start of the sketch: red
start of the coordinator success: white
start of the coordinator failure: 10* red
device bounded to the coordinator: green

during loop():
receive Temperature for device index 0: red
receive Temperature for device index 1: green
receive Temperature for device index 2: blue
receive Temperature for device index 3: yellow
receive Temperature for device index 4: purple
receive Temperature for device index overflow: white
*/


#ifndef ZIGBEE_MODE_ZCZR
#error "Zigbee coordinator mode is not selected in Tools->Zigbee mode"
#endif

const char *PROGRAM_VERSION = "ESP32 C6 Zigbee Coordinator Multi Thermostat OLED V01";
const char *PROGRAM_VERSION_2 = "Zigbee M Temp V1";

// ------------------------------------------------------------------
// Onboard RGB LED
#include "ONBOARD_LEDS.h"

// ------------------------------------------------------------------
// Zigbee
#include "Zigbee.h"
#include "ZigbeeThermostatOwn.h"
#define THERMOSTAT_ENDPOINT_NUMBER 1

ZigbeeThermostatOwn zbThermostat = ZigbeeThermostatOwn(THERMOSTAT_ENDPOINT_NUMBER);

float sensorTemp = 0;

const uint8_t MAXIMUM_SHORT_ADDRESSES = 5;
uint16_t shortAdresses[MAXIMUM_SHORT_ADDRESSES];
float temperatures[MAXIMUM_SHORT_ADDRESSES];
uint8_t lqis[MAXIMUM_SHORT_ADDRESSES];
uint8_t deviceTypes[MAXIMUM_SHORT_ADDRESSES];
uint8_t nbrOfShortAddresses = 0;

uint32_t rxCounter = 0;

// ------------------------------------------------------------------
// Boot button

uint8_t bootButton = BOOT_PIN;  // this is GPIO 9 on most ESP32-C6 boards
volatile unsigned long lastPressTime = 0;
volatile bool buttonDown = false;
volatile bool triggerAction = false;
const unsigned long LONG_PRESS_DURATION = 3000;  // Ab wann ist es "lang"?
const unsigned long DOUBLE_CLICK_GAP = 300;      // Max. Zeit zwischen zwei Klicks
unsigned long lastReleaseTime = 0;
int clickCount = 0;

// need to run the Interrupt Service Routine (ISR) in fast RAM memory
void IRAM_ATTR handleButtonPress() {
  if (digitalRead(bootButton) == LOW) {
    buttonDown = true;
    lastPressTime = millis();
  } else {
    buttonDown = false;
    lastReleaseTime = millis();
    triggerAction = true;
  }
}

// ------------------------------------------------------------------
// SSD1306 is a 0.96-inches 128x64 px OLED display

#include "SSD1306_OLED.h"
bool refreshDisplay = false;
char buf[30];

// ------------------------------------------------------------------
// Time cluster

struct tm timeinfo = {};  // Time structure for Time cluster

// ------------------------------------------------------------------
// data/display refresh

const long DATA_REFRESH_MILLIS = 10000;  // 10 seconds
long lastDataRefreshMillis = 0;
long lastTemperatureUpdateMillis;

// ------------------------------------------------------------------
// Short Addresses

// returns the index of a short address
// if the address is unknown it is saved in the array
// if the array is full, '255' is returned
uint8_t getShortAddressIndex(uint16_t shrtAddr) {
  for (uint8_t i = 0; i < nbrOfShortAddresses; i++) {
    if (shrtAddr == shortAdresses[i]) {
      return i;
    }
  }
  // at this point no short address is found
  if (nbrOfShortAddresses < MAXIMUM_SHORT_ADDRESSES) {
    shortAdresses[nbrOfShortAddresses] = shrtAddr;
    nbrOfShortAddresses++;
    return (nbrOfShortAddresses - 1);  // the index is starting at zero
  } else {
    // overflow, the memory is full
    return 255;
  }
}

void printShortAddresses() {
  for (uint8_t i = 0; i < nbrOfShortAddresses; i++) {
    Serial.printf("%02d : 0x%04x\n", i, shortAdresses[i]);
  }
}

void storeTemperatureArray(float temp, uint8_t arrayIndex) {
  if ((arrayIndex < 255) && (arrayIndex < MAXIMUM_SHORT_ADDRESSES)) {
    temperatures[arrayIndex] = temp;
  }
}

void printTemperatureArray() {
  for (uint8_t i = 0; i < nbrOfShortAddresses; i++) {
    Serial.printf("%02d x%04x LQI: %03d\n", i, shortAdresses[i], lqis[i]);
  }
}

void storeLqiArray(uint8_t lqi, uint8_t arrayIndex) {
  if ((arrayIndex < 255) && (arrayIndex < MAXIMUM_SHORT_ADDRESSES)) {
    lqis[arrayIndex] = lqi;
  }
}

void storeDeviceTypesArray(uint8_t devType, uint8_t arrayIndex) {
  if ((arrayIndex < 255) && (arrayIndex < MAXIMUM_SHORT_ADDRESSES)) {
    deviceTypes[arrayIndex] = devType;
  }
}

void printDeviceTypesArray() {
  if (nbrOfShortAddresses == 0) {
    Serial.println("no devices connected");
    return;
  }
  for (uint8_t i = 0; i < nbrOfShortAddresses; i++) {
    Serial.printf("%02d x%04x ", i, shortAdresses[i]);
    switch (deviceTypes[i]) {
      case ESP_ZB_DEVICE_TYPE_COORDINATOR:
        Serial.println("Coordinator");
        break;
      case ESP_ZB_DEVICE_TYPE_ROUTER:
        Serial.println("Router");
        break;
      case ESP_ZB_DEVICE_TYPE_ED:
        Serial.println("End Device");
        break;
      default:
        Serial.println("Unknown");
        break;
    }
  }
}

// this is the neighbor list of the coordinator !
uint8_t getLqiFromConnectedDevices() {
  esp_zb_nwk_info_iterator_t iterator = 0;
  esp_zb_nwk_neighbor_info_t nbr_info;
  uint8_t deviceCount = 0;

  // iterate through the neighborhood table
  while (esp_zb_nwk_get_next_neighbor(&iterator, &nbr_info) == ESP_OK) {
    deviceCount++;

    // IEEE-address is an 8-byte array (little-endian)
    uint8_t *ieee = nbr_info.ieee_addr;
    char bufAddr[30];

    Serial.printf("%d. Short address: 0x%04x | IEEE: %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x LQI: %d\n",
                  deviceCount,
                  nbr_info.short_addr,
                  ieee[7], ieee[6], ieee[5], ieee[4],
                  ieee[3], ieee[2], ieee[1], ieee[0],
                  nbr_info.lqi);

    // try to find a device with this short address in the table
    uint8_t idx = getShortAddressIndex(nbr_info.short_addr);
    storeLqiArray(nbr_info.lqi, idx);
    storeDeviceTypesArray(nbr_info.device_type, idx);
  }
  return deviceCount;
}

//#include "esp_zigbee_core.h"  // Erforderlich für SDK-Zugriff
//#include "zdo/esp_zigbee_zdo_common.h"

// ------------------------------------------------------------------
// Zigbee callbacks

void receiveSensorTempWithSource(float temperature, uint8_t src_endpoint, esp_zb_zcl_addr_t src_address) {
  rxCounter++;
  if (src_address.addr_type == ESP_ZB_ZCL_ADDR_TYPE_SHORT) {
    // get the index of the short address and store the data
    uint8_t shrtAddrIdx = getShortAddressIndex(src_address.u.short_addr);
    if (shrtAddrIdx < 255) {
      Serial.printf("1 Temperature sensor value: %.2f°C from endpoint %d, address 0x%04x (idx: %d)\n", temperature, src_endpoint, src_address.u.short_addr, shrtAddrIdx);
      storeTemperatureArray(temperature, shrtAddrIdx);
      if (shrtAddrIdx == 0) {
        setRedLedFlash = true;
      } else if (shrtAddrIdx == 1) {
        setGreenLedFlash = true;
      } else if (shrtAddrIdx == 2) {
        setBlueLedFlash = true;
      } else if (shrtAddrIdx == 3) {
        setYellowLedFlash = true;
      } else if (shrtAddrIdx == 4) {
        setPurpleLedFlash = true;
      } else {
        setWhiteLedFlash = true;
      }
    } else {
      Serial.printf("1 Temperature sensor value: %.2f°C from endpoint %d, address 0x%04x (not stored)\n", temperature, src_endpoint, src_address.u.short_addr);
    }
    // 1 Temperature sensor value: 40.59°C from endpoint 10, address 0x78d1 (idx: 1)
    // 1 Temperature sensor value: 43.70°C from endpoint 11, address 0x17ba (idx: 0)
  } else {
    onboardLedFlashWhite(1, 125);
    Serial.printf("2 Temperature sensor value: %.2f°C from endpoint %d, address %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n", temperature, src_endpoint,
                  src_address.u.ieee_addr[7], src_address.u.ieee_addr[6], src_address.u.ieee_addr[5], src_address.u.ieee_addr[4], src_address.u.ieee_addr[3],
                  src_address.u.ieee_addr[2], src_address.u.ieee_addr[1], src_address.u.ieee_addr[0]);
  }
  sensorTemp = temperature;
  refreshDisplay = true;
  lastTemperatureUpdateMillis = millis();
}

// This is from the Zigbee_On_Off_Switch example
void printDeviceNames() {
  std::list<zb_device_params_t *> boundLights = zbThermostat.getBoundDevices();
  for (const auto &device : boundLights) {
    Serial.printf("Device on endpoint %d, short address: 0x%x\r\n", device->endpoint, device->short_addr);
    Serial.printf(
      "IEEE Address: %02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X\r\n", device->ieee_addr[7], device->ieee_addr[6], device->ieee_addr[5], device->ieee_addr[4],
      device->ieee_addr[3], device->ieee_addr[2], device->ieee_addr[1], device->ieee_addr[0]);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println(PROGRAM_VERSION);

  // Init the boot button switch with internal pull-up resistor
  pinMode(bootButton, INPUT_PULLUP);
  // interrupt on falling edge on button press
  attachInterrupt(digitalPinToInterrupt(bootButton), handleButtonPress, CHANGE);

  // init the onboard RGB LED
  setupOnboardLeds();
  onboardLedFlashRed(1, 125); // flash the LED in RED

  // init the SSD1306 display
  setupSsd1306();
  oDisplay1 = PROGRAM_VERSION_2;
  oDisplayData13();

  // advanced debug mode
  Zigbee.setDebugMode(true);

  //Optional Time cluster configuration
  //example time January 13, 2025 13:30:30 CET
  timeinfo.tm_year = 2026 - 1900;  // = 2026
  timeinfo.tm_mon = 4 - 1;         // April
  timeinfo.tm_mday = 18;           // 18th
  timeinfo.tm_hour = 12;           // 12 hours - 1 hour (CET)
  timeinfo.tm_min = 30;            // 30 minutes
  timeinfo.tm_sec = 30;            // 30 seconds
  timeinfo.tm_isdst = -1;

  // Set time and gmt offset (timezone in seconds -> CET = +3600 seconds)
  zbThermostat.addTimeCluster(timeinfo, 3600);

  // Optional to allow multiple light to bind to the thermostat
  zbThermostat.allowMultipleBinding(true);

  // register the callback for temperature readings
  zbThermostat.onTempReceiveWithSource(receiveSensorTempWithSource);

  Serial.println("All callbacks are registered");

  // Optional: set Zigbee device name and model
  zbThermostat.setManufacturerAndModel("AndroidCrypto", "ZigbeeThermostatOwn");

  // Add endpoint to Zigbee Core
  Zigbee.addEndpoint(&zbThermostat);

  // Open network for 180 seconds after boot
  Zigbee.setRebootOpenNetwork(180);
  oDisplay2 = "Network open";
  oDisplayData13();

  // When all EPs are registered, start Zigbee with ZIGBEE_COORDINATOR mode
  if (!Zigbee.begin(ZIGBEE_COORDINATOR)) {
    Serial.println("Zigbee failed to start!");
    Serial.println("Rebooting...");
    onboardLedFlashRed(10, 125);
    ESP.restart();
  }
  Serial.println("The Zigbee Coordinator has started");
  onboardLedFlashWhite(1, 125);
  oDisplay3 = "Coordinator strt";
  oDisplayData13();

  Serial.println("Waiting for a temperature sensor to bound to the thermostat");
  while (!zbThermostat.bound()) {
    Serial.printf(".");
    delay(500);
  }
  Serial.println();
  Serial.println("A device is bounded to the Coordinator");
  onboardLedFlashGreen(1, 125);
  oDisplay4 = "Device bounded";
  oDisplayData13();
  delay(1000);

  printDeviceNames();
  oDisplayClearData();
  oDisplayData13();
  refreshDisplay = true;
}

void printTemperaturesOld() {
  uint8_t idx = 0;
  Serial.printf("Current Temperature sensors: %d\n", nbrOfShortAddresses);
  sprintf(buf, "%d 0x%04x: %2.2f C", idx, shortAdresses[idx], temperatures[idx]);
  Serial.println(buf);
  oDisplay1 = buf;
  idx++;
  sprintf(buf, "%d 0x%04x: %2.2f C", idx, shortAdresses[idx], temperatures[idx]);
  Serial.println(buf);
  oDisplay2 = buf;
  idx++;
  sprintf(buf, "%d 0x%04x: %2.2f C", idx, shortAdresses[idx], temperatures[idx]);
  Serial.println(buf);
  oDisplay3 = buf;
  idx++;
  sprintf(buf, "%d 0x%04x: %2.2f C", idx, shortAdresses[idx], temperatures[idx]);
  Serial.println(buf);
  oDisplay4 = buf;
  idx++;
  sprintf(buf, "%d 0x%04x: %2.2f C", idx, shortAdresses[idx], temperatures[idx]);
  Serial.println(buf);
  oDisplay5 = buf;
  oDisplayData13();
}

void printLqis() {
  getLqiFromConnectedDevices();
  uint8_t idx = 0;
  Serial.printf("Current LQI devices: %d\n", nbrOfShortAddresses);
  sprintf(buf, "%d 0x%04x: %3d", idx, shortAdresses[idx], lqis[idx]);
  Serial.println(buf);
  oDisplay1 = buf;
  idx++;
  sprintf(buf, "%d 0x%04x: %3d", idx, shortAdresses[idx], lqis[idx]);
  Serial.println(buf);
  oDisplay2 = buf;
  idx++;
  sprintf(buf, "%d 0x%04x: %3d", idx, shortAdresses[idx], lqis[idx]);
  Serial.println(buf);
  oDisplay3 = buf;
  idx++;
  sprintf(buf, "%d 0x%04x: %3d", idx, shortAdresses[idx], lqis[idx]);
  Serial.println(buf);
  oDisplay4 = buf;
  idx++;
  sprintf(buf, "%d 0x%04x: %3d", idx, shortAdresses[idx], lqis[idx]);
  Serial.println(buf);
  oDisplay5 = buf;
  oDisplayData13();
}

// https://github.com/espressif/esp-zigbee-sdk/blob/21f65f6ad5ae76b526ccdaf21c7ec1e21ab61c3b/components/esp-zigbee-lib/include/compat/nwk/esp_zigbee_nwk.h#L21
// As we are the Coordinator, empty entries or not retrieved would be shown as coordinator, so the hack is showing end device instea
String getDeviceTypeShortName(uint8_t devType) {
  String ret;
  switch (devType) {
    case ESP_ZB_DEVICE_TYPE_COORDINATOR:
      //ret = "C";
      ret = "E";  // hack, see above
      break;
    case ESP_ZB_DEVICE_TYPE_ROUTER:
      ret = "R";
      break;
    case ESP_ZB_DEVICE_TYPE_ED:
      ret = "E";
      break;
    default:
      ret = "U";
      break;
  }
  return ret;
}

void printTemperaturesLqis() {
  getLqiFromConnectedDevices();
  uint8_t idx = 0;
  Serial.printf("Current LQI devices: %d\n", nbrOfShortAddresses);
  sprintf(buf, "%d %04x:%4.1f %3d%s", idx, shortAdresses[idx], temperatures[idx], lqis[idx], getDeviceTypeShortName(deviceTypes[idx]));
  Serial.println(buf);
  oDisplay1 = buf;
  idx++;
  sprintf(buf, "%d %04x:%4.1f %3d%s", idx, shortAdresses[idx], temperatures[idx], lqis[idx], getDeviceTypeShortName(deviceTypes[idx]));
  Serial.println(buf);
  oDisplay2 = buf;
  idx++;
  sprintf(buf, "%d %04x:%4.1f %3d%s", idx, shortAdresses[idx], temperatures[idx], lqis[idx], getDeviceTypeShortName(deviceTypes[idx]));
  Serial.println(buf);
  oDisplay3 = buf;
  idx++;
  sprintf(buf, "%d %04x:%4.1f %3d%s", idx, shortAdresses[idx], temperatures[idx], lqis[idx], getDeviceTypeShortName(deviceTypes[idx]));
  Serial.println(buf);
  oDisplay4 = buf;
  idx++;
  sprintf(buf, "%d %04x:%4.1f %3d%s", idx, shortAdresses[idx], temperatures[idx], lqis[idx], getDeviceTypeShortName(deviceTypes[idx]));
  Serial.println(buf);
  oDisplay5 = buf;
  oDisplayData13();
}

void printTemperaturesLqisOld() {
  getLqiFromConnectedDevices();
  uint8_t idx = 0;
  Serial.printf("Current LQI devices: %d\n", nbrOfShortAddresses);
  sprintf(buf, "%d %04x:%2.1fC %2d", idx, shortAdresses[idx], temperatures[idx], lqis[idx]);
  Serial.println(buf);
  oDisplay1 = buf;
  idx++;
  sprintf(buf, "%d %04x:%2.1fC %2d", idx, shortAdresses[idx], temperatures[idx], lqis[idx]);
  Serial.println(buf);
  oDisplay2 = buf;
  idx++;
  sprintf(buf, "%d %04x:%2.1fC %2d", idx, shortAdresses[idx], temperatures[idx], lqis[idx]);
  Serial.println(buf);
  oDisplay3 = buf;
  idx++;
  sprintf(buf, "%d %04x:%2.1fC %2d", idx, shortAdresses[idx], temperatures[idx], lqis[idx]);
  Serial.println(buf);
  oDisplay4 = buf;
  idx++;
  sprintf(buf, "%d %04x:%2.1fC %2d", idx, shortAdresses[idx], temperatures[idx], lqis[idx]);
  Serial.println(buf);
  oDisplay5 = buf;
  oDisplayData13();
}

// avoid out of memory errors or crashes
void checkMemory() {
  Serial.println("--- Memory-Check ---");
  Serial.printf("Current Heap available: %d Bytes\n", ESP.getFreeHeap());
  Serial.printf("Lowest Heap (Min): %d Bytes\n", ESP.getMinFreeHeap());
  Serial.printf("Largest available block: %d Bytes\n\n", ESP.getMaxAllocHeap());
}

void loop() {

  rgbLedFlashLoop();  // delayless RGB LED flashing

  // handle button press for factory reset and reporting
  unsigned long now = millis();
  if (buttonDown && (now - lastPressTime > LONG_PRESS_DURATION)) {
    Serial.println("Result: LONG PRESS");
    Serial.println("Resetting Zigbee to factory and rebooting in 1s.");
    setPurpleLedFlash = true;
    delay(1000);
    Zigbee.factoryReset();
    // this will not called as the factory reset reboots the esp32-c6...
    buttonDown = false; 
    clickCount = 0; 
  }
  if (triggerAction && !buttonDown) {
    triggerAction = false;
    if (now - lastPressTime < LONG_PRESS_DURATION) {
      clickCount++;
    }
  }
  if (clickCount > 0 && (now - lastReleaseTime > DOUBLE_CLICK_GAP) && !buttonDown) {
    if (clickCount == 1) {
      Serial.println("Result: SINGLE CLICK");
      setMintLedFlash = true;
    } else if (clickCount >= 2) {
      Serial.println("result: DOUBLE CLICK");
      Zigbee.openNetwork(180);
      Serial.println("The network is open for 180 seconds");
      setYellowLedFlash = true;
    }
    clickCount = 0;
  }

  if ((millis() - lastDataRefreshMillis) > DATA_REFRESH_MILLIS) {
    // memory check
    checkMemory();
    refreshDisplay = true;
    lastDataRefreshMillis = millis();
  }


  if (refreshDisplay) {
    printTemperaturesLqis();  // prints short address, temperature and lqi in one row
    refreshDisplay = false;
  }
}
