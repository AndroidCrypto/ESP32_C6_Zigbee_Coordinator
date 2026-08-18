#ifndef NTP_MANAGEMENT_H
#define NTP_MANAGEMENT_H

#include <WiFi.h>
#include <time.h>
#include "secret.h"  // Includes your WiFi credentials

// =================================================================================
// TIMEZONE CONFIGURATION (POSIX FORMAT)
// =================================================================================
// Format breakdown for "CET-1CEST,M3.5.0,M10.5.0/3":
// - CET-1: Central European Time is 1 hour ahead of UTC (-1 in POSIX means UTC+1)
// - CEST: Name of the daylight saving time zone
// - M3.5.0: Switch to DST on the 3rd month (March), 5th week (last week), 0th day (Sunday)
// - M10.5.0/3: Switch back to standard time on the 10th month (October), last Sunday, at 3:00 AM
//
// WHERE TO FIND OTHER TIMEZONES:
// You can find a complete list of POSIX timezone strings on GitHub by searching for
// the repository "nayarsystems/posix_tz_db" and opening the file "zones.csv".
// URL Reference: github.com / nayarsystems / posix_tz_db / blob / master / zones.csv
// =================================================================================
const char* TIME_ZONE_BERLIN = "CET-1CEST,M3.5.0,M10.5.0/3";

// External references to the char arrays defined in the main sketch header
extern struct tm time_info_local;
extern char utc_time[9];
extern char utc_date[9];
extern char local_time[9];
extern char local_date[9];
extern char utc_offset[6];
extern int32_t localOffset;

/**
 * @brief Connects once to WiFi, synchronizes system time via NTP,
 *        sets the POSIX time zone for Berlin, and disconnects from WiFi.
 * 
 * @return true if synchronization is successful, false on error/timeout
 */
static inline bool sync_system_time_via_wifi() {
  // Initialize and stabilize WiFi radio
  // Always set mode first to ensure the WiFi driver is fully initialized (prevents ESP_ERR_WIFI_NOT_INIT)
  // Disable saving credentials to flash to prevent NVS wear and dual-connect attempts
  WiFi.persistent(false);

  Serial.println("[NTP] Connecting to WiFi...");
  WiFi.begin(ssid_ntp, password_ntp);

  // Wait for connection with a timeout of approx. 15 seconds
  int wifi_timeout_counter = 0;
  while (WiFi.status() != WL_CONNECTED && wifi_timeout_counter < 30) {
    delay(500);
    Serial.print(".");
    wifi_timeout_counter++;
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("\n[NTP] Error: WiFi connection failed.");
    WiFi.disconnect(true, true);
    WiFi.mode(WIFI_OFF);

    // AUTOMATIC RECOVERY: If it fails (like right after flashing),
    // force a clean system restart to reset the RF registers properly.
    Serial.println("[NTP] Triggering ESP.restart() for clean RF recovery...");
    delay(500);
    ESP.restart();

    return false;
  }

  Serial.println("\n[NTP] Successfully connected to WiFi.");

  // Set POSIX time zone (with automatic daylight saving time changes)
  configTzTime(TIME_ZONE_BERLIN, "pool.ntp.org", "time.nist.gov");

  // Wait until the time is synchronized via NTP
  Serial.println("[NTP] Waiting for NTP synchronization...");
  struct tm time_info;
  int ntp_timeout_counter = 0;

  while (!getLocalTime(&time_info) && ntp_timeout_counter < 30) {
    delay(500);
    Serial.print(".");
    ntp_timeout_counter++;
  }

  bool is_sync_successful = false;
  if (ntp_timeout_counter < 30) {
    Serial.println("\n[NTP] Time successfully synchronized!");
    Serial.print("[NTP] Current configured local time: ");
    Serial.println(&time_info, "%A, %B %d %Y %H:%M:%S");
    is_sync_successful = true;
  } else {
    Serial.println("\n[NTP] Error: NTP timeout exceeded.");
  }

  // Deep cleanup and radio shutdown
  // This is where we safely wipe all RAM caches and kill the driver for Zigbee operation
  WiFi.disconnect(true, true);
  delay(100);
  WiFi.mode(WIFI_OFF);
  delay(100);
  Serial.println("[NTP] WiFi disconnected and RF module turned off.");

  return is_sync_successful;
}

/**
 * @brief Reads the current system time and updates the global UTC and Local time/date char arrays.
 */
static inline void getSystemTime() {
  time_t raw_time;
  //struct tm time_info_local; // globally defined
  struct tm time_info_utc;

  time(&raw_time);
  localtime_r(&raw_time, &time_info_local);
  gmtime_r(&raw_time, &time_info_utc);

  strftime(local_time, sizeof(local_time), "%H:%M:%S", &time_info_local);
  strftime(local_date, sizeof(local_date), "%d.%m.%y", &time_info_local);

  strftime(utc_time, sizeof(utc_time), "%H:%M:%S", &time_info_utc);
  strftime(utc_date, sizeof(utc_date), "%d.%m.%y", &time_info_utc);

  // this part is calculating the localOffset (difference in seconds between local- and UTC time)
  time_info_utc.tm_isdst = time_info_local.tm_isdst;
  long myOffset = (long)difftime(mktime(&time_info_local), mktime(&time_info_utc));
  localOffset = myOffset;
  snprintf(utc_offset, sizeof(utc_offset), "%d", localOffset);
}

#endif  // NTP_MANAGEMENT_H
