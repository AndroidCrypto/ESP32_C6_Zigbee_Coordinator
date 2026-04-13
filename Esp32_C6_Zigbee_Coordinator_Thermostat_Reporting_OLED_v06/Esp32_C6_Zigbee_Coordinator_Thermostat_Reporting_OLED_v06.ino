/*
  Use an ESP32-C6 microcontroller to act as a Zigbee Coordinator for a
  Zigbee Thermometer end device.

  The example is based on the original Zigbee Thermometer example, but is modified for
  our needs. For displaying status changes, the onboard RGB LED is used.

  Hardware: ESP32-C6 with minimum 4MB Flash memory
            Zigbee Thermometer end device (indoor or outdoor, with or without display)

  I copy/paste the original ZigbeeThermostat.h/.cpp files into the sketch folder, renamed the
  class to ZigbeeThermostatOwn.h/.cpp and added two methods for the battery management. The 
  class is now receiving the battery voltage and remaining capacity percentage from the end device.
  Original source:
  https://github.com/espressif/arduino-esp32/blob/00e8ab428d4305436de1befad3afc1a3e83e4023/libraries/Zigbee/src/ep/ZigbeeThermostat.h
  https://github.com/espressif/arduino-esp32/blob/00e8ab428d4305436de1befad3afc1a3e83e4023/libraries/Zigbee/src/ep/ZigbeeThermostat.cpp

*/

/*
  Version management
13.04.2026 V06 This version is using a set Temperature|Humidity reporting but without any
               storage in SPIFFS. The battery related reportings are removed because they did 
               not work in my environment.
12.04.2026 V05 The power management reporting (battery voltage and capacity) is sending
               multiple data, this is skipping updates within some seconds
               On the display, beneath the rxCounter the seconds since the last temperature and 
               battery voltage are displayed
               When a temperature callback is fired, I'm sending a setTemperatureHumidityReporting
               request for each 60 seconds and this is working. The request for Battery
               Voltage & Capacity is transmitted as well, but I don't see a shorter intervall
               for reporting.
28.03.2026 V04 The measurement and difference data of all 4 parameters are stored additionally
               in CSV files in SPIFFS on demand (#define STORE_IN_SPIFFS true enabled)  
28.03.2026 V03 On single button press, the last 20 measures are displayed on the OLED for
               all 4 parameters. On double press, the difference in value and seconds to 
               the last data point is displayed
28.03.2026 V02 Data of all 4 parameters are stored in a ring storage along with a timestamp.
               On a single boot button click the data is printed on the Serial Monitor.
27.03.2026 V01 Initial programming. The received data (temperature, humidity, battery voltage, 
               battery remaining capacity) is displayed on the OLED. With a long button press
               (> 3 seconds) a factory reset is run.
*/

/*
  This is an advanced version that forces a setTemperatureReporting and setHumidityReporting
  when a temperature or humidity attribute is reported. As the maximum interval is set to 60,
  latest after 60 seconds a new attribute reporting is done.
  I'm using a combined request to avoid that the device is in sleep mode when the request is
  send to the device.
  The display has new structure: the battery capacity was removed and the current/previous
  second counter is for temperature, humidity and battery voltage now.
*/

/*
setTemperatureReporting interval min 60 max 3600 seconds change 50 Celsius
[294397][I][ZigbeeThermostatOwn.cpp:489] setTemperatureReporting(): Sending 'configure temperature reporting' command
[294399][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[294399][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 199, cluster_id: 0x0402, asdu_length: 8
[294400][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xc6c7, profile_id: 0x0104, security_status: 0, lqi: 56, rx_time: 0
[294401][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0xc6c7) src endpoint(1) to dst endpoint(1) cluster(0x402)
*/

#ifndef ZIGBEE_MODE_ZCZR
#error "Zigbee coordinator mode is not selected in Tools->Zigbee mode"
#endif

const char *PROGRAM_VERSION = "ESP32 C6 SM Zigbee Coordinator Thermostat OLED V06";
const char *PROGRAM_VERSION_2 = "Zigbee Temp V06";

#define STORE_IN_SPIFFS true

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

char budc[8];  // batteryUndervoltageDetectorCount as char
uint32_t rxCounter = 0;

// ------------------------------------------------------------------
// Boot button
// using the OneButton library, version 2.6.2
#include "OneButton.h"  // https://github.com/mathertel/OneButton
OneButton bootButton;

const long BOOT_BUTTON_FACTORY_RESET_MILLIS = 3000;

const uint8_t BOOT_BUTTON_PIN = BOOT_PIN;  // this is GPIO 9 on most ESP32-C6 boards
bool isSingleClick = false, isDoubleClick = false;

// ------------------------------------------------------------------
// SSD1306 is a 0.96-inches 128x64 px OLED display

#include "SSD1306_OLED.h"
bool refreshDisplay = false;
char buf[30];

// ------------------------------------------------------------------
// data/display refresh

const long DATA_REFRESH_MILLIS = 1000;  // 1 second
long lastDataRefreshMillis = 0;
long lastTemperatureUpdateMillis, lastHumidityUpdateMillis, lastBatteryVoltageUpdateMillis, lastBatteryPercentageUpdateMillis;

// settings for reporting
#define MIN_INTERVAL 30    // minimum 60 seconds between reports
#define MAX_INTERVAL 60  // maximum 60 seconds until reporting
#define TEMPERATURE_REPORTABLE_CHANGE 50 // 0.5°C change (Tuya often uses 0.1 degrees)
#define HUMIDITY_REPORTABLE_CHANGE 100 // in 0.01% steps, this is 1% point change

// ------------------------------------------------------------------
// Data logging

#include "DATA_LOGGING.h"
// sensor numbers: 0 = temperature, 1 = humidity, 2 = battery voltage, 3 = battery capacity

typedef enum {
  TEMP_SENS = 0,
  HUMID_SENS = 1,
  BAT_VOLT = 2,
  BAT_CAP = 3,
} SENSOR_NUMBER_t;

// if two updates are received within the intervall only the first one
// is recognized
const long MINIMUM_CALLBACK_UPDATE_INTERVALL_MILLIS = 2000;
long lastCallbackUpdateMillis = 0;

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
  //logSingleSensor(TEMP_SENS, temperature);
  logAndStore(TEMP_SENS, temperature);
  lastTemperatureUpdateMillis = millis();

  // this is the trigger for the setTemperatureReporting
  Serial.printf("*** setTemperatureHumidityReporting interval min %d max %d seconds change Celsius %d Humidity %d ***\n",  MIN_INTERVAL, MAX_INTERVAL, TEMPERATURE_REPORTABLE_CHANGE, HUMIDITY_REPORTABLE_CHANGE);
  zbThermostat.setTemperatureHumidityReporting(src_endpoint, src_address.u.short_addr, MIN_INTERVAL, MAX_INTERVAL, TEMPERATURE_REPORTABLE_CHANGE, HUMIDITY_REPORTABLE_CHANGE); // min 60 seconds, max 1 hour, delta = change 0.5 Deg Celsius, delta_hum 1% change

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
  //logSingleSensor(HUMID_SENS, humidity);
  logAndStore(HUMID_SENS, humidity);
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
  //logSingleSensor(BAT_VOLT, voltage / 10.0);
  if (millis() - lastBatteryVoltageUpdateMillis > MINIMUM_CALLBACK_UPDATE_INTERVALL_MILLIS) {
    logAndStore(BAT_VOLT, voltage / 10.0);  
  } else {
    Serial.println("Skipped database update for battery voltage (too fast updates)");
  }
  lastBatteryVoltageUpdateMillis = millis();
}

void receiveBatteryPercentageWithSource(uint8_t percentage, uint8_t src_endpoint, esp_zb_zcl_addr_t src_address) {
  onboardLedFlashWhite(1, 125);  // flash the LED
  rxCounter++;
  if (src_address.addr_type == ESP_ZB_ZCL_ADDR_TYPE_SHORT) {
    Serial.printf("1 Battery Percentage value: %d Volts from endpoint %d, address 0x%04x\n", percentage, src_endpoint, src_address.u.short_addr);
  } else {
    Serial.printf(
      "2 Battery Percentage value: %d %% from endpoint %d, address %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n", percentage, src_endpoint,
      src_address.u.ieee_addr[7], src_address.u.ieee_addr[6], src_address.u.ieee_addr[5], src_address.u.ieee_addr[4], src_address.u.ieee_addr[3],
      src_address.u.ieee_addr[2], src_address.u.ieee_addr[1], src_address.u.ieee_addr[0]);
  }
  prevBatteryPercentage = batteryPercentage;
  batteryPercentage = percentage / 2;
  refreshDisplay = true;
  //logSingleSensor(BAT_CAP, percentage / 2.0);
  if (millis() - lastBatteryPercentageUpdateMillis > MINIMUM_CALLBACK_UPDATE_INTERVALL_MILLIS) {
    logAndStore(BAT_CAP, percentage / 2.0);
  } else {
    Serial.println("Skipped database update for battery capacity (too fast updates)");
  }
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
    // skipping these methods as they are blocking ones
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

// ------------------------------------------------------------------
// Boot button callbacks

// this function will be called when the button was pressed 1 time in a short timeframe.
void SingleClick() {
  Serial.println("x1");
  isSingleClick = true;
}  // SingleClick

// this function will be called when the button was pressed 2 times in a short timeframe.
void DoubleClick() {
  Serial.println("x2");
  isDoubleClick = true;
}  // DoubleClick

// this function will be called when the button is held down.
void DuringLongPress(void *oneButton) {
  Serial.print(((OneButton *)oneButton)->getPressedMs());
  Serial.println("\t - DuringLongPress()");

  unsigned long pressDuration = ((OneButton *)oneButton)->getPressedMs();
  if (pressDuration > BOOT_BUTTON_FACTORY_RESET_MILLIS) {
    Serial.println("Resetting Zigbee to factory and rebooting in 1s.");
    onboardLedFlashGreen(10, 125);
    clearAllFiles();
    delay(1000);
    Zigbee.factoryReset(true);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println(PROGRAM_VERSION);

  // Init the boot button switch
  bootButton.setup(BOOT_BUTTON_PIN, INPUT_PULLUP, true);
  bootButton.attachClick(SingleClick);
  bootButton.attachDoubleClick(DoubleClick);
  bootButton.attachDuringLongPress(DuringLongPress, &bootButton);

  // init the onboard RGB LED
  setupOnboardLeds();
  onboardLedFlashRed(1, 125);  // flash the LED in RED

#ifdef STORE_IN_SPIFFS
  setupSPIFFS();
#endif  

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

  runFullTest();  // test the data logging
  clearAllSensors();

  // printDeviceNames(); // print is blocking the thread until receive the data or timeout
  oDisplayClearData();
  oDisplayData13();
  refreshDisplay = true;
}

void loop() {

  // keep watching the push button:
  bootButton.tick();

  if (isSingleClick) {
    long millisNow = millis();
    isSingleClick = false;
    Serial.println("4. Complette history Sensor TEMP_SENS (0) (newest first):");
    for (int i = 0; i < counts[TEMP_SENS]; i++) {
      HistoryResult data = getHistoricalData(TEMP_SENS, i);
      Serial.printf("   Pos %02d: %.2f | Time: %lu s\n", i, data.value, (millisNow - data.timestamp) / 1000);
    }
    Serial.println("4. Complette history Sensor HUMID_SENS (1) (newest first):");
    for (int i = 0; i < counts[HUMID_SENS]; i++) {
      HistoryResult data = getHistoricalData(HUMID_SENS, i);
      Serial.printf("   Pos %02d: %.2f | Time: %lu m\n", i, data.value,  (millisNow - data.timestamp) / 1000);
    }
    Serial.println("4. Complette history Sensor BAT_VOLT (2) (newest first):");
    for (int i = 0; i < counts[BAT_VOLT]; i++) {
      HistoryResult data = getHistoricalData(BAT_VOLT, i);
      Serial.printf("   Pos %02d: %.2f | Time: %lu s\n", i, data.value,  (millisNow - data.timestamp) / 1000);
    }
    Serial.println("4. Complette history Sensor BAT_CAP (3) (newest first):");
    for (int i = 0; i < counts[BAT_CAP]; i++) {
      HistoryResult data = getHistoricalData(BAT_CAP, i);
      Serial.printf("   Pos %02d: %.2f | Time: %lu s\n", i, data.value,  (millisNow - data.timestamp) / 1000);
    }

    oDisplay.clear();
    oDisplay.display();
    oDisplay.setTextAlignment(TEXT_ALIGN_LEFT);
    oDisplay.setFont(Monospaced_plain_9);
    // temperature
    uint8_t nbrTempData = counts[TEMP_SENS];
    for (uint8_t i = 0; i < nbrTempData; i++) {
      HistoryResult data = getHistoricalData(TEMP_SENS, i);
      sprintf(buf, "T%02d %.2f %lu s", i, data.value,  (millisNow - data.timestamp) / 10000);
      oDisplay.println(buf);
      delay(100);
    }
    delay(2000);
    uint8_t nbrHumidData = counts[HUMID_SENS];
    for (uint8_t i = 0; i < nbrHumidData; i++) {
      HistoryResult data = getHistoricalData(HUMID_SENS, i);
      sprintf(buf, "H%02d %.2f %lu s", i, data.value,  (millisNow - data.timestamp) / 1000);
      oDisplay.println(buf);
      delay(100);
    }
    delay(2000);
    uint8_t nbrBatVoltData = counts[BAT_VOLT];
    for (uint8_t i = 0; i < nbrBatVoltData; i++) {
      HistoryResult data = getHistoricalData(BAT_VOLT, i);
      sprintf(buf, "V%02d %.2f %lu s", i, data.value,  (millisNow - data.timestamp) / 1000);
      oDisplay.println(buf);
      delay(100);
    }
    delay(2000);
    uint8_t nbrBatCapData = counts[BAT_CAP];
    for (uint8_t i = 0; i < nbrBatCapData; i++) {
      HistoryResult data = getHistoricalData(BAT_CAP, i);
      sprintf(buf, "C%02d %.2f %lu s", i, data.value,  (millisNow - data.timestamp) / 1000);
      oDisplay.println(buf);
      delay(100);
    }
    delay(2000);
    printStorageInfo();
  }

  if (isDoubleClick) {
    // print out the difference data
    isDoubleClick = false;
    oDisplay.clear();
    oDisplay.display();
    oDisplay.setTextAlignment(TEXT_ALIGN_LEFT);
    oDisplay.setFont(Monospaced_plain_9);
    // temperature
    uint8_t nbrTempData = counts[TEMP_SENS];
    for (uint8_t i = 0; i < nbrTempData; i++) {
      HistoryDiff data = getHistoricalDataDifference(TEMP_SENS, i);
      sprintf(buf, "T%02d %.2f %lu s", i, data.valueDiff, (data.timeDiff / 1000));
      oDisplay.println(buf);
      delay(100);
    }
    delay(3000);
    uint8_t nbrHumidData = counts[HUMID_SENS];
    for (uint8_t i = 0; i < nbrHumidData; i++) {
      HistoryDiff data = getHistoricalDataDifference(HUMID_SENS, i);
      sprintf(buf, "H%02d %.2f %lu s", i, data.valueDiff, (data.timeDiff / 1000));
      oDisplay.println(buf);
      delay(100);
    }
    delay(3000);
    uint8_t nbrBatVoltData = counts[BAT_VOLT];
    for (uint8_t i = 0; i < nbrBatVoltData; i++) {
      HistoryDiff data = getHistoricalDataDifference(BAT_VOLT, i);
      sprintf(buf, "V%02d %.2f %lu s", i, data.valueDiff, (data.timeDiff / 1000));
      oDisplay.println(buf);
      delay(100);
    }
    delay(3000);
    uint8_t nbrBatCapData = counts[BAT_CAP];
    for (uint8_t i = 0; i < nbrBatCapData; i++) {
      HistoryDiff data = getHistoricalDataDifference(BAT_CAP, i);
      sprintf(buf, "C%02d %.2f %lu s", i, data.valueDiff, (data.timeDiff / 1000));
      oDisplay.println(buf);
      delay(100);
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
    //Serial.println("refreshDisplay triggered");
    sprintf(buf, "Temp:  %2.2f C", sensorTemp);
    //Serial.println(buf);
    oDisplay1 = buf;
    sprintf(buf, "Humid: %2.2f %%rH", sensorHumid);
    oDisplay2 = buf;
    sprintf(buf, "Bat V: %2.2f volts", batteryVoltage);
    oDisplay3 = buf;
    sprintf(buf, "Bat C: %2d %%", batteryPercentage);
    oDisplay4 = buf;

    // 0 is the last recent value
    HistoryResult lastTemperatureUpdate = getHistoricalData(TEMP_SENS, 0);
    uint32_t secondsSinceLastTempUpdate = (millis() -  lastTemperatureUpdate.timestamp) / 1000;
    HistoryResult lastBatVoltUpdate = getHistoricalData(BAT_VOLT, 0);
    uint32_t secondsSinceLastBatVoltUpdate = (millis() -  lastBatVoltUpdate.timestamp) / 1000;
/*
    // low voltage detection
    if (batteryVoltage < 2.4) {
      sprintf(budc, "LOW BAT");
    } else {
      sprintf(budc, "       ");
    }
*/    
    sprintf(buf, "C:%d %d|%ds", rxCounter, secondsSinceLastTempUpdate, secondsSinceLastBatVoltUpdate);
    oDisplay5 = buf;
    oDisplayData13();
    refreshDisplay = false;
  }

}
