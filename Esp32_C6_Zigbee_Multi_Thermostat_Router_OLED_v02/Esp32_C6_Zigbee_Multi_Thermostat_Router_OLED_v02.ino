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
26.04.2026 V02 Code cleaning
21.04.2026 V01 Initial version that is based on the 'single' Thermostat sketch
               ("Esp32_C6_16MB_Zigbee_Coordinator_Thermostat_OLED_v01"). It is
               displaying the LQI from all devices connected to the coordinator
               (this device) with device type 'E' and the LQI from devices 
               connected to the router with the device type 'I'
  
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

const char *PROGRAM_VERSION = "ESP32 C6 Zigbee Coordinator Multi Thermostat Router OLED V02";
const char *PROGRAM_VERSION_2 = "Zigbee MR Temp V2";

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
// Router Neighbor List

#include <vector>
#include "esp_zigbee_core.h"

// temporary list
std::vector<esp_zb_zdo_neighbor_table_list_record_t> neighborList;
bool receivedRouterNeighborData = false;
bool isReceivedRouterNeighborDataSuccess = false;

uint16_t firstRouterShortAddress;

bool oneTimeRouterLqiRequest = false;

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

const long ROUTER_DATA_REFRESH_MILLIS = 25000;  // 25 seconds
long lastRouterDataRefreshMillis = 0;

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

// this does not add a new short address, is used for
// the router neighbor callback
uint8_t getShortAddressIndexNoAdd(uint16_t shrtAddr) {
  for (uint8_t i = 0; i < nbrOfShortAddresses; i++) {
    if (shrtAddr == shortAdresses[i]) {
      return i;
    }
  }
  // at this point no short address is found
  return 255;
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

// returns the short address of the first router found in the neighbor table
// gives 0x0000 if no router was found
uint16_t getFirstRouterShortAddress() {
  for (uint8_t i = 0; i < nbrOfShortAddresses; i++) {
    if (deviceTypes[i] == ESP_ZB_DEVICE_TYPE_ROUTER) {
      //return the shortAddress of this device
      return shortAdresses[i];
    }
  }
  // no router was found
  return 0x0000;
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

    // the IEEE-address is an 8-byte array (little-endian)
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

// Note: this method is using paging, because the router does not provide the complete
// data set at all, but just 4 devices.
// this has to get placed above the callback 'lqi_mgmt_cb' because it is called recursively
void getLQIFromRouter(uint16_t router_short_addr, uint8_t startIndex = 0) {
  Serial.printf("start getLQIFromRouter for 0x%04x (Index: %d)\n", router_short_addr, startIndex);

  static esp_zb_zdo_mgmt_lqi_req_param_t lqi_req;
  memset(&lqi_req, 0, sizeof(esp_zb_zdo_mgmt_lqi_req_param_t));

  lqi_req.dst_addr = router_short_addr;
  lqi_req.start_index = startIndex;

  // clear list on first call only
  if (startIndex == 0) {
    neighborList.clear();
  }

  esp_zb_lock_acquire(portMAX_DELAY);
  // we provide the router_short_addr as user_ctx to use paging in the callback
  esp_zb_zdo_mgmt_lqi_req(&lqi_req, lqi_mgmt_cb, (void *)(uintptr_t)router_short_addr);
  esp_zb_lock_release();

  Serial.println("done getLQIFromRouter");
}

// callback is vector based and uses paging
// this is the neighbor table of the ROUTER, not the coordinator !
static void lqi_mgmt_cb(const esp_zb_zdo_mgmt_lqi_rsp_s *resp, void *user_ctx) {
  receivedRouterNeighborData = true;
  uint16_t router_addr = (uint16_t)(uintptr_t)user_ctx;

  if (resp && resp->status == ESP_ZB_ZDP_STATUS_SUCCESS) {
    esp_zb_zdo_neighbor_table_list_record_t *neighbor = resp->neighbor_table_list;

    // 1. Use neighbor_table_list_count for the loop
    for (uint8_t i = 0; i < resp->neighbor_table_list_count; i++) {
      neighborList.push_back(*neighbor);
      neighbor++;
    }

    // 2. get the next index
    uint8_t nextIndex = resp->start_index + resp->neighbor_table_list_count;

    // 3. compare with neighbor_table_entries (total number of entries)
    if (nextIndex < resp->neighbor_table_entries) {
      Serial.printf("Paging: %d of %d loaded. Next Page...\n", nextIndex, resp->neighbor_table_entries);
      getLQIFromRouter(router_addr, nextIndex);
    } else {
      Serial.printf("Ready: All %d Neighbors of 0x%04x stored.\n", (int)neighborList.size(), router_addr);
      isReceivedRouterNeighborDataSuccess = true;
    }
  } else {
    Serial.printf("LQI Error on Router 0x%04x\n", router_addr);
    isReceivedRouterNeighborDataSuccess = false;
  }
}

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
String getDeviceTypeShortNameOld(uint8_t devType) {
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

// note: as we are testing with a router, the connected end devices
// to the router are hardcoded to "E" instead of "C" as the device
// type is not visible for the coordinator
// https://github.com/espressif/esp-zigbee-sdk/blob/21f65f6ad5ae76b526ccdaf21c7ec1e21ab61c3b/components/esp-zigbee-lib/include/compat/nwk/esp_zigbee_nwk.h#L21
// with router neighbor list there is a manual addition because the Espressif list does not have this entry:
// ESP_ZB_DEVICE_TYPE_ED_ROUTER = 0x10, meaning an end device is connected via a router
// my deviceShortName is "I" for these devices (indirect)
#define ESP_ZB_DEVICE_TYPE_ED_ROUTER 0x10
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
    case ESP_ZB_DEVICE_TYPE_ED_ROUTER:
      ret = "I";
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

  if (millis() - lastRouterDataRefreshMillis > ROUTER_DATA_REFRESH_MILLIS) {
    // don't run this task too often as this makes your Zigbee network unstable
    // 1 get the router address
    firstRouterShortAddress = getFirstRouterShortAddress();
    // 2 check if the first router address is 0x0000 meaning there is no router
    if (firstRouterShortAddress == 0x0000) {
      Serial.println("This coordinator has no router connected");
      lastRouterDataRefreshMillis = millis();
      return;
    }
    Serial.printf("get the LQI values from the first router 0x%04x\n", firstRouterShortAddress);
    // 3 request the data
    getLQIFromRouter(firstRouterShortAddress);
    lastRouterDataRefreshMillis = millis();
  }

    // this is just a printer, needs to get improved to put the lqis in the main array
  // https://github.com/espressif/esp-zigbee-sdk/blob/21f65f6ad5ae76b526ccdaf21c7ec1e21ab61c3b/components/esp-zigbee-lib/include/compat/zdo/esp_zigbee_zdo_command.h#L427
  if (receivedRouterNeighborData) {
    // we received a callback
    receivedRouterNeighborData = false;
    if (isReceivedRouterNeighborDataSuccess) {
      // print only when success
      Serial.println("--- Current Router Neighbor table ---");

      for (const auto &n : neighborList) {
        uint16_t shortAddressCB = n.network_addr;
        Serial.printf("Short Address: 0x%04X | IEEE: %s | LQI: %3d | Depth: %d\n",
                      shortAddressCB,
                      Zigbee.formatIEEEAddress(n.extended_addr),  // this is the ieee address
                      n.lqi,
                      n.depth);
        // try to find the short address in the main array, skip 0x0000
        if (shortAddressCB != 0x0000) {
          uint8_t idx = getShortAddressIndexNoAdd(shortAddressCB);
          storeLqiArray(n.lqi, idx);
          // identify this device as 'indirect' end device
          storeDeviceTypesArray(ESP_ZB_DEVICE_TYPE_ED_ROUTER, idx);
        }
      }
      Serial.println("--- Current Router Neighbor table END ---");
      // release the memory as all data is processed
      neighborList.shrink_to_fit();
    }
  }

  if ((millis() - lastDataRefreshMillis) > DATA_REFRESH_MILLIS) {
    // memory check
    checkMemory();
    refreshDisplay = true;
    lastDataRefreshMillis = millis();
  }

  if (refreshDisplay) {
    printTemperaturesLqis(); // prints short address, temperature and lqi in one row
    refreshDisplay = false;
  }
}
