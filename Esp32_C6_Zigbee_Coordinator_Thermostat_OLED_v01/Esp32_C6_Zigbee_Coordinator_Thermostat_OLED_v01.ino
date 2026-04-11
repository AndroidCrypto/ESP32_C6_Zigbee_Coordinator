/*
  Use an ESP32-C6 microcontroller to act as a Zigbee Coordinator for a
  Zigbee Thermometer end device.

  The example is based on the original Zigbee Thermometer example, but is modified for
  our needs. For displaying status changes, the onboard RGB LED is used.

  See the RGB LED flashing code for detailled info.

  The number of callbacks fired is displayed in the last line of the display. The seconds
  since the last temperature update is displayed beneath. If the battery voltage drops below
  LOW_BATTERY_THRESHOLD (2.4 volts) a warning is displayed instead.

  Hardware: ESP32-C6 with minimum 4MB Flash memory
            Zigbee Thermometer end device (indoor or outdoor, with or without display)

  I copied/pasted the original ZigbeeThermostat.h/.cpp files into the sketch folder, renamed the
  class to ZigbeeThermostatOwn.h/.cpp and added two methods for the battery management. The 
  class is now receiving the battery voltage and remaining capacity percentage from the end device.
  Original source:
  https://github.com/espressif/arduino-esp32/blob/00e8ab428d4305436de1befad3afc1a3e83e4023/libraries/Zigbee/src/ep/ZigbeeThermostat.h
  https://github.com/espressif/arduino-esp32/blob/00e8ab428d4305436de1befad3afc1a3e83e4023/libraries/Zigbee/src/ep/ZigbeeThermostat.cpp
*/

/*
  RGB LED flashing code
  in setup() phase:
  one flash RED: program started, init for onboard LEDs and display is done
  one flash WHITE: Zigbee coordinator is started
  ten flashed RED: start of Zigbee coordinator failed
  one flash GREEN: minimum one device bounded
  one flash BLUE: waiting for actions

  in loop() phase:
  one flash RED: temperature reading callback fired
  one flash BLUE: humidity reading callback fired
  one flash GREEN: battery voltage callback fired
  one flash WHITE: remaining battery capacity callback fired
*/

/*
Settings:
ESP32-C6 Dev Board (regular board)
CDC on Boot enabled
Core Debug Level verbose [highest level]
Erase all flash enabled): don't forget to enable during testing, or pairing with a new project will fail
Flash size: 8 MB
Partition scheme: Zigbee ZCCR 8 MB with SPIFFS
Zigbee Mode ZCZR with Debug (coordinator/router)
*/

/*
On an ESP32-C6 Super Mini with 4 MB Flash you receive an upload error when selecting:
Partition scheme: Zigbee ZCCR 4 MB with SPIFFS

Sketch uses 1407544 bytes (107%) of program storage space. Maximum is 1310720 bytes.
Global variables use 40124 bytes (12%) of dynamic memory, leaving 287556 bytes for local variables. Maximum is 327680 bytes.
Sketch too big; see https://support.arduino.cc/hc/en-us/articles/360013825179 for tips on reducing it.
text section exceeds available space in board
Compilation error: text section exceeds available space in board

In this case, use the 'Custom' partition scheme and the partitions.csv included with this folder.

*/

#ifndef ZIGBEE_MODE_ZCZR
#error "Zigbee coordinator mode is not selected in Tools->Zigbee mode"
#endif

const char *PROGRAM_VERSION = "ESP32 C6 Zigbee Coordinator Thermostat OLED V01";
const char *PROGRAM_VERSION_2 = "Zigbee Temp V01";

// ------------------------------------------------------------------
// Onboard RGB LED
#include "ONBOARD_LEDS.h"

// ------------------------------------------------------------------
// Zigbee
#include "Zigbee.h"
#include "ZigbeeThermostatOwn.h"
#define THERMOSTAT_ENDPOINT_NUMBER 1

ZigbeeThermostatOwn zbThermostat = ZigbeeThermostatOwn(THERMOSTAT_ENDPOINT_NUMBER);

float sensorTemp = 0, sensorHumid = 0;
float batteryVoltage = 0;
uint8_t batteryPercentage = 0;
float prevTemp = 0, prevHumid = 0;
float prevBatteryVoltage = 0;
int8_t prevBatteryPercentage = 0;

char budc[8]; // batteryUndervoltageDetectorCount as char
const float LOW_BATTERY_THRESHOLD = 2.4;
uint32_t rxCounter = 0;

// ------------------------------------------------------------------
// Boot button

uint8_t bootButton = BOOT_PIN;  // this is GPIO 9 on most ESP32-C6 boards

// ------------------------------------------------------------------
// SSD1306 is a 0.96-inches 128x64 px OLED display

#include "SSD1306_OLED.h"
bool refreshDisplay = false;
char buf[30];

// ------------------------------------------------------------------
// data/display refresh

const long DATA_REFRESH_MILLIS = 1000;  // 10 seconds
long lastDataRefreshMillis = 0;
long lastTemperatureUpdateMillis, lastHumidityUpdateMillis, lastBatteryVoltageUpdateMillis, lastBatteryPercentageUpdateMillis;

// ------------------------------------------------------------------
// Zigbee callbacks

void receiveSensorTempWithSource(float temperature, uint8_t src_endpoint, esp_zb_zcl_addr_t src_address) {
  onboardLedFlashRed(1, 125);  // flash the LED
  rxCounter++;
  if (src_address.addr_type == ESP_ZB_ZCL_ADDR_TYPE_SHORT) {
    Serial.printf("1 Temperature sensor value: %.2f°C from endpoint %d, address 0x%04x\n", temperature, src_endpoint, src_address.u.short_addr);
  } else {
    Serial.printf(
      "2 Temperature sensor value: %.2f°C from endpoint %d, address %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n", temperature, src_endpoint,
      src_address.u.ieee_addr[7], src_address.u.ieee_addr[6], src_address.u.ieee_addr[5], src_address.u.ieee_addr[4], src_address.u.ieee_addr[3],
      src_address.u.ieee_addr[2], src_address.u.ieee_addr[1], src_address.u.ieee_addr[0]);
  }
  prevTemp = sensorTemp;
  sensorTemp = temperature;
  refreshDisplay = true;
  lastTemperatureUpdateMillis = millis();
}

void receiveSensorHumidWithSource(float humidity, uint8_t src_endpoint, esp_zb_zcl_addr_t src_address) {
  onboardLedFlashBlue(1, 125);  // flash the LED
  rxCounter++;
  if (src_address.addr_type == ESP_ZB_ZCL_ADDR_TYPE_SHORT) {
    Serial.printf("1 Humidity sensor value: %.2f percent from endpoint %d, address 0x%04x\n", humidity, src_endpoint, src_address.u.short_addr);
  } else {
    Serial.printf(
      "2 Humidity sensor value: %.2f percent from endpoint %d, address %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n", humidity, src_endpoint,
      src_address.u.ieee_addr[7], src_address.u.ieee_addr[6], src_address.u.ieee_addr[5], src_address.u.ieee_addr[4], src_address.u.ieee_addr[3],
      src_address.u.ieee_addr[2], src_address.u.ieee_addr[1], src_address.u.ieee_addr[0]);
  }
  prevHumid = sensorHumid;
  sensorHumid = humidity;
  refreshDisplay = true;
  lastHumidityUpdateMillis = millis();
}

void receiveBatteryVoltageWithSource(uint8_t voltage, uint8_t src_endpoint, esp_zb_zcl_addr_t src_address) {
  onboardLedFlashGreen(1, 125);  // flash the LED
  rxCounter++;
  if (src_address.addr_type == ESP_ZB_ZCL_ADDR_TYPE_SHORT) {
    Serial.printf("1 Battery Voltage value: %d Volts from endpoint %d, address 0x%04x\n", voltage, src_endpoint, src_address.u.short_addr);
  } else {
    Serial.printf(
      "2 Battery Voltage value: %d Volts from endpoint %d, address %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n", voltage, src_endpoint,
      src_address.u.ieee_addr[7], src_address.u.ieee_addr[6], src_address.u.ieee_addr[5], src_address.u.ieee_addr[4], src_address.u.ieee_addr[3],
      src_address.u.ieee_addr[2], src_address.u.ieee_addr[1], src_address.u.ieee_addr[0]);
  }
  prevBatteryVoltage = batteryVoltage;
  batteryVoltage = voltage / 10.0;
  refreshDisplay = true;
  lastBatteryVoltageUpdateMillis = millis();
}

void receiveBatteryPercentageWithSource(uint8_t percentage, uint8_t src_endpoint, esp_zb_zcl_addr_t src_address) {
  onboardLedFlashWhite(1, 125);  // flash the LED
  rxCounter++;
  if (src_address.addr_type == ESP_ZB_ZCL_ADDR_TYPE_SHORT) {
    Serial.printf("1 Battery Percentage value: %d percent from endpoint %d, address 0x%04x\n", percentage, src_endpoint, src_address.u.short_addr);
  } else {
    Serial.printf(
      "2 Battery Percentage value: %d %% from endpoint %d, address %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n", percentage, src_endpoint,
      src_address.u.ieee_addr[7], src_address.u.ieee_addr[6], src_address.u.ieee_addr[5], src_address.u.ieee_addr[4], src_address.u.ieee_addr[3],
      src_address.u.ieee_addr[2], src_address.u.ieee_addr[1], src_address.u.ieee_addr[0]);
  }
  prevBatteryPercentage = batteryPercentage;
  batteryPercentage = percentage / 2;
  refreshDisplay = true;
  lastBatteryPercentageUpdateMillis = millis();
}

// This is from the Zigbee_On_Off_Switch example
// Optional: List all bound devices and read manufacturer and model name
void printDeviceNames() {
  std::list<zb_device_params_t *> boundLights = zbThermostat.getBoundDevices();
  for (const auto &device : boundLights) {
    Serial.printf("Device on endpoint %d, short address: 0x%x\r\n", device->endpoint, device->short_addr);
    Serial.printf(
      "IEEE Address: %02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X\r\n", device->ieee_addr[7], device->ieee_addr[6], device->ieee_addr[5], device->ieee_addr[4],
      device->ieee_addr[3], device->ieee_addr[2], device->ieee_addr[1], device->ieee_addr[0]);
    // both methods are defined in ZigbeeEP
    char *manufacturer = zbThermostat.readManufacturer(device->endpoint, device->short_addr, device->ieee_addr);
    char *model = zbThermostat.readModel(device->endpoint, device->short_addr, device->ieee_addr);
    if (manufacturer != nullptr) {
      Serial.printf("Device manufacturer: %s\r\n", manufacturer);
    } else {
      Serial.println(F("No device manufacturer retrieved"));
    }
    if (model != nullptr) {
      Serial.printf("Device model: %s\r\n", model);
    } else {
      Serial.println(F("No device model retrieved"));
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println(PROGRAM_VERSION);

  // Init the boot button switch
  pinMode(bootButton, INPUT_PULLUP);

  // init the onboard RGB LED
  setupOnboardLeds();
  onboardLedFlashRed(1, 125);  // flash the LED in RED

  // init the SSD1306 display
  setupSsd1306();
  oDisplay1 = PROGRAM_VERSION_2;
  oDisplayData13();

  // advanced debug mode
  Zigbee.setDebugMode(true);

  // register the callback for temperature readings
  zbThermostat.onTempReceiveWithSource(receiveSensorTempWithSource);
  // register the callback for humidity readings
  zbThermostat.onHumidityReceiveWithSource(receiveSensorHumidWithSource);

  // register the callback for the Power Config cluster: battery voltage readings
  zbThermostat.onBatteryVoltageReceiveWithSource(receiveBatteryVoltageWithSource);

  // register the callback for the Power Config cluster: battery percentage readings
  zbThermostat.onBatteryPercentReceiveWithSource(receiveBatteryPercentageWithSource);
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
  oDisplay3 = "Coordinator started";
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
  onboardLedFlashBlue(1, 125);
  refreshDisplay = true;
}

void loop() {

  // Checking button for factory reset and reporting
  if (digitalRead(bootButton) == LOW) {  // Push button pressed
    // Key debounce handling
    delay(100);
    int startTime = millis();
    while (digitalRead(bootButton) == LOW) {
      delay(50);
      if ((millis() - startTime) > 3000) {
        // If key pressed for more than 3secs, factory reset Zigbee and reboot
        Serial.println("Resetting Zigbee to factory and rebooting in 1s.");
        onboardLedFlashGreen(10, 125);
        delay(1000);
        Zigbee.factoryReset();
      }
    }
  }

  if ((millis() - lastDataRefreshMillis) > DATA_REFRESH_MILLIS) {
    Serial.printf("Temperature: %02.2f Celsius Humidity: %02.1f %%rH Battery voltage: %1.2f voltage remaining capacity: %3d %%\n", sensorTemp, sensorHumid, batteryVoltage, batteryPercentage);
    long currentUpdate = millis();
    uint32_t lastUpdateTemperatureSeconds = (currentUpdate - lastTemperatureUpdateMillis) / 1000;
    uint32_t lastUpdateHumiditySeconds = (currentUpdate - lastHumidityUpdateMillis) / 1000;
    uint32_t lastUpdateBatteryVoltageSeconds = (currentUpdate - lastBatteryVoltageUpdateMillis) / 1000;
    uint32_t lastUpdateBatteryPercentageSeconds = (currentUpdate - lastBatteryPercentageUpdateMillis) / 1000;
    Serial.printf("Last update for Temperature: %d (%1.2f) Humidity: %d (%1.2f) Battery voltage: %d (%1.2f) percentage: %d (%d) seconds\n",
                  lastUpdateTemperatureSeconds, sensorTemp - prevTemp, lastUpdateHumiditySeconds, sensorHumid - prevHumid,
                  lastUpdateBatteryVoltageSeconds, batteryVoltage - prevBatteryVoltage, lastUpdateBatteryPercentageSeconds, batteryPercentage - prevBatteryPercentage);
    refreshDisplay = true;                  
    lastDataRefreshMillis = millis();
  }

  if (refreshDisplay) {
    Serial.println("refreshDisplay triggered");
    sprintf(buf, "Temp:  %2.2f C", sensorTemp);
    Serial.println(buf);
    oDisplay1 = buf;
    sprintf(buf, "Humid: %2.2f %%rH", sensorHumid);
    oDisplay2 = buf;
    sprintf(buf, "Bat V: %2.2f volts", batteryVoltage);
    oDisplay3 = buf;
    sprintf(buf, "Bat C: %2d %%", batteryPercentage);
    oDisplay4 = buf;

    // low voltage detection
    if (batteryVoltage < LOW_BATTERY_THRESHOLD) {
      sprintf(budc, "LOW BAT");
      sprintf(buf, "C: %d %s", rxCounter, budc);
    } else {
      sprintf(buf, "C: %d T U.%ds", rxCounter, (millis() - lastTemperatureUpdateMillis) / 1000);
    }
    oDisplay5 = buf;
    oDisplayData13();
    refreshDisplay = false;
  }
}
