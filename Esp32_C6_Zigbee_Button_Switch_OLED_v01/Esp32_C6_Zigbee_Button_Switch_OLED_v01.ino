/*
  The sketch detects the button press of a Zigbee Button and is using the ZigbeeSwitch
  class for communicating with the button.

  Please use the settings below to see the data in the Serial Monitor.

*/

/*
  Version Management
15.04.2026 V01 This version is based on the  'Esp32_C6_Zigbee_On_Off_Switch_OLED_v01' sketch.  
               For debug reasons, I activated the Zigbee Debug Mode
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
  OLED SSD1306 Pin Mapping to ESP32-C6 Dev Board
OLED - ESP32-C6
GND  - GND
VCC  - 3.3 Volt
SCL  - GPIO 11 *1)
SDA  - GPIO 10 *1)
*1) There is no static GPIO usage, you can use every pin for the setup. I used pins 10 and 11 because they are on
    the same side as the power rail.  
*/

/*
  RGB LED flashing code
- during setup():
  Green: start of sketch
  Red:   Zigbee coordinator starting failure
  White: Device is bounded
  Blue:  The 'zbSwitch.getLightState()' was fired
- during loop():
  Green: received switch status change
  Blue:  The 'zbSwitch.getLightState()' was fired (optional)
*/

char *PROGRAM_VERSION = "ESP32 C6 Zigbee Button Switch V01";

// ------------------------------------------------------------------
#include <Arduino.h>
#ifndef ZIGBEE_MODE_ZCZR
#error "Zigbee coordinator mode is not selected in Tools->Zigbee mode"
#endif

#include "Zigbee.h"

/* Zigbee switch configuration */
#define SWITCH_ENDPOINT_NUMBER 1

// ------------------------------------------------------------------
// OLED display
#include "SSD1306_OLED.h"

// ------------------------------------------------------------------
// Onboard RGB LED
#include "ONBOARD_LEDS.h"

// ------------------------------------------------------------------

ZigbeeSwitch zbSwitch = ZigbeeSwitch(SWITCH_ENDPOINT_NUMBER);

// ------------------------------------------------------------------

bool isButtonPress = false;
const long BUTTON_PRESS_DISPLAY_MILLIS = 1000;  // 1 second
long lastButtonPressDisplayMillis = 0;

static void onLightStateChange(bool state) {
  onboardLedFlashGreen(1, 125); // flash the LED
  if (state) {
    Serial.println("Received onLightStateChange state: true");
  } else {
    Serial.println("Received onLightStateChange state: false");
  }
  lastButtonPressDisplayMillis = millis();
  isButtonPress = true;
}

/********************* Periodic task ***************************/
void periodicTask(void *arg) {
  while (true) {

    // Poll light state every second
    static uint32_t lastPoll = 0;
    if (millis() - lastPoll > 1000) {
      lastPoll = millis();
      zbSwitch.getLightState();
      // onboardLedFlashBlue(1, 125); // optional
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
  onboardLedFlashGreen(1, 125); // flash the LED

  // advanced debug mode, added by AndroidCrypto
  Zigbee.setDebugMode(true);

  // Optional: set Zigbee device name and model
  zbSwitch.setManufacturerAndModel("AndroidCrypto", "ZigbeeSwitch");

  // Optional to allow multiple light to bind to the switch
  zbSwitch.allowMultipleBinding(true);

  // Register the onLightStateChange callback
  zbSwitch.onLightStateChange(onLightStateChange);

  // Add endpoint to Zigbee Core
  Serial.println("Adding ZigbeeSwitch endpoint to Zigbee Core");
  Zigbee.addEndpoint(&zbSwitch);

  // Open network for 180 seconds after boot
  Zigbee.setRebootOpenNetwork(180);

  oDisplayClearData();
  oDisplay1 = " Starting";
  oDisplay2 = " Zigbee as";
  oDisplay3 = "coordinator";
  oDisplay4 = "  network";
  oDisplayData18();
  delay(2000);

  // When all EPs are registered, start Zigbee with ZIGBEE_COORDINATOR mode
  if (!Zigbee.begin(ZIGBEE_COORDINATOR)) {
    Serial.println("Zigbee failed to start!");
    Serial.println("Rebooting...");
    oDisplay1 = "Starting";
    oDisplay2 = "Zigbee as";
    oDisplay3 = "coordinator";
    oDisplay4 = "failed";
    oDisplayData18();
    onboardLedFlashRed(5, 125);  // flash the LED
    delay(2000);
    ESP.restart();
  }

  oDisplayClearData();
  oDisplay1 = "  Waiting";
  oDisplay2 = "for devices";
  oDisplay3 = " to bound";
  oDisplay4 = "";
  oDisplayData18();

  Serial.println("Waiting for a Button to bound to the switch");
  //Wait for switch to bound to a light:
  while (!zbSwitch.bound()) {
    Serial.printf(".");
    delay(500);
  }
  Serial.println();
  onboardLedFlashWhite(1, 125);  // flash the LED

  // Optional: List all bound devices and read manufacturer and model name
  char *manufacturer;
  char *model;
  std::list<zb_device_params_t *> boundLights = zbSwitch.getBoundDevices();
  for (const auto &device : boundLights) {
    Serial.printf("Device on endpoint %d, short address: 0x%x\r\n", device->endpoint, device->short_addr);
    Serial.printf(
      "IEEE Address: %02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X\r\n", device->ieee_addr[7], device->ieee_addr[6], device->ieee_addr[5], device->ieee_addr[4],
      device->ieee_addr[3], device->ieee_addr[2], device->ieee_addr[1], device->ieee_addr[0]);
    manufacturer = zbSwitch.readManufacturer(device->endpoint, device->short_addr, device->ieee_addr);
    model = zbSwitch.readModel(device->endpoint, device->short_addr, device->ieee_addr);
    oDisplayClearData();
    if (manufacturer != nullptr) {
      Serial.printf("Light manufacturer: %s\r\n", manufacturer);
      oDisplay2 = String(manufacturer);
    } else {
      oDisplay2 = " n/a";
    }
    if (model != nullptr) {
      Serial.printf("Light model: %s\r\n", model);
      oDisplay4 = String(model);
    } else {
      oDisplay4 = " n/a";
    }
  }
  Serial.println();
  oDisplay1 = "  Bounded:";
  oDisplay3 = "   Model:";
  oDisplayData13();
  delay(2000);
  
  zbSwitch.getLightState();
  onboardLedFlashBlue(1, 125);
  xTaskCreate(periodicTask, "periodicTask", 1024 * 4, NULL, 10, NULL);
}

void loop() {

  if (isButtonPress) {
    if (millis() - lastButtonPressDisplayMillis > BUTTON_PRESS_DISPLAY_MILLIS) {
      isButtonPress = false;
      oDisplayClearData();
      oDisplayData18();
      //zbSwitch.getLightState();
      //onboardLedFlashBlue(1, 125);
    } else {
      oDisplay1 = " The ";
      oDisplay2 = " button";
      oDisplay3 = " was";
      oDisplay4 = " pressed";
      oDisplayData18();
    }
  }
  delay(10);
}
