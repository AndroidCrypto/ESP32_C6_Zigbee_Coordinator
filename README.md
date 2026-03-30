# ESP32-C6 Zigbee Coordinator

This repository accompanies a series of articles about the **ESP32-C6** microcontroller, which operates a **Zigbee coordinator**:

- Overview tutorial "**How to use an ESP32-C6 as Zigbee Coordinator or End Device (overview)**": soon
- **How to use an ESP32-C6 as Zigbee Coordinator or End Device for a Thermometer or Thermostat**: soon
- **How to connect an ESP32-C6 Zigbee Coordinator to a smart plug socket and read the current wattage (part 1)**: soon

## Useful links

All programs are based on [examples](https://github.com/espressif/arduino-esp32/tree/master/libraries/Zigbee/examples) from the **[Arduino ESP32 library](https://github.com/espressif/arduino-esp32)** (there is a [Zigbee subfolder](https://github.com/espressif/arduino-esp32/tree/master/libraries/Zigbee)). However, this library is largely dependent on the parent **[esp-zigbee-sdk](https://github.com/espressif/esp-zigbee-sdk)**. The subdirectory [components/esp-zigbee-lib/include/](https://github.com/espressif/esp-zigbee-sdk/tree/main/components/esp-zigbee-lib/include) contains many files that define, for example, cluster and attribute settings for the various devices.

## Development Environment (Arduino)
````plaintext
Arduino IDE Version 2.3.8 (Windows)
arduino-esp32 boards Version 3.3.7 (https://github.com/espressif/arduino-esp32) that is based on Espressif ESP32 Version 5.5.1
````

Last update: March, 30 th. 2026
