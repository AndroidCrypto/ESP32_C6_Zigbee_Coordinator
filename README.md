# ESP32-C6 Zigbee Coordinator

This repository accompanies a series of articles about the **ESP32-C6** microcontroller, which operates a **Zigbee coordinator**:

- Overview tutorial "**How to use an ESP32-C6 as Zigbee Coordinator or End Device (overview)**": https://medium.com/@androidcrypto/how-to-use-an-esp32-c6-as-zigbee-coordinator-or-end-device-overview-e70cfa7f45f9
- **How to use an ESP32-C6 as Zigbee Coordinator or End Device for a Light or Switch**: https://medium.com/@androidcrypto/how-to-use-an-esp32-c6-as-zigbee-coordinator-or-end-device-for-a-switch-or-light-f7b915c99530
- **How to control multiple Zigbee switches or lights with an ESP32-C6 Coordinator**: https://medium.com/@androidcrypto/how-to-control-multiple-zigbee-switches-or-lights-with-an-esp32-c6-coordinator-f5350e510587
- **How to use an ESP32-C6 as Zigbee Coordinator or End Device for a Thermometer or Thermostat**: https://medium.com/@androidcrypto/how-to-use-an-esp32-c6-as-zigbee-coordinator-or-end-device-for-a-thermometer-or-thermostat-b91fca418849
- **Setup a reporting in an ESP32-C6 as Zigbee Coordinator for a Thermostat**: https://medium.com/@androidcrypto/a-zsetup-a-reporting-in-an-esp32-c6-as-zigbee-coordinator-for-a-thermostat-2560b27bfd27
- **How to control multiple Zigbee thermometers with an ESP32-C6 Coordinator**: https://medium.com/@androidcrypto/how-to-control-multiple-zigbee-thermometers-with-an-esp32-c6-coordinator-7b0fb27a96c8
- **How to use an ESP32-C6 as a Zigbee Coordinator for a Button**: https://medium.com/@androidcrypto/how-to-use-an-esp32-c6-as-a-zigbee-coordinator-for-a-button-c2e2a767b7bb
- **How to connect an ESP32-C6 Zigbee Coordinator to a smart plug socket and read the current wattage (part 1)**: soon
- **How to connect an ESP32-C6 Zigbee Coordinator to a smart plug socket and read the current wattage (part 2)**: soon

## Sketches for the tutorials

The code of each sketch is in sepate folders.

### ESP32-C6 as Zigbee Coordinator for a Switch

- Original "On-Off-Light" sketch:   **[Esp32_C6_Zigbee_On_Off_Light_v01](./Esp32_C6_Zigbee_On_Off_Light_v01)** folder (end device)
- Original "On-Off-Switch" sketch:  **[Esp32_C6_Zigbee_On_Off_Switch_v01](./Esp32_C6_Zigbee_On_Off_Switch_v01)** folder (coordinator)
- "On-Off-Light with OLED" sketch:  **[Esp32_C6_Zigbee_On_Off_Light_OLED_v01](./Esp32_C6_Zigbee_On_Off_Light_OLED_v01)** folder **(recommended)**  (end device)
- "On-Off-Switch with OLED" sketch: **[Esp32_C6_Zigbee_On_Off_Switch_OLED_v01](./Esp32_C6_Zigbee_On_Off_Switch_OLED_v01)** folder **(recommended)** (coordinator)

### ESP32-C6 as Zigbee Coordinator for multiple Switches or Lights
- Modified "On-Off-Light" sketch:   **[Esp32_C6_Zigbee_On_Off_Light_v01b](./Esp32_C6_Zigbee_On_Off_Light_v01b)** folder (end device): changed the end device number, manufacturer and model name
- "Multiple Switches/Light" sketch: **[Esp32_C6_Zigbee_On_Off_Multi_Switch_OLED_v01](./Esp32_C6_Zigbee_On_Off_Multi_Switch_OLED_v01)** folder (coordinator)

### ESP32-C6 as Zigbee Coordinator for a Thermostat
- Original "Temperature_Sensor" sketch: **[Esp32_C6_Zigbee_Temperature_Sensor_v01](./Esp32_C6_Zigbee_Temperature_Sensor_v01)** folder (end device)
- Original "Thermostat" sketch: **[Esp32_C6_Zigbee_Thermostat_v01](./Esp32_C6_Zigbee_Thermostat_v01)** folder (coordinator)
- Modified and advanced "Thermostat" sketch: **[Esp32_C6_Zigbee_Coordinator_Thermostat_OLED_v01](./Esp32_C6_Zigbee_Coordinator_Thermostat_OLED_v01)** folder (coordinator)

### Setup the reporting on an ESP32-C6 as Zigbee Coordinator for a Thermostat
- advanced "Thermostat" sketch: **[Esp32_C6_Zigbee_Coordinator_Thermostat_Reporting_OLED_v06](./Esp32_C6_Zigbee_Coordinator_Thermostat_Reporting_OLED_v06)** folder (coordinator)

### ESP32-C6 as Zigbee Coordinator for multiple Thermometers
- "Multi Thermometer" sketch: **[Esp32_C6_Zigbee_Multi_Thermostat_OLED_v01](./Esp32_C6_Zigbee_Multi_Thermostat_OLED_v01)** folder (coordinator)
- "Advanced Thermometer" with LQI + RSSI displaying sketch Device 1: **[Esp32_C6_Zigbee_Temperature_Sensor_LQI_OLED_v02_d1](./Esp32_C6_Zigbee_Temperature_Sensor_LQI_OLED_v02_d1)** folder (end device)
- "Advanced Thermometer" with LQI + RSSI displaying sketch Device 2: **[Esp32_C6_Zigbee_Temperature_Sensor_LQI_OLED_v02_d2](./Esp32_C6_Zigbee_Temperature_Sensor_LQI_OLED_v02_d2)** folder (end device)
- "Advanced Thermometer" with LQI + RSSI displaying sketch Device 3: **[Esp32_C6_Zigbee_Temperature_Sensor_LQI_OLED_v02_d3](./Esp32_C6_Zigbee_Temperature_Sensor_LQI_OLED_v02_d3)** folder (end device)

### ESP32-C6 as Zigbee Coordinator for a Button
- "Button" sketch: **[Esp32_C6_Zigbee_Button_Switch_OLED_v01](./Esp32_C6_Zigbee_Button_Switch_OLED_v01)** folder (coordinator)

## Useful links

All programs are based on [examples](https://github.com/espressif/arduino-esp32/tree/master/libraries/Zigbee/examples) from the **[Arduino ESP32 library](https://github.com/espressif/arduino-esp32)** (there is a [Zigbee subfolder](https://github.com/espressif/arduino-esp32/tree/master/libraries/Zigbee)). However, this library is largely dependent on the parent **[esp-zigbee-sdk](https://github.com/espressif/esp-zigbee-sdk)**. The subdirectory [components/esp-zigbee-lib/include/](https://github.com/espressif/esp-zigbee-sdk/tree/main/components/esp-zigbee-lib/include) contains many files that define, for example, cluster and attribute settings for the various devices.

Another useful source of information is provided by the Espressif documents with the [Zigbee API description](https://docs.espressif.com/projects/arduino-esp32/en/latest/libraries.html#zigbee-apis).

If you are working with devices from the Chinese developer **Tuya**, you should take a look at the [documentation](https://developer.tuya.com/en/docs/connect-subdevices-to-gateways/Zigbee_2?id=Kcww7qppbe87m), e.g. a technical overview of a [Smart Plug energy meter](https://developer.tuya.com/en/docs/connect-subdevices-to-gateways/tuya-zigbee-measuring-smart-plug-access-standard?id=K9ik6zvofpzqk).

## Development Environment (Arduino)
````plaintext
Arduino IDE Version 2.3.8 (Windows)
arduino-esp32 boards Version 3.3.7 (https://github.com/espressif/arduino-esp32) that is based on Espressif ESP32 Version 5.5.1
````

Last update: April, 22 2026
