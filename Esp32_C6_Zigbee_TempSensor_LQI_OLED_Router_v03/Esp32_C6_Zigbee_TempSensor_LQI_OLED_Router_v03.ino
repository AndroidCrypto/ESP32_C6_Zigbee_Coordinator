// Copyright 2024 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @brief This example demonstrates Zigbee temperature sensor.
 *
 * The example demonstrates how to use Zigbee library to create a end device temperature sensor.
 * The temperature sensor is a Zigbee end device, which is controlled by a Zigbee coordinator.
 *
 * Proper Zigbee mode must be selected in Tools->Zigbee mode
 * and also the correct partition scheme must be selected in Tools->Partition Scheme.
 *
 * Please check the README.md for instructions and more detailed description.
 *
 * Created by Jan Procházka (https://github.com/P-R-O-C-H-Y/)
 */

/*
  Version Management
25.04.2026 V03 Added displaying the number of connected devices to the router  
24.04.2026 V02 Router variant: this is the upgraded version with a Router functionality
               need to open the network for new devices  
22.04.2026 V02 Changed the button press to an interrupt control, displaying
               the Link Quality Index (LQI) and signal strength (RSSI)
17.04.2026 V01 Initial programming, based on the original Zigbee Temperature Sensor example
*/

#ifndef ZIGBEE_MODE_ZCZR
#error "Zigbee coordinator mode is not selected in Tools->Zigbee mode"
#endif

char *PROGRAM_VERSION = "ESP32 C6 Zigbee Temperature Sensor LQI with OLED and Router V03";
char *PROGRAM_VERSION_SHORT = "Zigb.Temp LQI Router V03";

// Zigbee temperature sensor configuration
#define TEMP_SENSOR_ENDPOINT_NUMBER 14
char *MANUFACTURER_NAME = "AndCrypt4";
char *MODEL_NAME = "Temp4";
#define HAS_OLED_DISPLAY

#include <Arduino.h>
#include "Zigbee.h"

// Optional Time cluster variables
struct tm timeinfo;
struct tm *localTime;
int32_t timezone;

ZigbeeTempSensor zbTempSensor = ZigbeeTempSensor(TEMP_SENSOR_ENDPOINT_NUMBER);

// ------------------------------------------------------------------
// Signal quality
// LQI Link Quality Index
uint8_t lqiToCoordinator = 0;
int8_t rssiToCoordinator = 0;

// ------------------------------------------------------------------
// OLED display
#include "SSD1306_OLED.h"

// ------------------------------------------------------------------
// Onboard RGB LED
#include "ONBOARD_LEDS.h"

// ------------------------------------------------------------------
// Number of connected devices to the router
uint8_t nbrOfConnectedDevices = 0; // this excludes the connection to the coordinator
uint8_t nbrOfConnectedCoordinators = 0; // should be 0 (no connection) or 1

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

/************************ Temp sensor *****************************/
static void temp_sensor_value_update() {
  // Read temperature sensor value
  float tsens_value = temperatureRead();
  char buf[60];
  Serial.printf("Updated temperature sensor value to %.2f°C\r\n", tsens_value);
  // Update temperature value in Temperature sensor EP
  zbTempSensor.setTemperature(tsens_value);
  setGreenLedFlash = true;
  sprintf(buf, "LQI:%d RSSI:%d dBm", lqiToCoordinator, rssiToCoordinator);
  oDisplay4 = buf;
  sprintf(buf, "Temp:%5.2fC|Co:%d | Dev:%d", tsens_value, nbrOfConnectedCoordinators, nbrOfConnectedDevices);
  oDisplay5 = buf;
  //oDisplay5 = "Temp:" + String(tsens_value) + "C|Co:" + String(nbrOfConnectedCoordinators) + "|Dev:" + String(nbrOfConnectedDevices);
#ifdef HAS_OLED_DISPLAY
  oDisplayData();
#endif  
}

// retrieves the LQI (Link Quality Indicator) and RSSI (Signal strength)
// and counts the number of connected devices (ex coordinator) and
// coordinators
uint8_t getLqi() {
  esp_zb_nwk_info_iterator_t iterator = 0;
  esp_zb_nwk_neighbor_info_t nbr_info;

  // reset the data
  nbrOfConnectedDevices = 0; // this excludes the connection to the coordinator
  nbrOfConnectedCoordinators = 0; // should be 0 (no connection) or 1

  Serial.println("--- Signal-Statistic ---");

  while (esp_zb_nwk_get_next_neighbor(&iterator, &nbr_info) == ESP_OK) {
    Serial.print("Device: 0x");
    Serial.print(nbr_info.short_addr, HEX);

    // LQI (0 ... 255)
    Serial.print(" | LQI: ");
    Serial.print(nbr_info.lqi);

    // RSSI (value in dBm, typical negative, e.g., -65)
    Serial.print(" | RSSI: ");
    Serial.print(nbr_info.rssi);
    Serial.println(" dBm");
    nbrOfConnectedDevices++;

    if (nbr_info.short_addr == 0x0000) {
      Serial.println("  [Connection to Coordinator]");
      lqiToCoordinator = nbr_info.lqi;
      rssiToCoordinator = nbr_info.rssi;
      nbrOfConnectedDevices--;
      nbrOfConnectedCoordinators++;
    }
  }
  Serial.println("-----------------------");
  return lqiToCoordinator;
}

/********************* Periodic task ***************************/
void periodicTask(void *arg) {
  while (true) {

    // get new temperature data and send every 5 seconds
    static uint32_t lastTransmit = 0;
    if (millis() - lastTransmit > 5000) {
      getLqi();
      temp_sensor_value_update();
      setRedLedFlash = true;
      lastTransmit = millis();
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

/********************* Arduino functions **************************/
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println(PROGRAM_VERSION);

  Serial.println("This is an Endpoint that has Router capabilities");


  // Init the boot button switch with internal pull-up resistor
  pinMode(bootButton, INPUT_PULLUP);
  // interrupt on falling edge on button press
  attachInterrupt(digitalPinToInterrupt(bootButton), handleButtonPress, CHANGE);

  setupOnboardLeds();
  onboardLedFlashRed(1, 125); // flash the LED
  
#ifdef HAS_OLED_DISPLAY
  setupSsd1306();
  oDisplay1 = PROGRAM_VERSION_SHORT;
  oDisplayData();
#endif

  // advanced debug mode, added by AndroidCrypto
  Zigbee.setDebugMode(true);

  // Optional: set Zigbee device name and model, in case someone is asking...
  zbTempSensor.setManufacturerAndModel(MANUFACTURER_NAME, MODEL_NAME);

  // Set minimum and maximum temperature measurement value (10-50°C is default range for chip temperature measurement)
  // if set to 50 a setTemperature of (51) will fail
  zbTempSensor.setMinMaxValue(10, 80);

  // Optional: Set default (initial) value for the temperature sensor to 10.0°C to match the minimum temperature measurement value
  zbTempSensor.setDefaultValue(10.0);

  // Optional: Set tolerance for temperature measurement in °C (lowest possible value is 0.01°C)
  zbTempSensor.setTolerance(0.1);

  // Optional: Time cluster configuration (default params, as this device will revieve time from coordinator)
  zbTempSensor.addTimeCluster();

  // Add endpoint to Zigbee Core
  Zigbee.addEndpoint(&zbTempSensor);

  Serial.println("Starting Zigbee...");
  oDisplay2 = "start Zigbee as";
#ifdef HAS_OLED_DISPLAY  
  oDisplayData();
#endif  

  // Optional: Create a custom Zigbee configuration for Zigbee Extender
  esp_zb_cfg_t zigbeeConfig = ZIGBEE_DEFAULT_ROUTER_CONFIG();
  zigbeeConfig.nwk_cfg.zczr_cfg.max_children = 5;  // 10 is default

  // When all EPs are registered, start Zigbee in End Device mode
  if (!Zigbee.begin(ZIGBEE_ROUTER)) {
    Serial.println("Zigbee failed to start!");
    Serial.println("Rebooting...");
    ESP.restart();
  } else {
    Serial.println("Zigbee started successfully!");
  }

  Zigbee.openNetwork(180);
  Serial.println("The network is open for 180 seconds");

  oDisplay3 = "END DEVICE | ROUTER";

#ifdef HAS_OLED_DISPLAY   
  oDisplayData();
#endif  
  Serial.println("Connecting to network");
  while (!Zigbee.connected()) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();
  oDisplay4 = "Connected";
#ifdef HAS_OLED_DISPLAY  
  oDisplayData();
#endif  

  // Optional: If time cluster is added, time can be read from the coordinator
  timeinfo = zbTempSensor.getTime();
  timezone = zbTempSensor.getTimezone();

  Serial.println("UTC time:");
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");

  time_t local = mktime(&timeinfo) + timezone;
  localTime = localtime(&local);

  Serial.println("Local time with timezone:");
  Serial.println(localTime, "%A, %B %d %Y %H:%M:%S");

  // Start Temperature sensor reading task
  //xTaskCreate(temp_sensor_value_update, "temp_sensor_update", 2048, NULL, 10, NULL);
  xTaskCreate(periodicTask, "periodicTask", 1024 * 4, NULL, 10, NULL);

  // Set reporting interval for temperature measurement in seconds, must be called after Zigbee.begin()
  // min_interval and max_interval in seconds, delta (temp change in 0,1 °C)
  // if min = 1 and max = 0, reporting is sent only when temperature changes by delta
  // if min = 0 and max = 10, reporting is sent every 10 seconds or temperature changes by delta
  // if min = 0, max = 10 and delta = 0, reporting is sent every 10 seconds regardless of temperature change
  //zbTempSensor.setReporting(1, 0, 1);
  zbTempSensor.setReporting(1, 30, 0.5);
}

void loop() {

  rgbLedFlashLoop(); // delayless RGB LED flashing

  // handle button press for factory reset and reporting
  unsigned long now = millis();
  if (buttonDown && (now - lastPressTime > LONG_PRESS_DURATION)) {
    Serial.println("Ergebnis: LONG PRESS");
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
      Serial.println("SINGLE CLICK: zbTempSensor.reportTemperature()");
      zbTempSensor.reportTemperature();
      setMintLedFlash = true;

    } else if (clickCount >= 2) {
      Serial.println("DOUBLE CLICK");
      Zigbee.openNetwork(180);
      Serial.println("The network is open for 180 seconds");
      setYellowLedFlash = true;
    }
    clickCount = 0;
  }

  //delay(100);
}
