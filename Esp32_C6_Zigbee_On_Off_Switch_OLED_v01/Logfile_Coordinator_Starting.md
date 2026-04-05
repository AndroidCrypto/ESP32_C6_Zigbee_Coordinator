[     0][V][ZigbeeEP.cpp:27] ZigbeeEP(): Endpoint: 5
=========== Before Setup Start ===========
Chip Info:
------------------------------------------
  Model             : ESP32-C6
  Package           : 0
  Revision          : 0.02
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
  Total Size        :   426828 B ( 416.8 KB)
  Free Bytes        :   391248 B ( 382.1 KB)
  Allocated Bytes   :    28340 B (  27.7 KB)
  Minimum Free Bytes:   386436 B ( 377.4 KB)
  Largest Free Block:   368628 B ( 360.0 KB)
------------------------------------------
Flash Info:
------------------------------------------
  Chip Size         :  8388608 B (8 MB)
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
               app0 : addr: 0x00010000, size:  3328.0 KB, type:  APP, subtype: OTA_0
               app1 : addr: 0x00350000, size:  3328.0 KB, type:  APP, subtype: OTA_1
             spiffs : addr: 0x00690000, size:  1384.0 KB, type: DATA, subtype: SPIFFS
         zb_storage : addr: 0x007EA000, size:    16.0 KB, type: DATA, subtype: FAT
             zb_fct : addr: 0x007EE000, size:     4.0 KB, type: DATA, subtype: FAT
             rcp_fw : addr: 0x007EF000, size:     4.0 KB, type: DATA, subtype: SPIFFS
           coredump : addr: 0x007F0000, size:    64.0 KB, type: DATA, subtype: COREDUMP
------------------------------------------
Software Info:
------------------------------------------
  Compile Date/Time : Feb 19 2026 17:23:22
  Compile Host OS   : windows
  ESP-IDF Version   : v5.5.2-729-g87912cd291
  Arduino Version   : 3.3.7
------------------------------------------
Board Info:
------------------------------------------
  Arduino Board     : ESP32C6_DEV
  Arduino Variant   : esp32c6
  Arduino FQBN      : esp32:esp32:esp32c6:UploadSpeed=921600,CDCOnBoot=cdc,CPUFreq=160,FlashFreq=80,FlashMode=qio,FlashSize=8M,PartitionScheme=zigbee_zczr_8MB,DebugLevel=verbose,EraseFlash=all,JTAGAdapter=default,ZigbeeMode=zczr_debug
============ Before Setup End ============
[   824][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RX (2) cleared
[   824][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_TX (3) cleared
[   825][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_CTS (4) cleared
[   825][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RTS (5) cleared
[   826][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 17 successfully set to type UART_RX (2) with bus 0x408115a4
[   827][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_RX (2) successfully set to 0x420108c4
[   827][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 16 successfully set to type UART_TX (3) with bus 0x408115a4
[   828][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_TX (3) successfully set to 0x4201078a
[   828][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 12 already has type USB_DM (38) with bus 0x40814ca4
[   829][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 13 already has type USB_DP (39) with bus 0x40814ca4
ESP32 C6 Zigbee On Off Switch example with OLED V01
[  1329][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type GPIO (1) successfully set to 0x4200b5f2
[  1330][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 15 successfully set to type GPIO (1) with bus 0x10
Adding ZigbeeSwitch endpoint to Zigbee Core
[  1581][D][ZigbeeCore.cpp:116] addEndpoint(): Endpoint: 5, Device ID: 0x0000
[  1582][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type GPIO (1) successfully set to 0x4200b5f2
[  1582][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 9 successfully set to type GPIO (1) with bus 0xa
[  1583][D][ZigbeeCore.cpp:164] zigbeeInit(): Initialize Zigbee stack
[  1668][D][ZigbeeCore.cpp:171] zigbeeInit(): Register all Zigbee EPs in list
[  1669][I][ZigbeeCore.cpp:179] zigbeeInit(): List of registered Zigbee EPs:
[  1670][I][ZigbeeCore.cpp:181] zigbeeInit(): Device type: General On/Off switch, Endpoint: 5, Device ID: 0x0000
[  1675][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Config Ready (0x17), status: ESP_FAIL
[  1676][I][ZigbeeCore.cpp:275] esp_zb_app_signal_handler(): Zigbee stack initialized
[  1676][D][ZigbeeCore.cpp:276] esp_zb_app_signal_handler(): Zigbee channel mask: 0x07fff800
[  1682][I][ZigbeeCore.cpp:447] esp_zb_app_signal_handler(): Network(0x8fbd) closed, devices joining not allowed.
[  1683][I][ZigbeeCore.cpp:282] esp_zb_app_signal_handler(): Device started up in non factory-reset mode
[  1684][I][ZigbeeCore.cpp:295] esp_zb_app_signal_handler(): Device rebooted
[  1684][I][ZigbeeCore.cpp:299] esp_zb_app_signal_handler(): Opening network for joining for 180 seconds
[  1685][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[  1687][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[  1687][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[  1688][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[  1690][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[  1690][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8033, asdu_length: 5
[  1691][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[  1692][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[  1693][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 0, index 0, count 0
[  1693][D][ZigbeeCore.cpp:575] bindingTableCb(): No binding table entries found
[  1694][D][ZigbeeCore.cpp:578] bindingTableCb(): Clearing bound devices for EP 5
Waiting for Light to bound to the switch
.[  2154][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0x8fbd) is open for 180 seconds
...............
