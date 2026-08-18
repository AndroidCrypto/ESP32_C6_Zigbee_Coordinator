// Copyright 2024 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @brief This example demonstrates simple Zigbee light bulb.
 *
 * The example demonstrates how to use Zigbee library to create a end device light bulb.
 * The light bulb is a Zigbee end device, which is controlled by a Zigbee coordinator.
 *
 * Proper Zigbee mode must be selected in Tools->Zigbee mode
 * and also the correct partition scheme must be selected in Tools->Partition Scheme.
 *
 * Please check the README.md for instructions and more detailed description.
 *
 * Created by Jan Procházka (https://github.com/P-R-O-C-H-Y/)
 */

/*
  Version management
18.08.2026 V05 Code cleaning
02.04.2026 V01 Initial programming, using the original Zigbee_On-Off_Light example and
               added an OLED, using the Onboard RGB LED and uses the advanced Zigbee 
               Debug settings
*/

/*
Settings:

ESP32-C6 Dev Board (4 MB e.g. Super Mini Flash)
CDC on Boot ENabled
Core Debug Level Debug [second level]
Erase all flash enabled): don't forget to enable during testing, or pairing with a new project will fail
Flash size: 4 MB
Partition scheme: Zigbee 4 MB with SPIFFS
Zigbee Mode ED (end device) with Debug
*/

/*
  RGB LED flashing code
  in setup() phase:
  one flash RED:   program started, init for onboard LEDs and display is done
  one flash GREEN: Zigbee coordinator is started
  ten flashed RED: start of Zigbee coordinator failed
  one flash WHITE: device connected, waiting for actions

  in loop() phase:
  one flash GREEN: the BOOT button was pressed for toggling on/off and color
  one flash WHITE: received an setLight (change) callback
*/

char *PROGRAM_VERSION = "ESP32 C6 Zigbee Light End Device Time Cluster with OLED V05";

char *PROGRAM_VERSION_SHORT = "Z Light TimeClustr V05";

//#define SUPPRESS_DISPLAY_OUTPUT true // if enabled, not output on display is done (good for Serial Monitor analyzis)

#include <Arduino.h>

// ------------------------------------------------------------------
// OLED display
#include "SSD1306_OLED.h"
char buf[60];
// ------------------------------------------------------------------
// Onboard RGB LED
#include "ONBOARD_LEDS.h"
uint8_t nextLedColor = 0;  // toggles between red, green and blue

// ------------------------------------------------------------------
// Zigbee

#ifndef ZIGBEE_MODE_ED
#error "Zigbee end device mode is not selected in Tools->Zigbee mode"
#endif

#include "Zigbee.h"

/* Zigbee light bulb configuration */
#define ZIGBEE_LIGHT_ENDPOINT 10

uint8_t button = BOOT_PIN;

ZigbeeLight zbLight = ZigbeeLight(ZIGBEE_LIGHT_ENDPOINT);

// ------------------------------------------------------------------
// Time Cluster

time_t receivedTime = 0;
struct tm timeinfo;   // has the local time
int32_t localOffset;  // is the difference in seconds between local time and UTC

const unsigned long DISPLAY_UPDATE_INTERVAL = 1000;
unsigned long lastDisplayUpdate = 0;
const unsigned long ZIGBEE_TIME_CLUSTER_UPDATE_INTERVAL = 60000;  // one minute
unsigned long lastZigbeeTimeClusterUpdate = 0;
//unsigned long lastDisp = 0;

void getTimeData() {
  // If time cluster is added, time can be read from the coordinator
  Serial.println("-----------------------");
  Serial.println("###################################");
  struct tm timeinfoTc = zbLight.getTime();
  int32_t timezoneOffset = zbLight.getTimezone();
  Serial.printf("TimeCluster time %d zone %d\n", timeinfoTc, timezoneOffset);
  Serial.println("###################################");

  // convert tm-structure in Unix-time (Epoch)
  time_t t = mktime(&timeinfoTc);
  if (t > 0) {
    struct timeval tv;
    tv.tv_sec = t;
    tv.tv_usec = 0;
    // set system time (stored in internal RTC memory)
    settimeofday(&tv, NULL);
    // optional: set timezone globaly for methods like localtime()
    char tzConfig[32];
    sprintf(tzConfig, "GMT%s%ld", (timezoneOffset >= 0) ? "-" : "+", abs(timezoneOffset / 3600));
    setenv("TZ", tzConfig, 1);
    tzset();
    Serial.println("System-RTC was synchronized with Zigbee-Time Cluster.");
    localOffset = timezoneOffset;
  }
  printCurrentTime();
  Serial.println("-----------------------");
}

void printCurrentTime() {
  time_t now;
  struct tm timeinfo;
  char buffer[64];
  time(&now);  // get current system time
  // --- 1. LOCAL TIME ---
  localtime_r(&now, &timeinfo);
  strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", &timeinfo);
  Serial.printf("Local time:  %s\n", buffer);
  // --- 2. UTC TIME ---
  gmtime_r(&now, &timeinfo);
  strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", &timeinfo);
  Serial.printf("UTC time:    %s\n", buffer);
  snprintf(buffer, sizeof(buffer), "%d", localOffset);
  Serial.printf("Offset:      %s seconds\n", buffer);
}

void displayTimeInformation() {
  oDisplayClearData();
  // esp32 rtc time
  struct tm timeinfoEsp;
  bool timeValidEsp = getLocalTime(&timeinfoEsp);
  time_t nowEsp;
  time(&nowEsp);
  struct tm *utc_tm_esp = gmtime(&nowEsp);
  sprintf(buf, "CET: %02d.%02d.%04d", timeinfoEsp.tm_mday, timeinfoEsp.tm_mon + 1, timeinfoEsp.tm_year + 1900);
  oDisplay1 = buf;
  sprintf(buf, "     %02d:%02d:%02d", timeinfoEsp.tm_hour, timeinfoEsp.tm_min, timeinfoEsp.tm_sec);
  oDisplay2 = buf;
  sprintf(buf, "UTC: %02d.%02d.%04d", utc_tm_esp->tm_mday, utc_tm_esp->tm_mon + 1, utc_tm_esp->tm_year + 1900);
  oDisplay3 = buf;
  sprintf(buf, "     %02d:%02d:%02d", utc_tm_esp->tm_hour, utc_tm_esp->tm_min, utc_tm_esp->tm_sec);
  oDisplay4 = buf;
  sprintf(buf, "Offs:%d %ds", localOffset, (millis() - lastZigbeeTimeClusterUpdate) / 1000);
  oDisplay5 = buf;
  oDisplayData13();
}

/********************* RGB LED functions **************************/
// changed for toggling between red, green and blue when on
void setLED(bool value) {
  onboardLedFlashWhite(1, 125);  // flash the LED
  oDisplayClearData();
  oDisplay1 = " Switch is";
  if (value) {
    oDisplay2 = "    ON";
    oDisplay3 = " Color is";
    // toggling the color
    if (nextLedColor == 0) {
      setRgbLedRed(10);
      oDisplay4 = "    RED";
      Serial.println("Received a setLED callback with value TRUE == ON, color is RED");
    } else if (nextLedColor == 1) {
      setRgbLedGreen(10);
      oDisplay4 = "   GREEN";
      Serial.println("Received a setLED callback with value TRUE == ON, color is GREEN");
    } else {
      setRgbLedBlue(10);
      oDisplay4 = "   BLUE";
      Serial.println("Received a setLED callback with value TRUE == ON, color is BLUE");
    }
    nextLedColor++;
    if (nextLedColor > 2) nextLedColor = 0;
  } else {
    oDisplay2 = "    OFF";
    oDisplay3 = "     No";
    oDisplay4 = "   Color";
    setRgbLedOff();
    Serial.println("Received a setLED callback with value FALSE == OFF, no color is shown");
  }
  oDisplayData18();
  lastDisplayUpdate = millis() + 2000;  // two additional seconds for displaying
}

/********************* Arduino functions **************************/
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println(PROGRAM_VERSION);

  setupOnboardLeds();
  setupSsd1306();
  onboardLedFlashRed(1, 125);  // flash the LED

  oDisplay1 = PROGRAM_VERSION_SHORT;
  oDisplayData();

  // advanced debug mode, added by AndroidCrypto
  Zigbee.setDebugMode(true);

  // Init button for factory reset
  pinMode(button, INPUT_PULLUP);

  // Optional: set Zigbee device name and model
  zbLight.setManufacturerAndModel("AndroidCrypto", "ZB_ED_TimeCluster");

  // Set callback function for light change
  zbLight.onLightChange(setLED);

  // Optional: Time cluster configuration (default params, as this device will recieve time from coordinator)
  zbLight.addTimeCluster();

  //Add endpoint to Zigbee Core
  Serial.println("Adding ZigbeeLight endpoint to Zigbee Core");
  Zigbee.addEndpoint(&zbLight);

  // When all EPs are registered, start Zigbee. By default acts as ZIGBEE_END_DEVICE
  if (!Zigbee.begin()) {
    Serial.println("Zigbee failed to start!");
    Serial.println("Rebooting...");
    onboardLedFlashRed(10, 125);  // flash the LED
    oDisplay3 = "Zigbee Error";
    oDisplay4 = "Restarting !";
    oDisplayData();
    delay(2000);
    ESP.restart();
  }
  onboardLedFlashGreen(1, 125);  // flash the LED
  oDisplay3 = "   Zigbee started";
  oDisplayData();

  Serial.println("Connecting to network");
  while (!Zigbee.connected()) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();
  Serial.println("Connected to Coordinator: wait for actions");
  onboardLedFlashWhite(1, 125);  // flash the LED
  oDisplay3 = "    Connected to ";
  oDisplay4 = "    Coordinator";
  oDisplay5 = "  wait for actions";
  oDisplayData();
}

void loop() {
  // Checking button for factory reset
  if (digitalRead(button) == LOW) {  // Push button pressed
    // Key debounce handling
    delay(100);
    int startTime = millis();
    while (digitalRead(button) == LOW) {
      delay(50);
      if ((millis() - startTime) > 3000) {
        // If key pressed for more than 3 secs, factory reset Zigbee and reboot
        Serial.println("Resetting Zigbee to factory and rebooting in 1s.");
        delay(1000);
        Zigbee.factoryReset();
      }
    }
    // Toggle light by pressing the button
    onboardLedFlashGreen(1, 125);  // flash the LED
    zbLight.setLight(!zbLight.getLightState());
  }

  if (millis() - lastZigbeeTimeClusterUpdate > ZIGBEE_TIME_CLUSTER_UPDATE_INTERVAL) {
    onboardLedFlashWhite(2, 125);  // flash the LED
    getTimeData();
    //printCurrentTime(); // is done in getTimeData()
    lastZigbeeTimeClusterUpdate = millis();
  }

  // display update
  if (millis() - lastDisplayUpdate >= DISPLAY_UPDATE_INTERVAL) {
    lastDisplayUpdate = millis();
    displayTimeInformation();
  }
}
