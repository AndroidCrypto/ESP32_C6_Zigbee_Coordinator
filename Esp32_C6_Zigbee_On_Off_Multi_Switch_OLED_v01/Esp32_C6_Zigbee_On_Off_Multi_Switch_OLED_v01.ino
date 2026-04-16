/*
  The sketch is a modifcation of the original Espressif Arduino
  'Zigbee_On_Off_Switch' example but modified to our needs.

  For using the sketch in the development phase, I recommend to
  use two light devices based on the Espressif Arduino
  'Zigbee_On_Off_Light' example. In my GitHub repository you
  find the slightly modified code for the second device 
  ('Esp32_C6_Zigbee_On_Off_Light_v01b'), there I changed the
  endpoint from "10" to "9", the manufacturer name to
  "AndroidCrypto" and the model name to "ZBLight 2", this is
  to identify both (different) devices on the screen.
  The second advantage of using the ESP32-C6 based device is 
  that you can track the incoming and outgoing data in parallel 
  with the coordinator (which is not possible with a commercial 
  light or switch).

  Please use the settings below to see the data in the Serial Monitor.

  I removed the complete code for button control and you need to
  use the Serial Monitor interface to control the devices. Be sure
  that you use '115200 baud' speed and 'No Line Ending' option.
  For a short explanation of the commands, see the Help.md tab.

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
 * @brief This example demonstrates simple Zigbee light switch.
 *
 * The example demonstrates how to use Zigbee library to control a light bulb.
 * The light bulb is a Zigbee end device, which is controlled by a Zigbee coordinator (Switch).
 * Button switch and Zigbee runs in separate tasks.
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

16.04.2026 V01 Initial programming, based on the ESP32_C6_On_Off_Switch_OLED_v01' sketch.
               I added an OLED, using the Onboard RGB LED and uses the advanced Zigbee 
               Debug settings. The light state polling is still the 1 second interval.
*/

/*
  RGB LED flashing code
  in setup() phase:
  one flash RED: program started, init for onboard LEDs and display is done
  one flash GREEN: Zigbee coordinator is started
  ten flashed RED: start of Zigbee coordinator failed
  one flash BLUE: minimum one device bounded
  one flash WHITE: waiting for actions

  in loop() phase:
  one flash BLUE: the BOOT button was pressed for toggling on/off and color
  one flash GREEN: received an onLightChange callback
*/

char *PROGRAM_VERSION = "ESP32 C6 Zigbee On Off Multi Switch with OLED V01";
char *PROGRAM_VERSION_SHORT = "Zigbee On Off Switch V01";

//#define SUPPRESS_DISPLAY_OUTPUT true // if enabled, not output on display is done (good for Serial Monitor analyzis)

// ------------------------------------------------------------------
// Zigbee

#include <Arduino.h>
#ifndef ZIGBEE_MODE_ZCZR
#error "Zigbee coordinator mode is not selected in Tools->Zigbee mode"
#endif

#include "Zigbee.h"

/* Zigbee switch configuration */
#define SWITCH_ENDPOINT_NUMBER 5

// variables for multi devices
uint8_t nbrOfDevices = 0;
uint8_t endpoint1 = 0, endpoint2 = 0;
uint16_t shortAddress1, shortAddress2;
uint8_t ieeeAddress1[8], ieeeAddress2[8];
bool switchState1, switchState2;
bool receivedManufacturer1 = false, receivedManufacturer2 = false;
bool receivedModel1 = false, receivedModel2 = false;
char manufacturerChar1[13], manufacturerChar2[13];
char modelChar1[13], modelChar2[13];
char stateChar1[5], stateChar2[5];

ZigbeeSwitch zbSwitch = ZigbeeSwitch(SWITCH_ENDPOINT_NUMBER);

// ------------------------------------------------------------------
// OLED display
#include "SSD1306_OLED.h"

// ------------------------------------------------------------------
// Onboard RGB LED
#include "ONBOARD_LEDS.h"

/********************* Zigbee functions **************************/

/*
static void onLightStateChange(bool state) {
  if (state != light_state) {
    light_state = state;
    Serial.printf("Light state changed to %d\r\n", state);
    onboardLedFlashGreen(1, 125);  // flash the LED
    oDisplay1 = "";
    oDisplay2 = "";
    oDisplay3 = " The LED is";
    if (state) {
      oDisplay4 = "    ON";
    } else {
      oDisplay4 = "    OFF";
    }
    oDisplayData18();
  }
}
*/

static void onLightStateChangeWithSource(bool state, uint8_t src_endpoint, esp_zb_zcl_addr_t src_address) {
  if (src_address.addr_type == ESP_ZB_ZCL_ADDR_TYPE_SHORT) {
    if (shortAddress1 == src_address.u.short_addr) {
      onboardLedFlashRed(1, 125);  // flash the LED
      if (state != switchState1) {
        switchState1 = state;
        Serial.printf("1-Switch state dev 1 changed to: %d from endpoint %d, address 0x%04x\n", switchState1, src_endpoint, src_address.u.short_addr);
        if (switchState1) {
          snprintf(stateChar1, sizeof(stateChar1), "%-4s", "ON");
        } else {
          snprintf(stateChar1, sizeof(stateChar1), "%-4s", "OFF");
        }
        displayConnectedDevices();
      }
    } else if (shortAddress2 == src_address.u.short_addr) {
      onboardLedFlashGreen(1, 125);  // flash the LED
      if (state != switchState2) {
        switchState2 = state;
        Serial.printf("1-Switch state dev 2 changed to: %d from endpoint %d, address 0x%04x\n", switchState2, src_endpoint, src_address.u.short_addr);
        if (switchState2) {
          snprintf(stateChar2, sizeof(stateChar2), "%-4s", "ON");
        } else {
          snprintf(stateChar2, sizeof(stateChar2), "%-4s", "OFF");
        }
      }
      displayConnectedDevices();
    }
    Serial.printf("The state of dev 1: %s dev 2: %s\n", stateChar1, stateChar2);
    // this situation is not covered by the sketch, you need to compare the ieee addresses to find device 1 or 2
  } else {
    Serial.printf(
      "2-Switch state changed to: %d V from endpoint %d, address %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n", state, src_endpoint,
      src_address.u.ieee_addr[7], src_address.u.ieee_addr[6], src_address.u.ieee_addr[5], src_address.u.ieee_addr[4], src_address.u.ieee_addr[3],
      src_address.u.ieee_addr[2], src_address.u.ieee_addr[1], src_address.u.ieee_addr[0]);
  }
}

// returns the endpoint of a bounded device with a specific ieee address
// gives 0 when address was not found
uint8_t getBoundedEndpoint(uint8_t ieeeAddr[8]) {
  // get the list of all bounded devices and iterate through
  std::list<zb_device_params_t *> boundLights = zbSwitch.getBoundDevices();
  for (const auto &device : boundLights) {
    Serial.printf("Device on endpoint %d, short address: 0x%x\r\n", device->endpoint, device->short_addr);
    Serial.printf(
      "IEEE Address: %02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X\r\n", device->ieee_addr[7], device->ieee_addr[6], device->ieee_addr[5], device->ieee_addr[4],
      device->ieee_addr[3], device->ieee_addr[2], device->ieee_addr[1], device->ieee_addr[0]);
    // check for the matching ieee address
    if (memcmp(ieeeAddr, device->ieee_addr, sizeof(ieeeAddr)) == 0) {
      return device->endpoint;
    }
  }
  return 0;  // nothing found
}

// returns the number of connected devices in the neighborhood
// the number of bounded devices can be higher
// returns 0 when no device is connected
uint8_t listConnectedDevices() {
  esp_zb_nwk_info_iterator_t iterator = 0;
  esp_zb_nwk_neighbor_info_t nbr_info;
  uint8_t deviceCount = 0;

  Serial.println("Bounded Zigbee devices (IEEE-addresses):");

  // iterate through the neighborhood table
  while (esp_zb_nwk_get_next_neighbor(&iterator, &nbr_info) == ESP_OK) {
    deviceCount++;

    // IEEE-address is an 8-byte array (little-endian)
    uint8_t *ieee = nbr_info.ieee_addr;
    char bufAddr[30];

    Serial.printf("%d. Short address: 0x%04x | IEEE: %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n",
                  deviceCount,
                  nbr_info.short_addr,
                  ieee[7], ieee[6], ieee[5], ieee[4],
                  ieee[3], ieee[2], ieee[1], ieee[0]);

    if (deviceCount == 1) {
      shortAddress1 = nbr_info.short_addr;
      memcpy(ieeeAddress1, ieee, 8);

      endpoint1 = getBoundedEndpoint(ieee);

      // readManufacturer and readModel methods are blocking the stack, so if we already received
      // data don't ask again !
      if (!receivedManufacturer1) {
        char *manufacturer = zbSwitch.readManufacturer(endpoint1, shortAddress1, ieeeAddress1);
        if (manufacturer != nullptr) {
          strlcpy(manufacturerChar1, manufacturer, sizeof(manufacturerChar1));
          Serial.printf("Light manufacturer1: %s\r\n", manufacturerChar1);
          receivedManufacturer1 = true;
        } else {
          Serial.printf("Light manufacturer1: %s\r\n", "n/a");
        }
      }
      if (!receivedModel1) {
        char *model = zbSwitch.readModel(endpoint1, shortAddress1, ieeeAddress1);
        if (model != nullptr) {
          strlcpy(modelChar1, model, sizeof(modelChar1));
          Serial.printf("Light model1: %s\r\n", modelChar1);
          receivedModel1 = true;
        }
      }
      Serial.printf("Data is for dev nbr 1 endpoint %d shortAddress 0x%04X IEEEAddress %s\n", endpoint1, shortAddress1, Zigbee.formatIEEEAddress(ieeeAddress1));
    } else if (deviceCount == 2) {
      shortAddress2 = nbr_info.short_addr;
      memcpy(ieeeAddress2, ieee, 8);
      endpoint2 = getBoundedEndpoint(ieee);
      if (!receivedManufacturer2) {
        char *manufacturer = zbSwitch.readManufacturer(endpoint2, shortAddress2, ieeeAddress2);

        if (manufacturer != nullptr) {
          strlcpy(manufacturerChar2, manufacturer, sizeof(manufacturerChar2));
          Serial.printf("Light manufacturer2: %s\r\n", manufacturerChar2);
          receivedManufacturer2 = true;
        } else {
          Serial.printf("Light manufacturer2: %s\r\n", "n/a");
        }
      }
      if (!receivedModel2) {
        char *model = zbSwitch.readModel(endpoint2, shortAddress2, ieeeAddress2);
        if (model != nullptr) {
          strlcpy(modelChar2, model, sizeof(modelChar2));
          Serial.printf("Light model1: %s\r\n", modelChar2);
          receivedModel2 = true;
        }
      }
      Serial.printf("Data is for dev nbr 2 endpoint %d shortAddress 0x%04X IEEEAddress %s\n", endpoint2, shortAddress2, Zigbee.formatIEEEAddress(ieeeAddress2));
    }
    // if more devices are connected they are skipped
  }
  return deviceCount;
}

void displayConnectedDevices() {
  oDisplayClearData();
  nbrOfDevices = listConnectedDevices();
  Serial.printf("Found %d connected devices in the neighborhood\n", nbrOfDevices);
  char buf[40], buf1[40], buf2[40];
  // Header
  if (nbrOfDevices > 0) {
    //sprintf(buf1, "     Dev 1 ");
    sprintf(buf1, "Dev 1 (%3d)", endpoint1);
  } else {
    sprintf(buf1, "      n/a  ");
  }
  if (nbrOfDevices > 1) {
    //sprintf(buf2, "  Dev 2");
    sprintf(buf2, "Dev 2 (%3d)", endpoint2);
  } else {
    sprintf(buf2, "   n/a ");
  }
  sprintf(buf, "%s | %s", buf1, buf2);
  oDisplay1 = buf;

  // Short Address
  if (nbrOfDevices > 0) {
    sprintf(buf1, "0x%04x", shortAddress1);
  } else {
    sprintf(buf1, " n/a");
  }
  if (nbrOfDevices > 1) {
    sprintf(buf2, "0x%04x", shortAddress2);
  } else {
    sprintf(buf2, " n/a");
  }
  sprintf(buf, "srt  %s |   %s", buf1, buf2);
  oDisplay2 = buf;

  // Manufacturer
  sprintf(buf, "%-12.12s|%-12.12s", manufacturerChar1, manufacturerChar2);
  oDisplay3 = buf;

  // Model
  sprintf(buf, "%-12.12s|%-12.12s", modelChar1, modelChar2);
  oDisplay4 = buf;

  // Switch state
  sprintf(buf, "   %-9.9s|   %-9.9s", stateChar1, stateChar2);
  //sprintf(buf, "%-4.4s|%-4.4s", stateChar1, stateChar2);
  oDisplay5 = buf;

  oDisplayData();
}

/********************* Periodic task ***************************/
void periodicTask(void *arg) {
  while (true) {
    // print the bound lights every 10 seconds
    static uint32_t lastPrint = 0;
    if (millis() - lastPrint > 10000) {
      lastPrint = millis();
      zbSwitch.printBoundDevices(Serial);
    }

    // Poll light state every 2 seconds
    static uint32_t lastPoll = 0;
    if (millis() - lastPoll > 2000) {
      lastPoll = millis();
      zbSwitch.getLightState();
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
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

  //Optional: set Zigbee device name and model
  zbSwitch.setManufacturerAndModel("AndroidCrypto", "ZigbeeSwitch");

  //Optional to allow multiple light to bind to the switch
  zbSwitch.allowMultipleBinding(true);

  //zbSwitch.onLightStateChange(onLightStateChange);
  // register the onLightChange callback with source
  zbSwitch.onLightStateChangeWithSource(onLightStateChangeWithSource);

  //Add endpoint to Zigbee Core
  Serial.println("Adding ZigbeeSwitch endpoint to Zigbee Core");
  Zigbee.addEndpoint(&zbSwitch);

  //Open network for 180 seconds after boot
  Zigbee.setRebootOpenNetwork(180);
  oDisplay2 = "Network is open (180s)";
  oDisplayData();

  // When all EPs are registered, start Zigbee with ZIGBEE_COORDINATOR mode
  if (!Zigbee.begin(ZIGBEE_COORDINATOR)) {
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
  oDisplay3 = "    Zigbee started";
  oDisplayData();

  Serial.println("Waiting for Light to bound to the switch");
  //Wait for switch to bound to a light:
  while (!zbSwitch.bound()) {
    Serial.printf(".");
    delay(500);
  }
  onboardLedFlashBlue(1, 125);  // flash the LED
  oDisplay4 = "    Device bounded";
  oDisplayData();

  // set the unknown state of the devices
  strlcpy(stateChar1, "uknw", sizeof(stateChar1));
  strlcpy(stateChar2, "uknw", sizeof(stateChar2));


  // Optional: List all bound devices and read manufacturer and model name
  std::list<zb_device_params_t *> boundLights = zbSwitch.getBoundDevices();
  for (const auto &device : boundLights) {
    Serial.printf("Device on endpoint %d, short address: 0x%x\r\n", device->endpoint, device->short_addr);
    Serial.printf(
      "IEEE Address: %02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X\r\n", device->ieee_addr[7], device->ieee_addr[6], device->ieee_addr[5], device->ieee_addr[4],
      device->ieee_addr[3], device->ieee_addr[2], device->ieee_addr[1], device->ieee_addr[0]);
    // skip this here, is done later in 'listConnectedDevices()'
    /*
    char *manufacturer = zbSwitch.readManufacturer(device->endpoint, device->short_addr, device->ieee_addr);
    char *model = zbSwitch.readModel(device->endpoint, device->short_addr, device->ieee_addr);
    if (manufacturer != nullptr) {
      Serial.printf("Light manufacturer: %s\r\n", manufacturer);
    }
    if (model != nullptr) {
      Serial.printf("Light model: %s\r\n", model);
    }
    */
  }

  Serial.println();

  xTaskCreate(periodicTask, "periodicTask", 1024 * 4, NULL, 10, NULL);

  oDisplay5 = "   wait for actions";
  oDisplayData();
  onboardLedFlashWhite(1, 125);  // flash the LED
  delay(1000);
  oDisplayClearData();
}

void loop() {

  // Handle serial input to control the lights
  if (Serial.available()) {
    String command = Serial.readString();
    Serial.println("Command: " + command);

    if (command == "on") {
      Serial.println("  --> SIG Input : All Lights ON");
      zbSwitch.lightOn();
    } else if (command == "off") {
      Serial.println("  --> SIG Input : All Lights OFF");
      zbSwitch.lightOff();
    } else if (command == "toggle") {
      Serial.println("  --> SIG Input : Toggle all Lights");
      zbSwitch.lightToggle();
    } else if (command == "list") {
      Serial.println("  --> SIG Input : Get Devices");
      displayConnectedDevices();
      //zbSwitch.lightOff();
    } else if (command == "1on") {
      Serial.println("  --> SIG Input : Light 1 ON");
      zbSwitch.lightOn(endpoint1, ieeeAddress1);
    } else if (command == "1off") {
      Serial.println("  --> SIG Input : Light 1 OFF");
      zbSwitch.lightOff(endpoint1, ieeeAddress1);
    } else if (command == "2on") {
      Serial.println("  --> SIG Input : Light 2 ON");
      zbSwitch.lightOn(endpoint2, shortAddress2);
    } else if (command == "2off") {
      Serial.println("  --> SIG Input : Light 2 OFF");
      zbSwitch.lightOff(endpoint2, shortAddress2);
    } else if (command == "freset") {
      Serial.println("  --> SIG Input : Factory Reset!");
      delay(1500);
      Zigbee.factoryReset();
    } else if (command == "open_network") {
      Serial.println("  --> SIG Input : Open Network");
      Zigbee.openNetwork(180);
    } else if (command == "help") {
      Serial.println("  --> SIG Input : help");
      Serial.println("Use these commands: on | off | toggle | list | 1on | 1off | 2on | 2off | freset | open_network | help");
    }

    else {
      Serial.println("Unknown command");
    }
  }
  delay(100);
}