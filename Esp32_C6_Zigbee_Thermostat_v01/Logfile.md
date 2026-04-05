Sketch uses 768636 bytes (58%) of program storage space. Maximum is 1310720 bytes.
Global variables use 36792 bytes (11%) of dynamic memory, leaving 290888 bytes for local variables. Maximum is 327680 bytes.

[     0][V][ZigbeeEP.cpp:27] ZigbeeEP(): Endpoint: 1
[  2274][D][ZigbeeCore.cpp:578] bindingTableCb(): Clearing bound devices for EP 1
Waiting for Temperature sensor to bound to the thermostat
.[  2738][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0x2e1e) is open for 180 seconds
...............................[ 18170][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NWK Device Associated (0x12), status: ESP_OK
[ 18193][I][ZigbeeCore.cpp:360] esp_zb_app_signal_handler(): New device commissioned or rejoined (short: 0x697c)
[ 18193][V][ZigbeeCore.cpp:364] esp_zb_app_signal_handler(): Device capabilities: 0x8c
[ 18194][D][ZigbeeCore.cpp:378] esp_zb_app_signal_handler(): Checking endpoint 1
[ 18194][D][ZigbeeCore.cpp:393] esp_zb_app_signal_handler(): Device not bound to endpoint 1 and it is free to bound!
[ 18195][D][ZigbeeCore.cpp:395] esp_zb_app_signal_handler(): Endpoint 1 is searching for device
[ 18228][D][ZigbeeThermostat.cpp:80] findCbWrapper(): findCbWrapper on EP 1
[ 18228][I][ZigbeeThermostat.cpp:88] findCb(): Found temperature sensor
[ 18228][D][ZigbeeThermostat.cpp:96] findCb(): Temperature sensor found: short address(0x697c), endpoint(10)
[ 18229][I][ZigbeeThermostat.cpp:107] findCb(): Request temperature sensor to bind us
[ 18229][I][ZigbeeThermostat.cpp:110] findCb(): Request humidity sensor to bind us
[ 18230][I][ZigbeeThermostat.cpp:124] findCb(): Try to bind Humidity Measurement
[ 18230][I][ZigbeeThermostat.cpp:130] findCb(): Try to bind Temperature Measurement
[ 18232][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[ 18233][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[ 18240][D][ZigbeeThermostat.cpp:72] bindCbWrapper(): bindCbWrapper on EP 1
[ 18240][I][ZigbeeThermostat.cpp:56] bindCb(): Bound successfully!
[ 18241][I][ZigbeeThermostat.cpp:59] bindCb(): The sensor originating from address(0x697c) on endpoint(10)
[ 18241][D][ZigbeeThermostat.cpp:60] bindCb(): Sensor bound to thermostat on EP 1
[ 18243][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[ 18243][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 2, index 0, count 2
[ 18244][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 1, dst_endp 10, cluster_id 0x0405, dst_addr_mode 3
[ 18245][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 1: src_endp 1, dst_endp 10, cluster_id 0x0402, dst_addr_mode 3
[ 18245][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 2
[ 18246][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 1
[ 18246][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 18246][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 18247][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 18247][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 18248][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
[ 18248][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[ 18249][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 2, index 0, count 2
[ 18249][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 1, dst_endp 10, cluster_id 0x0405, dst_addr_mode 3
[ 18250][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 1: src_endp 1, dst_endp 10, cluster_id 0x0402, dst_addr_mode 3
[ 18250][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 2
[ 18251][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 1
[ 18251][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 18251][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 18252][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 18252][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 18253][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished

--------------------------------
Device on endpoint 10, short address: 0x697c
[ 18275][I][ZigbeeThermostat.cpp:377] getTemperatureSettings(): Sending 'read sensor settings' command to endpoint 10, address 0x697c
[ 18318][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
[ 18318][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x402), attribute(0x1), type(0x29), value(232)
[ 18319][D][ZigbeeThermostat.cpp:162] zbAttributeRead(): Received min temperature: 10.00°C from endpoint 10
[ 18320][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x402), attribute(0x2), type(0x29), value(136)
[ 18320][D][ZigbeeThermostat.cpp:168] zbAttributeRead(): Received max temperature: 50.00°C from endpoint 10
[ 18321][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x402), attribute(0x3), type(0x21), value(100)
[ 18322][D][ZigbeeThermostat.cpp:174] zbAttributeRead(): Received tolerance: 1.00°C from endpoint 10
[ 18322][D][ZigbeeThermostat.cpp:177] zbAttributeRead(): All temperature config attributes processed
Temperature sensor config: min 10.00°C, max 50.00°C, tolerance 1.00°C
=========== After Setup Start ============
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   431980 B ( 421.9 KB)
  Free Bytes        :   360736 B ( 352.3 KB)
  Allocated Bytes   :    62884 B (  61.4 KB)
  Minimum Free Bytes:   360600 B ( 352.1 KB)
  Largest Free Block:   344052 B ( 336.0 KB)
------------------------------------------
GPIO Info:
------------------------------------------
  GPIO : BUS_TYPE[bus/unit][chan]
  --------------------------------------  
     9 : GPIO
    12 : USB_DM
    13 : USB_DP
    16 : UART_TX[0]
    17 : UART_RX[0]
============ After Setup End =============
Loop temperature info: 0.00°C (-25 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 18394][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Device Authorized (0x2f), status: ESP_OK
[ 18413][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0x2e1e) is open for 180 seconds
[ 19545][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 39.70°C from endpoint 10, address 0x697c
[ 25549][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 40.70°C from endpoint 10, address 0x697c
Loop temperature info: 40.70°C (76 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
Loop temperature info: 40.70°C (76 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 42560][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 41.70°C from endpoint 10, address 0x697c
[ 46069][I][ZigbeeThermostat.cpp:448] setTemperatureReporting(): Sending 'configure temperature reporting' command
[ 46092][V][ZigbeeHandlers.cpp:216] zb_configure_report_resp_handler(): Configure report response: status(0), cluster(0x402), direction(0xff), attribute(0xffff)
[ 46096][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 41.70°C from endpoint 10, address 0x697c
Loop temperature info: 41.70°C (79 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 50066][I][ZigbeeThermostat.cpp:448] setTemperatureReporting(): Sending 'configure temperature reporting' command
[ 50089][V][ZigbeeHandlers.cpp:216] zb_configure_report_resp_handler(): Configure report response: status(0), cluster(0x402), direction(0xff), attribute(0xffff)
[ 50093][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 41.70°C from endpoint 10, address 0x697c
Loop temperature info: 41.70°C (79 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 60090][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 41.70°C from endpoint 10, address 0x697c
Loop temperature info: 41.70°C (79 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 70092][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 41.70°C from endpoint 10, address 0x697c
Loop temperature info: 41.70°C (79 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 80094][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 42.70°C from endpoint 10, address 0x697c
Loop temperature info: 42.70°C (81 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 90095][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 42.70°C from endpoint 10, address 0x697c
Loop temperature info: 42.70°C (81 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[100097][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 42.70°C from endpoint 10, address 0x697c
Loop temperature info: 42.70°C (81 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[110099][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 42.70°C from endpoint 10, address 0x697c
Loop temperature info: 42.70°C (81 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[120100][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 42.70°C from endpoint 10, address 0x697c
Loop temperature info: 42.70°C (81 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[130102][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 42.70°C from endpoint 10, address 0x697c
Loop temperature info: 42.70°C (81 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[140104][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x697c
Loop temperature info: 43.70°C (84 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[150105][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x697c
Loop temperature info: 43.70°C (84 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[160107][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x697c
Loop temperature info: 43.70°C (84 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[170109][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x697c
Loop temperature info: 43.70°C (84 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[180110][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x697c
Loop temperature info: 43.70°C (84 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[190112][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x697c) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x697c
Loop temperature info: 43.70°C (84 %)
Bound devices:
Device on endpoint 10, short address: 0x697c, ieee address: 9c:9e:6e:ff:fe:43:83:68
[198414][I][ZigbeeCore.cpp:447] esp_zb_app_signal_handler(): Network(0x2e1e) closed, devices joining not allowed.
[     0][V][ZigbeeEP.cpp:27] ZigbeeEP(): Endpoint: 1
=========== Before Setup Start ===========
Chip Info:
------------------------------------------
  Model             : ESP32-C6
  Package           : 1
  Revision          : 0.01
  Cores             : 1
  CPU Frequency     : 160 MHz
  XTAL Frequency    : 4es Bitfield : 0x00000052
  Embedded Flash    : No
  Embedded PSRAM    : No
  2.4GHz WiFi       : Yes
  Classic BT        : No
  BT Low Energy     : Yes
  IEEE 802.15.4     : Yes
------------------------------------------
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   431980 B ( 421.9 KB)
  Free Bytes        :   396332 B ( 387.0 KB)
  Allocated Bytes   :    28280 B (  27.6 KB)
  Minimum Free Bytes:   391344 B ( 382.2 KB)
  Largest Free Block:   368628 B ( 360.0 KB)
------------------------------------------
Flash Info:
------------------------------------------
  Chip Size         :  4194304 B (4 MB)
  Block Size        :    65536 B (  64.0 KB)
  Sector Size       :     4096 B (   4.0 KB)
  Page Size         :      256 B (   0.2 KB)
  Bus Speed         : 80 MHz
  Flash Frequency   : 80 MHz (source: 80 MHz, divider: 1)
  Bus Mode          : QIO
------------------------------------------
Partitions Info:
------------------------------------------
                nvs : addr: 0x00009000, size:    20.0 KB, type: DATA, subtype: NVS
            otadata : addr: 0x0000E000, size:     8.0 KB, type: DATA, subtype: OTA
               app0 : addr: 0x00010000, size:  1280.0 KB, type:  APP, subtype: OTA_0
               app1 : addr: 0x00150000, size:  1280.0 KB, type:  APP, subtype: OTA_1
             spiffs : addr: 0x00290000, size:  1384.0 KB, type: DATA, subtype: SPIFFS
         zb_storage : addr: 0x003EA000, size:    16.0 KB, type: DATA, subtype: FAT
             zb_fct : addr: 0x003EE000, size:     4.0 KB, type: DATA, subtype: FAT
             rcp_fw : addr: 0x003EF000, size:     4.0 KB, type: DATA, subtype: SPIFFS
           coredump : addr: 0x003F0000, size:    64.0 KB, type: DATA, subtype: COREDUMP
------------------------------------------
Software Info:
------------------------------------------
  Compile Date/Time : Feb 19 2026 18:53:02
  Compile Host OS   : windows
  ESP-IDF Version   : v5.5.2-729-g87912cd291
  Arduino Version   : 3.3.7
------------------------------------------
Board Info:
------------------------------------------
  Arduino Board     : ESP32C6_DEV
  Arduino Variant   : esp32c6
  Arduino FQBN      : esp32:esp32:esp32c6:UploadSpeed=921600,CDCOnBoot=cdc,CPUFreq=160,FlashFreq=80,FlashMode=qio,FlashSize=4M,PartitionScheme=zigbee_zczr,DebugLevel=verbose,EraseFlash=all,JTAGAdapter=default,ZigbeeMode=zczr
============ Before Setup End ============
[  1584][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RX (2) cleared
[  1584][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_TX (3) cleared
[  1585][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_CTS (4) cleared
[  1585][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RTS (5) cleared
[  1586][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 17 successfully set to type UART_RX (2) with bus 0x40810f6c
[  1586][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_RX (2) successfully set to 0x4200a446
[  1587][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 16 successfully set to type UART_TX (3) with bus 0x40810f6c
[  1588][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_TX (3) successfully set to 0x4200a30c
[  1588][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 12 already has type USB_DM (38) with bus 0x40814290
[  1589][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 13 already has type USB_DP (39) with bus 0x40814290
[  1589][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type GPIO (1) successfully set to 0x420076fe
[  1590][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 9 successfully set to type GPIO (1) with bus 0xa
[  1590][D][ZigbeeCore.cpp:116] addEndpoint(): Endpoint: 1, Device ID: 0x0301
[  1591][D][ZigbeeCore.cpp:164] zigbeeInit(): Initialize Zigbee stack
[  1646][D][ZigbeeCore.cpp:171] zigbeeInit(): Register all Zigbee EPs in list
[  1648][I][ZigbeeCore.cpp:179] zigbeeInit(): List of registered Zigbee EPs:
[  1648][I][ZigbeeCore.cpp:181] zigbeeInit(): Device type: Thermostat Device, Endpoint: 1, Device ID: 0x0301
[  1802][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Config Ready (0x17), status: ESP_FAIL
[  1803][I][ZigbeeCore.cpp:275] esp_zb_app_signal_handler(): Zigbee stack initialized
[  1803][D][ZigbeeCore.cpp:276] esp_zb_app_signal_handler(): Zigbee channel mask: 0x07fff800
[  1805][I][ZigbeeCore.cpp:282] esp_zb_app_signal_handler(): Device started up in  factory-reset mode
[  1805][I][ZigbeeCore.cpp:286] esp_zb_app_signal_handler(): Start network formation
[  6257][I][ZigbeeCore.cpp:447] esp_zb_app_signal_handler(): Network(0xfe6d) closed, devices joining not allowed.
[  6258][I][ZigbeeCore.cpp:319] esp_zb_app_signal_handler(): Formed network successfully (Extended PAN ID: 54:32:04:ff:fe:3d:dc:64, PAN ID: 0xfe6d, Channel:14, Short Address: 0x0000)
[  6726][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0xfe6d) is open for 180 seconds
[  6727][I][ZigbeeCore.cpp:335] esp_zb_app_signal_handler(): Network steering started
Waiting for Temperature sensor to bound to the thermostat
.........[ 10750][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NWK Device Associated (0x12), status: ESP_OK
[ 10773][I][ZigbeeCore.cpp:360] esp_zb_app_signal_handler(): New device commissioned or rejoined (short: 0x65f7)
[ 10774][V][ZigbeeCore.cpp:364] esp_zb_app_signal_handler(): Device capabilities: 0x8c
[ 10774][D][ZigbeeCore.cpp:378] esp_zb_app_signal_handler(): Checking endpoint 1
[ 10774][D][ZigbeeCore.cpp:393] esp_zb_app_signal_handler(): Device not bound to endpoint 1 and it is free to bound!
[ 10775][D][ZigbeeCore.cpp:395] esp_zb_app_signal_handler(): Endpoint 1 is searching for device
[ 10801][D][ZigbeeThermostat.cpp:80] findCbWrapper(): findCbWrapper on EP 1
[ 10802][I][ZigbeeThermostat.cpp:88] findCb(): Found temperature sensor
[ 10802][D][ZigbeeThermostat.cpp:96] findCb(): Temperature sensor found: short address(0x65f7), endpoint(10)
[ 10802][I][ZigbeeThermostat.cpp:107] findCb(): Request temperature sensor to bind us
[ 10803][I][ZigbeeThermostat.cpp:110] findCb(): Request humidity sensor to bind us
[ 10803][I][ZigbeeThermostat.cpp:124] findCb(): Try to bind Humidity Measurement
[ 10804][I][ZigbeeThermostat.cpp:130] findCb(): Try to bind Temperature Measurement
[ 10806][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[ 10807][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[ 10814][D][ZigbeeThermostat.cpp:72] bindCbWrapper(): bindCbWrapper on EP 1
[ 10814][I][ZigbeeThermostat.cpp:56] bindCb(): Bound successfully!
[ 10814][I][ZigbeeThermostat.cpp:59] bindCb(): The sensor originating from address(0x65f7) on endpoint(10)
[ 10815][D][ZigbeeThermostat.cpp:60] bindCb(): Sensor bound to thermostat on EP 1
[ 10817][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[ 10817][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 2, index 0, count 2
[ 10818][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 1, dst_endp 10, cluster_id 0x0405, dst_addr_mode 3
[ 10818][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 1: src_endp 1, dst_endp 10, cluster_id 0x0402, dst_addr_mode 3
[ 10819][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 2
[ 10819][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 1
[ 10820][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 10820][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 10821][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 10821][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 10822][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
[ 10822][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[ 10822][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 2, index 0, count 2
[ 10823][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 1, dst_endp 10, cluster_id 0x0405, dst_addr_mode 3
[ 10824][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 1: src_endp 1, dst_endp 10, cluster_id 0x0402, dst_addr_mode 3
[ 10824][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 2
[ 10825][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 1
[ 10825][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 10826][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 10826][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 10826][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 10827][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
[ 10882][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Device Authorized (0x2f), status: ESP_OK
[ 10902][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0xfe6d) is open for 180 seconds
[ 11060][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x65f7

--------------------------------
Device on endpoint 10, short address: 0x65f7
[ 11228][I][ZigbeeThermostat.cpp:377] getTemperatureSettings(): Sending 'read sensor settings' command to endpoint 10, address 0x65f7
[ 11252][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
[ 11253][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x402), attribute(0x1), type(0x29), value(232)
[ 11253][D][ZigbeeThermostat.cpp:162] zbAttributeRead(): Received min temperature: 10.00°C from endpoint 10
[ 11254][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x402), attribute(0x2), type(0x29), value(136)
[ 11254][D][ZigbeeThermostat.cpp:168] zbAttributeRead(): Received max temperature: 50.00°C from endpoint 10
[ 11255][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x402), attribute(0x3), type(0x21), value(100)
[ 11256][D][ZigbeeThermostat.cpp:174] zbAttributeRead(): Received tolerance: 1.00°C from endpoint 10
[ 11256][D][ZigbeeThermostat.cpp:177] zbAttributeRead(): All temperature config attributes processed
Temperature sensor config: min 10.00°C, max 50.00°C, tolerance 1.00°C
=========== After Setup Start ============
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   431980 B ( 421.9 KB)
  Free Bytes        :   360924 B ( 352.5 KB)
  Allocated Bytes   :    62712 B (  61.2 KB)
  Minimum Free Bytes:   360728 B ( 352.3 KB)
  Largest Free Block:   344052 B ( 336.0 KB)
------------------------------------------
GPIO Info:
------------------------------------------
  GPIO : BUS_TYPE[bus/unit][chan]
  --------------------------------------  
     9 : GPIO
    12 : USB_DM
    13 : USB_DP
    16 : UART_TX[0]
    17 : UART_RX[0]
============ After Setup End =============
Loop temperature info: 43.70°C (84 %)
Bound devices:
Device on endpoint 10, short address: 0x65f7, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 12070][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 42.70°C from endpoint 10, address 0x65f7
[ 13068][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x65f7
[ 14070][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 42.70°C from endpoint 10, address 0x65f7
[ 15072][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x65f7
[ 19067][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 42.70°C from endpoint 10, address 0x65f7
[ 20069][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x65f7
[ 21071][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 42.70°C from endpoint 10, address 0x65f7
Loop temperature info: 42.70°C (81 %)
Bound devices:
Device on endpoint 10, short address: 0x65f7, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 22073][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x65f7
[ 31371][I][ZigbeeThermostat.cpp:448] setTemperatureReporting(): Sending 'configure temperature reporting' command
Loop temperature info: 43.70°C (84 %)
Bound devices:
Device on endpoint 10, short address: 0x65f7, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 31394][V][ZigbeeHandlers.cpp:216] zb_configure_report_resp_handler(): Configure report response: status(0), cluster(0x402), direction(0xff), attribute(0xffff)
[ 31398][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x65f7
[ 41395][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x65f7
[ 41597][I][ZigbeeThermostat.cpp:448] setTemperatureReporting(): Sending 'configure temperature reporting' command
Loop temperature info: 43.70°C (84 %)
Bound devices:
Device on endpoint 10, short address: 0x65f7, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 41620][V][ZigbeeHandlers.cpp:216] zb_configure_report_resp_handler(): Configure report response: status(0), cluster(0x402), direction(0xff), attribute(0xffff)
[ 41624][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 43.70°C from endpoint 10, address 0x65f7
[ 44082][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 40.70°C from endpoint 10, address 0x65f7
[ 46084][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 38.70°C from endpoint 10, address 0x65f7
[ 49086][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 36.70°C from endpoint 10, address 0x65f7
[ 51087][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x65f7) src endpoint(10) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 38.70°C from endpoint 10, address 0x65f7
Loop temperature info: 38.70°C (71 %)
Bound devices:
Device on endpoint 10, short address: 0x65f7, ieee address: 9c:9e:6e:ff:fe:43:83:68
