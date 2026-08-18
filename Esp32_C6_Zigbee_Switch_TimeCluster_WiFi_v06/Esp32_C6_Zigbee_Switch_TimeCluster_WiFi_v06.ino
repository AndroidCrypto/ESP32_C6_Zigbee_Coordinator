/*
  This sketch is the switch coordinator but with Real Time Cluster actions.
  It is receiving the current time from an NTP server during setup().

  Timezone String: please edit the 'TZ_INFO' parameter
  to a string that represents your local time zone. The
  example is the German/Europe parameter that includes
  a daylight saving time feature.

  The device will show the UTC and local time on the display, accompanied
  by the time offset (seconds between local and UTC time). As the base of
  this sketch is a Zigbee switch, the state of the connected light is shown
  on the display as well ('ON' or 'OFF').

  Please note this Arduino ESP32 version note:
  Since Arduino ESP32 version 3.3.9, the use of the Zigbee Time Cluster has 
  been buggy. You can either use version 3.3.8 —the last working version—
  or modify the Zigbee library. 
  You can find details on this in my tutorial "How to Use the Time Cluster 
  on an ESP32-C6 Zigbee Time Coordinator and End Device," 
  available at medium.com/@AndroidCrypto.

  Don't forget to change the Wi-Fi credentials in secret.h to your own data.
*/

const char* PROGRAM_VERSION = "ESP32-C6 Zigbee Switch with Time Cluster NTP Time Sync WiFi Coordinator V06";
const char* PROGRAM_VERSION_SHORT = "Zigbee Switch TimeCl V06";

// ------------------------------------------------------------------
// Zigbee

#include <Arduino.h>
#ifndef ZIGBEE_MODE_ZCZR
#error "Zigbee coordinator mode is not selected in Tools->Zigbee mode"
#endif

#include "Zigbee.h"

#define SWITCH_ENDPOINT_NUMBER 1
ZigbeeSwitch zbSwitch = ZigbeeSwitch(SWITCH_ENDPOINT_NUMBER);

// ------------------------------------------------------------------
// OLED display
#include "SSD1306_OLED.h"

// ------------------------------------------------------------------
// Onboard RGB LED
#include "ONBOARD_LEDS.h"

// ------------------------------------------------------------------
// NTP and WiFi Management

struct tm time_info_local;

// Define global time buffers (Size 9 allows for 8 chars + null terminator)
char utc_time[9];
char utc_date[9];
char local_time[9];
char local_date[9];
char utc_offset[6];

int32_t localOffset;  // is the difference in seconds between local time and UTC

#include "NTP_MANAGEMENT.h"


// ------------------------------------------------------------------
// Updates

const unsigned long DISPLAY_UPDATE_INTERVAL = 1000;               // each second
const unsigned long ZIGBEE_TIME_CLUSTER_UPDATE_INTERVAL = 60000;  // one minute
unsigned long lastZigbeeTimeClusterUpdate = 0;
bool switchState;

static void onLightStateChangeWithSource(bool state, uint8_t src_endpoint, esp_zb_zcl_addr_t src_address) {
  onboardLedFlashRed(1, 125);  // flash the LED
  if (state != switchState) {
    switchState = state;
    Serial.printf("1-Switch state dev 1 changed to: %d from endpoint %d, address 0x%04x\n", switchState, src_endpoint, src_address.u.short_addr);
    oDisplayData1813();
  }
}

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println(PROGRAM_VERSION);

  setupOnboardLeds();
  setupSsd1306();
  onboardLedFlashWhite(1, 125);  // flash the LED

  oDisplay1 = PROGRAM_VERSION_SHORT;
  oDisplay2 = "Waiting for time";
  oDisplay3 = "Synchronization";
  oDisplayData();

  bool success = sync_system_time_via_wifi();
  if (success) {
    getSystemTime();
    Serial.print("Local: ");
    Serial.print(local_date);
    Serial.print(" ");
    Serial.println(local_time);
    Serial.print("UTC:   ");
    Serial.print(utc_date);
    Serial.print(" ");
    Serial.println(utc_time);
    Serial.print("Offset:");
    Serial.println(utc_offset);
    Serial.println("Time synchronization done");
    oDisplay2 = "Time sync done";
    oDisplay3 = "UTC: " + String(utc_time);
    oDisplay4 = "LOC: " + String(local_time);
    oDisplay5 = "DAT: " + String(local_date) + " Offs:" + String(utc_offset);
    oDisplayData();
    onboardLedFlashGreen(1, 125);
    delay(2000);
  } else {
    Serial.println("ERROR during Time synchronization");
    Serial.println("System halted");
    oDisplay2 = "ERROR Time sync";
    oDisplay3 = "System HALTED";
    oDisplay4 = "";
    oDisplayData();
    onboardLedFlashRed(5, 125);
    delay(1000);
    while (1)
      ;
  }

  // add the Time Cluster with the data
  zbSwitch.addTimeCluster(time_info_local, localOffset);

  Zigbee.addEndpoint(&zbSwitch);

  // register the onLightChange callback with source
  zbSwitch.onLightStateChangeWithSource(onLightStateChangeWithSource);

  // advanced debug mode, added by AndroidCrypto
  Zigbee.setDebugMode(true);

  // Optional: set Zigbee device name and model
  zbSwitch.setManufacturerAndModel("AndroidCrypto", "ZigbeeTimeCl");

  // Optional to allow multiple light to bind to the switch
  zbSwitch.allowMultipleBinding(true);

  // Open network for 180 seconds after boot
  Zigbee.setRebootOpenNetwork(180);
  oDisplay2 = "Network is open (180s)";
  oDisplay3 = "";
  oDisplay4 = "";
  oDisplayData();

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
  Serial.println("Zigbee started successfully with the received time.");

  Serial.println("Waiting for Light to bound to the switch");
  // Wait for switch to bound to a light:
  while (!zbSwitch.bound()) {
    Serial.printf(".");
    delay(500);
  }
  onboardLedFlashBlue(1, 125);  // flash the LED
  oDisplay4 = "    Device bounded";
  oDisplayData();
}

void loop() {

  // display update
  static unsigned long lastDisp = 0;
  if (millis() - lastDisp >= DISPLAY_UPDATE_INTERVAL) {
    lastDisp = millis();
    getSystemTime();
    updateDisplay();
  }

  //
  if (millis() - lastZigbeeTimeClusterUpdate > ZIGBEE_TIME_CLUSTER_UPDATE_INTERVAL) {

    // Whenever you need the time
    getSystemTime();

    // The variables now contain the updated strings
    Serial.print("Local: ");
    Serial.print(local_date);
    Serial.print(" ");
    Serial.println(local_time);
    Serial.print("UTC:   ");
    Serial.print(utc_date);
    Serial.print(" ");
    Serial.println(utc_time);

    //getTimeByUtcTimestamp();
    Serial.println("###################################");
    //zbSwitch.setTime(timeinfo);
    zbSwitch.setTime(time_info_local);
    zbSwitch.setTimezone(localOffset);
    //Serial.printf("Zigbee Time Cluster updated UTC timestamp %d localOffset %d\n", timeinfo, localOffset);
    Serial.printf("Zigbee Time Cluster updated UTC timestamp %d localOffset %d\n", time_info_local, localOffset);
    int32_t localOffsetCoordinator = zbSwitch.getTimezone(SWITCH_ENDPOINT_NUMBER);
    Serial.printf("Zigbee Time Cluster\nlocal Offset in Coordinator: %d seconds\n", localOffsetCoordinator);
    printCurrentTime();
    Serial.println("###################################");
    lastZigbeeTimeClusterUpdate = millis();
  }

  // Poll light state every 2 seconds
  static uint32_t lastPoll = 0;
  if (millis() - lastPoll > 2000) {
    lastPoll = millis();
    //zbSwitch.getLightState();
  }
}

void printCurrentTime() {
  time_t now;
  struct tm timeinfo;
  char buffer[64];
  time(&now);  // get current system time
  // LOCAL TIME
  localtime_r(&now, &timeinfo);
  strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", &timeinfo);
  Serial.printf("Local time: %s\n", buffer);
  // UTC TIME
  gmtime_r(&now, &timeinfo);
  strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", &timeinfo);
  Serial.printf("UTC time:   %s\n", buffer);
}

void updateDisplay() {
  char buf[64];
  oDisplay1 = " " + String(local_time);
  oDisplay2 = "Local: " + String(local_date);
  oDisplay3 = "UTC:   " + String(utc_time);
  //oDisplay4 = " Offset:" + String(utc_offset) + "s";
  if (switchState) {
    sprintf(buf, "Offset:%ss ON", utc_offset);
  } else {
    sprintf(buf, "Offset:%ss OFF", utc_offset);
  }
  oDisplay4 = buf;
  oDisplayData1813();
}
