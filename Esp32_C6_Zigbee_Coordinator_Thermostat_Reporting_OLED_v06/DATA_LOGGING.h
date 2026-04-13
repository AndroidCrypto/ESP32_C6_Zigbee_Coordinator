/*
  The storage of data is done here.

  Version management
  28.03.2026 V02 Including storage in SPIFFS (CSV files for 4 sensors, current data and difference data)
  28.03.2026 V01 Initial programming
*/

#ifndef IS_DATA_LOGGING
#define IS_DATA_LOGGING
#endif

#include <string.h> // for memset
#include "SPIFFS.h"

const int NUM_SENSORS = 4;
const int MAX_READINGS = 20;

//#define ACTIVATE_SPIFFS_STORAGE true

// structure for each data point
struct Reading {
  unsigned long timestamp;
  float value;
};

// structure for each data point when returning value and timestamp
struct HistoryResult {
  float value;
  unsigned long timestamp;
  bool valid; // if the value is not available
};

struct HistoryDiff {
  float valueDiff;          // difference of the values
  long timeDiff;            // difference in time in ms
  bool valid;               // true, if both datapoints exist
};

// 2d-array: 4 sensor readings, each 20 data points
Reading history[NUM_SENSORS][MAX_READINGS];

// separate indices for each sensor
int writeIndices[NUM_SENSORS] = {0, 0, 0, 0};
int counts[NUM_SENSORS] = {0, 0, 0, 0};

// global counter for CSV
unsigned long totalMeasurements[NUM_SENSORS] = {0, 0, 0, 0};

// filenames
const char* rawFiles[] = {"/s0_raw.csv", "/s1_raw.csv", "/s2_raw.csv", "/s3_raw.csv"};
const char* diffFiles[] = {"/s0_diff.csv", "/s1_diff.csv", "/s2_diff.csv", "/s3_diff.csv"};

// method for storing of a single value
void logSingleSensor(int sensorIdx, float val) {
  if (sensorIdx < 0 || sensorIdx >= NUM_SENSORS) return;

  int currentIdx = writeIndices[sensorIdx];
  
  // store the value and timestamp
  history[sensorIdx][currentIdx].value = val;
  history[sensorIdx][currentIdx].timestamp = millis();

  // increase the index for this sensor
  writeIndices[sensorIdx] = (currentIdx + 1) % MAX_READINGS;
  if (counts[sensorIdx] < MAX_READINGS) counts[sensorIdx]++;
}

// method to get the last 20 values of a sensor
void printHistory(int sensorIdx) {
  Serial.printf("\n--- Historie Sensor % d (oldest first) --- \n", sensorIdx);
  
  int total = counts[sensorIdx];
  int startIdx = writeIndices[sensorIdx];

  for (int i = 0; i < total; i++) {
    // get the index, starting with the oldest value to the newest value
    int idx = (startIdx - total + i + MAX_READINGS) % MAX_READINGS;
    
    Serial.printf("Point %02d | Time: %lu ms | Value: %.2f\n", 
                  i + 1, 
                  history[sensorIdx][idx].timestamp, 
                  history[sensorIdx][idx].value);
  }
}

void printHistoryNewestFirst(int sensorIdx) {
  Serial.printf("\n--- History Sensor %d (newest first) ---\n", sensorIdx);
  
  int total = counts[sensorIdx];
  int latestIdx = writeIndices[sensorIdx] - 1; // Der zuletzt geschriebene Index

  for (int i = 0; i < total; i++) {
    // count backwards: newest first, oldest last
    // + MAX_READINGS is important to avoid negative modulo value
    int idx = (latestIdx - i + MAX_READINGS) % MAX_READINGS;
    
    Serial.printf("Point %02d | Time: %lu ms | Value: %.2f\n", 
                  i + 1, 
                  history[sensorIdx][idx].timestamp, 
                  history[sensorIdx][idx].value);
  }
}

// gives the newest value
void printLatestSingleValue(int sensorIdx) {
  if (sensorIdx < 0 || sensorIdx >= NUM_SENSORS) return;

  // check that a value was stored before
  if (counts[sensorIdx] == 0) {
    Serial.printf("Sensor %d: No data available.\n", sensorIdx);
    return;
  }

  // the newest value is available at (writeIndex - 1)
  int latestIdx = (writeIndices[sensorIdx] - 1 + MAX_READINGS) % MAX_READINGS;
  
  float val = history[sensorIdx][latestIdx].value;
  unsigned long ts = history[sensorIdx][latestIdx].timestamp;

  Serial.printf("Latest Sensor %d | Time: %lu ms | Value: %.2f\n", sensorIdx, ts, val);
}

// returns the number of stored data points of sensor (0 to 20)
int getStoredCount(int sensorIdx) {
  if (sensorIdx < 0 || sensorIdx >= NUM_SENSORS) return 0;
  
  return counts[sensorIdx];
}

// example for usage in Serial Monitor
void printAllCounts() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.printf("Sensor %d hat aktuell %d Messwerte im Speicher.\n", i, counts[i]);
  }
}

// returns a specific historic value
// index 0 = newest, 1 = second newest, ..., 19 = oldest
float getHistoricalValue(int sensorIdx, int historyIndex) {
  // sanity checks: sensor available? Index in range 0-19? Daten available?
  if (sensorIdx < 0 || sensorIdx >= NUM_SENSORS) return 0.0;
  if (historyIndex < 0 || historyIndex >= MAX_READINGS) return 0.0;
  if (historyIndex >= counts[sensorIdx]) return 0.0; // if there are not 20 points available

  // the newest value is at (writeIndex - 1)
  int latestIdx = (writeIndices[sensorIdx] - 1 + MAX_READINGS) % MAX_READINGS;
  
  // go backwards in 'historyIndex'
  int targetIdx = (latestIdx - historyIndex + MAX_READINGS) % MAX_READINGS;
  
  return history[sensorIdx][targetIdx].value;
}

// returns value, timestamp and valid
// index 0 = newest, 1 = second newest, ..., 19 = oldest
HistoryResult getHistoricalData(int sensorIdx, int historyIndex) {
  HistoryResult result = {0.0, 0, false};

  // sanity checks
  if (sensorIdx < 0 || sensorIdx >= NUM_SENSORS) return result;
  if (historyIndex < 0 || historyIndex >= MAX_READINGS) return result;
  if (historyIndex >= counts[sensorIdx]) return result;

  // calculate the position in ring (0 = newest)
  int latestIdx = (writeIndices[sensorIdx] - 1 + MAX_READINGS) % MAX_READINGS;
  int targetIdx = (latestIdx - historyIndex + MAX_READINGS) % MAX_READINGS;
  
  result.value = history[sensorIdx][targetIdx].value;
  result.timestamp = history[sensorIdx][targetIdx].timestamp;
  result.valid = true;

  return result;
}

// index 0 = newest, 1 = second newest, ..., 19 = oldest
HistoryDiff getHistoricalDataDifference(int sensorIdx, int historyIndex) {
  HistoryDiff diff = {0.0, 0, false};

  // we need the selected data point (n) und and its precessor (n+1)
  // example: n=0 (newest) vs n=1 (second newest) data point
  HistoryResult current = getHistoricalData(sensorIdx, historyIndex);
  HistoryResult previous = getHistoricalData(sensorIdx, historyIndex + 1);

  // calculate if both data points exist only
  if (current.valid && previous.valid) {
    diff.valueDiff = current.value - previous.value;
    
    // difference in time (as millis() is unsigned, we are using long for the result)
    diff.timeDiff = (long)(current.timestamp - previous.timestamp);
    diff.valid = true;
  }
  return diff;
}

void clearAllSensors() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    writeIndices[i] = 0;
    counts[i] = 0;
  }
  Serial.println("All sensor data references got deleted.");
}

void clearSingleSensor(int sensorIdx) {
  if (sensorIdx < 0 || sensorIdx >= NUM_SENSORS) return;
  
  writeIndices[sensorIdx] = 0;
  counts[sensorIdx] = 0;
  Serial.printf("Data for sensor %d was resetted.\n", sensorIdx);
}

void hardResetAll() {
  // 1. Reset counter
  for (int i = 0; i < NUM_SENSORS; i++) {
    writeIndices[i] = 0;
    counts[i] = 0;
  }
  // 2. Clear the complete memory by overwriting with 0
  memset(history, 0, sizeof(history));
  
  Serial.println("Memory completely cleared.");
}

void setupSPIFFS() {
#ifdef ACTIVATE_SPIFFS_STORAGE  
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS Mount Failed");
    onboardLedFlashWhite(10, 125);
    return;
  }
#endif  
}

// helper for writing the measured data
void writeRawToCSV(int sensorIdx, float val, unsigned long ts) {
  File file = SPIFFS.open(rawFiles[sensorIdx], FILE_APPEND);
  if (file) {
    // format: increasing number, value, timestamp
    file.printf("%lu,%.2f,%lu\n", totalMeasurements[sensorIdx], val, ts);
    file.close();
  }
}

// helper for writing the difference data
void writeDiffToCSV(int sensorIdx, float valDiff, long timeDiff) {
  File file = SPIFFS.open(diffFiles[sensorIdx], FILE_APPEND);
  if (file) {
    // format: increasing number, value difference, timestamp difference
    file.printf("%lu,%.2f,%ld\n", totalMeasurements[sensorIdx], valDiff, timeDiff);
    file.close();
  }
}

void logAndStore(int sensorIdx, float val) {
  if (sensorIdx < 0 || sensorIdx >= NUM_SENSORS) return;

  // 1. increase the counter for this sensor
  totalMeasurements[sensorIdx]++;

  // 2. store in ring storage
  logSingleSensor(sensorIdx, val); 

#ifdef ACTIVATE_SPIFFS_STORAGE
  // 3. get data for CSV
  HistoryResult current = getHistoricalData(sensorIdx, 0);
  HistoryDiff diff = getHistoricalDataDifference(sensorIdx, 0);

  // 4. write data in SPIFFS
  if (current.valid) {
    writeRawToCSV(sensorIdx, current.value, current.timestamp);
  }
  
  if (diff.valid) {
    writeDiffToCSV(sensorIdx, diff.valueDiff, diff.timeDiff);
  }
#endif  
}

void printStorageInfo() {
  Serial.println("\n--- SPIFFS STORAGE Overview ---");

  // 1. get the size of the 8 CSV-files
  unsigned long totalFilesSize = 0;
  
  Serial.println("File sizes:");
  for (int i = 0; i < NUM_SENSORS; i++) {
    // raw files
    File raw = SPIFFS.open(rawFiles[i], "r");
    size_t sRaw = raw ? raw.size() : 0;
    raw.close();
    
    // difference files
    File diff = SPIFFS.open(diffFiles[i], "r");
    size_t sDiff = diff ? diff.size() : 0;
    diff.close();

    Serial.printf("  Sensor %d: Raw = %7u Bytes | Diff = %7u Bytes\n", i, sRaw, sDiff);
    totalFilesSize += (sRaw + sDiff);
  }

  // 2. total storage overview
  size_t totalBytes = SPIFFS.totalBytes();
  size_t usedBytes = SPIFFS.usedBytes();
  size_t freeBytes = totalBytes - usedBytes;

  Serial.println("-------------------------------------------");
  Serial.printf("Total storage size SPIFFS: %10u bytes\n", totalBytes);
  Serial.printf("Used  storage size       : %10u Bytes\n", usedBytes);
  Serial.printf("Empty storage size       : %10u Bytes\n", freeBytes);
  Serial.println("-------------------------------------------\n");
}

void clearAllFiles() {
  Serial.println("Clear the content of all 8 CSV files...");

  for (int i = 0; i < NUM_SENSORS; i++) {
    // 1. clear raw value file
    File fRaw = SPIFFS.open(rawFiles[i], "w");
    if (fRaw) {
      fRaw.close();
    }

    // 2. clear difference value file
    File fDiff = SPIFFS.open(diffFiles[i], "w");
    if (fDiff) {
      fDiff.close();
    }

    // 3. reset counter
    totalMeasurements[i] = 0;
    
    // optional: clear RAM ringstorage
    writeIndices[i] = 0;
    counts[i] = 0;
  }

  Serial.println("All files got cleared and the counter resetted to 0.");
}

// testing the ring data storage, not the SPIFFS storage
void runFullTest() {
  Serial.println("\n=== STARTING TESTROUTINE ===");

  // 1. fill data (simulation: sensor 0 gets 25 value -> overflow test)
  Serial.println("1. Simulate 25 measures for sensor 0 (test overflow)...");
  for (int i = 1; i <= 25; i++) {
    logSingleSensor(0, (float)i * 1.1); 
    delay(10); // change the timestamp
  }

  // 2. Check number
  Serial.print("2. Check number of measures for sensor 0: ");
  Serial.println(counts[0]); // should be 20

  // 3. Access to each single data point (0 = newest, 1 = second newest, 19 = oldest)
  Serial.println("3. Test access:");
  HistoryResult newV = getHistoricalData(0, 0);
  HistoryResult oldV = getHistoricalData(0, 19);

  if (newV.valid) Serial.printf("   Newest (index 0): %.2f (Time: %lu)\n", newV.value, newV.timestamp);
  if (oldV.valid) Serial.printf("   Oldest (index 19):  %.2f (Time: %lu)\n", oldV.value, oldV.timestamp);

  // 4. print complete history (newest first)
  Serial.println("4. Complette history Sensor 0 (newest first):");
  for (int i = 0; i < counts[0]; i++) {
    HistoryResult data = getHistoricalData(0, i);
    Serial.printf("   Pos %02d: %.2f | Time: %lu\n", i, data.value, data.timestamp);
  }

  // 5. Test a sensor without data
  Serial.print("5. Test empty sensor 3: ");
  HistoryResult empty = getHistoricalData(3, 0);
  if (!empty.valid) Serial.println("No data available.");

  Serial.println("=== TEST END ===\n");
}