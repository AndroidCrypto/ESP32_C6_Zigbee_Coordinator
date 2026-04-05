=========== Before Setup Start ===========
Chip Info:
------------------------------------------
  Model             : ESP32-C6
  Package           : 1
  Revision          : 0.01
  Cores             : 1
  CPU Frequency     : 160 MHz
  XTAL Frequency    : 40 MHz
  Features Bitfield : 0x00000052
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
  Free Bytes        :   396140 B ( 386.9 KB)
  Allocated Bytes   :    28440 B (  27.8 KB)
  Minimum Free Bytes:   391328 B ( 382.2 KB)
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
[  1108][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RX (2) cleared
[  1108][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_TX (3) cleared
[  1109][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_CTS (4) cleared
[  1109][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RTS (5) cleared
[  1110][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 17 successfully set to type UART_RX (2) with bus 0x40810f6c
[  1110][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_RX (2) successfully set to 0x4200a446
[  1111][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 16 successfully set to type UART_TX (3) with bus 0x40810f6c
[  1112][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_TX (3) successfully set to 0x4200a30c
[  1112][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 12 already has type USB_DM (38) with bus 0x40814290
[  1113][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 13 already has type USB_DP (39) with bus 0x40814290
[  1113][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type GPIO (1) successfully set to 0x420076fe
[  1114][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 9 successfully set to type GPIO (1) with bus 0xa
[  1115][D][ZigbeeCore.cpp:116] addEndpoint(): Endpoint: 1, Device ID: 0x0301
[  1115][D][ZigbeeCore.cpp:164] zigbeeInit(): Initialize Zigbee stack
[  1169][D][ZigbeeCore.cpp:171] zigbeeInit(): Register all Zigbee EPs in list
[  1171][I][ZigbeeCore.cpp:179] zigbeeInit(): List of registered Zigbee EPs:
[  1172][I][ZigbeeCore.cpp:181] zigbeeInit(): Device type: Thermostat Device, Endpoint: 1, Device ID: 0x0301
[  1179][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Config Ready (0x17), status: ESP_FAIL
[  1180][I][ZigbeeCore.cpp:275] esp_zb_app_signal_handler(): Zigbee stack initialized
[  1180][D][ZigbeeCore.cpp:276] esp_zb_app_signal_handler(): Zigbee channel mask: 0x07fff800
[  1184][I][ZigbeeCore.cpp:447] esp_zb_app_signal_handler(): Network(0xfe6d) closed, devices joining not allowed.
[  1185][I][ZigbeeCore.cpp:282] esp_zb_app_signal_handler(): Device started up in non factory-reset mode
[  1186][I][ZigbeeCore.cpp:295] esp_zb_app_signal_handler(): Device rebooted
[  1186][I][ZigbeeCore.cpp:299] esp_zb_app_signal_handler(): Opening network for joining for 180 seconds
[  1187][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[  1188][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[  1189][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 2, index 0, count 2
[  1190][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 1, dst_endp 10, cluster_id 0x0405, dst_addr_mode 3
[  1190][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 1: src_endp 1, dst_endp 10, cluster_id 0x0402, dst_addr_mode 3
[  1191][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 2
[  1191][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 1
[  1192][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[  1192][D][ZigbeeCore.cpp:734] bindingTableCb(): Device bound to EP 1 -> device endpoint: 10, ieee addr: 9C:9E:6E:FF:FE:43:83:68
[  1193][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[  1193][D][ZigbeeCore.cpp:734] bindingTableCb(): Device bound to EP 1 -> device endpoint: 10, ieee addr: 9C:9E:6E:FF:FE:43:83:68
[  1194][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
Waiting for Temperature sensor to bound to the thermostat

--------------------------------
Device on endpoint 10, IEEE Address: 9C:9E:6E:FF:FE:43:83:68
[  1195][I][ZigbeeThermostat.cpp:408] getTemperatureSettings(): Sending 'read sensor settings' command to endpoint 10, ieee address 9c:9e:6e:ff:fe:43:83:68
[  1217][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NLME Status Indication (0x32), status: ESP_OK
[  1654][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0xfe6d) is open for 180 seconds
[  4217][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NLME Status Indication (0x32), status: ESP_OK
[  7218][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NLME Status Indication (0x32), status: ESP_OK
[ 10219][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NLME Status Indication (0x32), status: ESP_OK
[ 11198][E][ZigbeeThermostat.cpp:418] getTemperatureSettings(): Error while reading attributes
--------------------------------
Device on endpoint 10, IEEE Address: 9C:9E:6E:FF:FE:43:83:68
[ 11199][I][ZigbeeThermostat.cpp:408] getTemperatureSettings(): Sending 'read sensor settings' command to endpoint 10, ieee address 9c:9e:6e:ff:fe:43:83:68
[ 11220][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NLME Status Indication (0x32), status: ESP_OK
[ 12489][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NWK Device Associated (0x12), status: ESP_OK
[ 13018][I][ZigbeeCore.cpp:360] esp_zb_app_signal_handler(): New device commissioned or rejoined (short: 0x6aed)
[ 13019][V][ZigbeeCore.cpp:364] esp_zb_app_signal_handler(): Device capabilities: 0x80
[ 13019][D][ZigbeeCore.cpp:378] esp_zb_app_signal_handler(): Checking endpoint 1
[ 13200][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Device Unavailable (0x3c), status: ESP_OK
[ 14221][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NLME Status Indication (0x32), status: ESP_OK
[ 14525][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Device Authorized (0x2f), status: ESP_OK
[ 14640][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0xfe6d) is open for 180 seconds
[ 17222][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NLME Status Indication (0x32), status: ESP_OK
[ 19660][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x6aed) src endpoint(1) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 23.10°C from endpoint 1, address 0x6aed
[ 19884][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x6aed) src endpoint(1) to dst endpoint(1) cluster(0x405)
[ 20107][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x6aed) src endpoint(1) to dst endpoint(1) cluster(0x1)
[ 20108][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x6aed) src endpoint(1) to dst endpoint(1) cluster(0x1)
[ 20223][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NLME Status Indication (0x32), status: ESP_OK
[ 21201][E][ZigbeeThermostat.cpp:418] getTemperatureSettings(): Error while reading attributes
=========== After Setup Start ============
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   431980 B ( 421.9 KB)
  Free Bytes        :   360704 B ( 352.2 KB)
  Allocated Bytes   :    62884 B (  61.4 KB)
  Minimum Free Bytes:   360512 B ( 352.1 KB)
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
Loop temperature info: 23.10°C (2147483647 %)
Bound devices:
Device on endpoint 10, short address: 0xffff, ieee address: 9c:9e:6e:ff:fe:43:83:68
Device on endpoint 10, short address: 0xffff, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 23204][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Device Unavailable (0x3c), status: ESP_OK
Loop temperature info: 23.10°C (2147483647 %)
Bound devices:
Device on endpoint 10, short address: 0xffff, ieee address: 9c:9e:6e:ff:fe:43:83:68
Device on endpoint 10, short address: 0xffff, ieee address: 9c:9e:6e:ff:fe:43:83:68
Loop temperature info: 23.10°C (2147483647 %)
Bound devices:
Device on endpoint 10, short address: 0xffff, ieee address: 9c:9e:6e:ff:fe:43:83:68
Device on endpoint 10, short address: 0xffff, ieee address: 9c:9e:6e:ff:fe:43:83:68
[ 50545][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x6aed) src endpoint(1) to dst endpoint(1) cluster(0x402)
Temperature sensor value: 23.30°C from endpoint 1, address 0x6aed
[ 50769][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x6aed) src endpoint(1) to dst endpoint(1) cluster(0x405)
[ 50994][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x6aed) src endpoint(1) to dst endpoint(1) cluster(0x1)
[ 50995][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x6aed) src endpoint(1) to dst endpoint(1) cluster(0x1)
Loop temperature info: 23.30°C (2147483647 %)
Bound devices:
Device on endpoint 10, short address: 0xffff, ieee address: 9c:9e:6e:ff:fe:43:83:68
Device on endpoint 10, short address: 0xffff, ieee address: 9c:9e:6e:ff:fe:43:83:68
Loop temperature info: 23.30°C (2147483647 %)
Bound devices:
Device on endpoint 10, short address: 0xffff, ieee address: 9c:9e:6e:ff:fe:43:83:68
Device on endpoint 10, short address: 0xffff, ieee address: 9c:9e:6e:ff:fe:43:83:68
