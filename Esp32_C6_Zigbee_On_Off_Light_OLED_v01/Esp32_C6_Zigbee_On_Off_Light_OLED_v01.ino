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
02.04.2026 V01 Initial programming, using the original Zigbee_On-Off_Light example and
               added an OLED, using the Onboard RGB LED and uses the advanced Zigbee 
               Debug settings
*/

/*
Settings:
ESP32-C6 Dev Board (8 MB / 16 MB Flash)
CDC on Boot enabled
Core Debug Level verbose [highest level]
Erase all flash enabled): don't forget to enable during testing, or pairing with a new project will fail
Flash size: 8 MB
Partition scheme: Zigbee 8 MB with SPIFFS
Zigbee Mode ED (end device) with Debug

ESP32-C6 Dev Board (4 MB e.g. Super Mini Flash)
CDC on Boot enabled
Core Debug Level verbose [highest level]
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

char *PROGRAM_VERSION = "ESP32 C6 Zigbee On Off Light example with OLED V01";
char *PROGRAM_VERSION_SHORT = "Zigbee On Off Light V01";

//#define SUPPRESS_DISPLAY_OUTPUT true // if enabled, not output on display is done (good for Serial Monitor analyzis)

// ------------------------------------------------------------------
// Zigbee

#include <Arduino.h>
#ifndef ZIGBEE_MODE_ED
#error "Zigbee end device mode is not selected in Tools->Zigbee mode"
#endif

#include "Zigbee.h"

/* Zigbee light bulb configuration */
#define ZIGBEE_LIGHT_ENDPOINT 10
//uint8_t led = RGB_BUILTIN;
uint8_t button = BOOT_PIN;

ZigbeeLight zbLight = ZigbeeLight(ZIGBEE_LIGHT_ENDPOINT);

// ------------------------------------------------------------------
// OLED display
#include "SSD1306_OLED.h"

// ------------------------------------------------------------------
// Onboard RGB LED
#include "ONBOARD_LEDS.h"
uint8_t nextLedColor = 0; // toggles between red, green and blue

/********************* RGB LED functions **************************/
// changed for toggling between red, green and blue when on
void setLED(bool value) {
  onboardLedFlashWhite(1, 125); // flash the LED
  //digitalWrite(led, value);
  oDisplayClearData();
  oDisplay1 = " Switch is";
  if (value) {
    oDisplay2 = "    ON";
    oDisplay3 = " Color is";
    // toggling the color
    if (nextLedColor == 0)  {
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
}


/********************* Arduino functions **************************/
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println(PROGRAM_VERSION);

  setupOnboardLeds();
  setupSsd1306();
  onboardLedFlashRed(1, 125); // flash the LED

  oDisplay1 = PROGRAM_VERSION_SHORT;
  oDisplayData();

  // advanced debug mode, added by AndroidCrypto
  Zigbee.setDebugMode(true);

  // Init LED and turn it OFF (if LED_PIN == RGB_BUILTIN, the rgbLedWrite() will be used under the hood)
  /*
  // dactivated, as it is using the RGB LED with 3 colors
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  */

  // Init button for factory reset
  pinMode(button, INPUT_PULLUP);

  //Optional: set Zigbee device name and model
  zbLight.setManufacturerAndModel("AndroidCrypto", "ZBLightBulb");

  // Set callback function for light change
  zbLight.onLightChange(setLED);

  //Add endpoint to Zigbee Core
  Serial.println("Adding ZigbeeLight endpoint to Zigbee Core");
  Zigbee.addEndpoint(&zbLight);

  // When all EPs are registered, start Zigbee. By default acts as ZIGBEE_END_DEVICE
  if (!Zigbee.begin()) {
    Serial.println("Zigbee failed to start!");
    Serial.println("Rebooting...");
    onboardLedFlashRed(10, 125); // flash the LED
    oDisplay3 = "Zigbee Error";
    oDisplay4 = "Restarting !";
    oDisplayData();
    delay(2000);
    ESP.restart();
  }
  onboardLedFlashGreen(1, 125); // flash the LED
  oDisplay3 = "   Zigbee started";
  oDisplayData();

  Serial.println("Connecting to network");
  while (!Zigbee.connected()) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();
  onboardLedFlashWhite(1, 125); // flash the LED
  oDisplay3 = "    Connected to";
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
        // If key pressed for more than 3secs, factory reset Zigbee and reboot
        Serial.println("Resetting Zigbee to factory and rebooting in 1s.");
        delay(1000);
        Zigbee.factoryReset();
      }
    }
    // Toggle light by pressing the button
    onboardLedFlashGreen(1, 125); // flash the LED
    zbLight.setLight(!zbLight.getLightState());
  }
  delay(100);
}
