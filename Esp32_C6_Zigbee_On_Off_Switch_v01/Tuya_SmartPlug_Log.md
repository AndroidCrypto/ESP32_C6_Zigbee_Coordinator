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
  Total Size        :   430476 B ( 420.4 KB)
  Free Bytes        :   394896 B ( 385.6 KB)
  Allocated Bytes   :    28340 B (  27.7 KB)
  Minimum Free Bytes:   390084 B ( 380.9 KB)
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
[   754][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RX (2) cleared
[   754][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_TX (3) cleared
[   755][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_CTS (4) cleared
[   755][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RTS (5) cleared
[   756][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 17 successfully set to type UART_RX (2) with bus 0x40811034
[   757][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_RX (2) successfully set to 0x42009b14
[   757][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 16 successfully set to type UART_TX (3) with bus 0x40811034
[   758][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_TX (3) successfully set to 0x420099da
[   758][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 12 already has type USB_DM (38) with bus 0x408142d0
[   759][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 13 already has type USB_DP (39) with bus 0x408142d0
ESP32 C6 Zigbee On Off Switch Orignal V01
Adding ZigbeeSwitch endpoint to Zigbee Core
[  1259][D][ZigbeeCore.cpp:116] addEndpoint(): Endpoint: 5, Device ID: 0x0000
[  1259][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type GPIO (1) successfully set to 0x42006c7c
[  1260][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 9 successfully set to type GPIO (1) with bus 0xa
[  1261][D][ZigbeeCore.cpp:164] zigbeeInit(): Initialize Zigbee stack
[  1347][D][ZigbeeCore.cpp:171] zigbeeInit(): Register all Zigbee EPs in list
[  1349][I][ZigbeeCore.cpp:179] zigbeeInit(): List of registered Zigbee EPs:
[  1349][I][ZigbeeCore.cpp:181] zigbeeInit(): Device type: General On/Off switch, Endpoint: 5, Device ID: 0x0000
[  1355][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Config Ready (0x17), status: ESP_FAIL
[  1356][I][ZigbeeCore.cpp:275] esp_zb_app_signal_handler(): Zigbee stack initialized
[  1356][D][ZigbeeCore.cpp:276] esp_zb_app_signal_handler(): Zigbee channel mask: 0x07fff800
[  1361][I][ZigbeeCore.cpp:447] esp_zb_app_signal_handler(): Network(0xb526) closed, devices joining not allowed.
[  1363][I][ZigbeeCore.cpp:282] esp_zb_app_signal_handler(): Device started up in non factory-reset mode
[  1364][I][ZigbeeCore.cpp:295] esp_zb_app_signal_handler(): Device rebooted
[  1364][I][ZigbeeCore.cpp:299] esp_zb_app_signal_handler(): Opening network for joining for 180 seconds
[  1364][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[  1366][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[  1367][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[  1368][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[  1369][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[  1370][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8033, asdu_length: 5
[  1371][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[  1372][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[  1372][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 0, index 0, count 0
[  1373][D][ZigbeeCore.cpp:575] bindingTableCb(): No binding table entries found
[  1373][D][ZigbeeCore.cpp:578] bindingTableCb(): Clearing bound devices for EP 5
Waiting for Light to bound to the switch
.[  1833][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0xb526) is open for 180 seconds
............................[ 15643][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NWK Device Associated (0x12), status: ESP_OK
[ 15706][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 15706][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 14, cluster_id: 0x0013, asdu_length: 12
[ 15707][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xfffd, src_short_addr: 0xac98, profile_id: 0x0000, security_status: 0, lqi: 25, rx_time: 0
[ 15708][I][ZigbeeCore.cpp:360] esp_zb_app_signal_handler(): New device commissioned or rejoined (short: 0xac98)
[ 15709][V][ZigbeeCore.cpp:364] esp_zb_app_signal_handler(): Device capabilities: 0x8e
[ 15709][D][ZigbeeCore.cpp:378] esp_zb_app_signal_handler(): Checking endpoint 5
[ 15710][D][ZigbeeCore.cpp:393] esp_zb_app_signal_handler(): Device not bound to endpoint 5 and it is free to bound!
[ 15711][D][ZigbeeCore.cpp:395] esp_zb_app_signal_handler(): Endpoint 5 is searching for device
[ 15793][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 15794][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8006, asdu_length: 6
[ 15795][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0000, security_status: 0, lqi: 25, rx_time: 0
[ 15796][D][ZigbeeSwitch.cpp:62] findCbWrapper(): findCbWrapper on EP 5
[ 15796][D][ZigbeeSwitch.cpp:70] findCb(): Found light endpoint
[ 15796][D][ZigbeeSwitch.cpp:77] findCb(): Light found: short address(0xac98), endpoint(1)
[ 15797][V][ZigbeeSwitch.cpp:86] findCb(): Try to bind On/Off
[ 15797][D][ZigbeeSwitch.cpp:90] findCb(): Find callback on EP 5
[ 15800][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 15800][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0021, asdu_length: 22
[ 15801][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 15802][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[ 15806][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 15807][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[ 15807][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 15809][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 15809][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8021, asdu_length: 2
[ 15810][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 15811][D][ZigbeeSwitch.cpp:53] bindCbWrapper(): bindCbWrapper on EP 5
[ 15812][I][ZigbeeSwitch.cpp:37] bindCb(): Bound successfully!
[ 15812][I][ZigbeeSwitch.cpp:40] bindCb(): The light originating from address(0xac98) on endpoint(1)
[ 15812][D][ZigbeeSwitch.cpp:41] bindCb(): Light bound to a switch on EP 5
[ 15813][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 15814][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8033, asdu_length: 26
[ 15815][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 15816][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[ 15816][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 1, index 0, count 1
[ 15817][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 5, dst_endp 1, cluster_id 0x0006, dst_addr_mode 3
[ 15817][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 1
[ 15818][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 5
[ 15818][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 5
[ 15819][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 15819][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
Device on endpoint 1, short address: 0xac98
IEEE Address: 0C:43:14:FF:FE:52:AE:17
[ 15906][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 15907][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0000, asdu_length: 24
[ 15908][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 40, rx_time: 0
[ 15909][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x0)
[ 15910][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x0), attribute(0x4), type(0x42), value(16)
[ 15910][I][ZigbeeEP.cpp:320] zbReadBasicCluster(): Peer Manufacturer is "_TZ3000_5f43h46b"
[ 15954][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 15954][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0000, asdu_length: 14
[ 15955][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 45, rx_time: 0
[ 15957][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x0)
[ 15957][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x0), attribute(0x5), type(0x42), value(6)
[ 15958][I][ZigbeeEP.cpp:333] zbReadBasicCluster(): Peer Model is "TS011F"
Light manufacturer: _TZ3000_5f43h46b
Light model: TS011F

Bound devices:
Device on endpoint 1, short address: 0xac98, ieee address: 0c:43:14:ff:fe:52:ae:17
=========== After Setup Start ============
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   430476 B ( 420.4 KB)
  Free Bytes        :   355624 B ( 347.3 KB)
  Allocated Bytes   :    66708 B (  65.1 KB)
  Minimum Free Bytes:   355492 B ( 347.2 KB)
  Largest Free Block:   335860 B ( 328.0 KB)
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
[ 15998][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 15999][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 15999][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 45, rx_time: 0
[ 16001][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 16002][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(1)
Light state changed to 1
[ 16147][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16147][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0002, asdu_length: 3
[ 16148][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0000, security_status: 0, lqi: 51, rx_time: 0
[ 16251][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Device Authorized (0x2f), status: ESP_OK
[ 16335][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16336][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 28, cluster_id: 0x0036, asdu_length: 3
[ 16336][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xfffc, src_short_addr: 0xac98, profile_id: 0x0000, security_status: 0, lqi: 51, rx_time: 0
[ 16338][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0xb526) is open for 180 seconds
[ 16787][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16788][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 29, cluster_id: 0x000a, asdu_length: 5
[ 16789][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 61, rx_time: 0
[ 17992][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17992][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 17993][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 56, rx_time: 0
[ 17994][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 17995][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(1)
[ 19994][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 19994][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 19995][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 66, rx_time: 0
[ 19997][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 19997][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(1)
[ 21992][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 21993][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 21993][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 45, rx_time: 0
[ 21995][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 21995][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(1)
[ 22412][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 22413][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 17, cluster_id: 0x0006, asdu_length: 7
[ 22414][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 40, rx_time: 0
[ 22419][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 22419][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 17, cluster_id: 0xe001, asdu_length: 7
[ 22420][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 45, rx_time: 0
[ 22425][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 22425][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 18, cluster_id: 0xe001, asdu_length: 7
[ 22426][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 51, rx_time: 0
[ 23992][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 23993][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 23994][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 51, rx_time: 0
[ 23995][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 23996][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(1)
[ 25994][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 25994][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 25995][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 56, rx_time: 0
[ 25996][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 25997][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(1)
[ 26370][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NLME Status Indication (0x32), status: ESP_OK
Bound devices:
Device on endpoint 1, short address: 0xac98, ieee address: 0c:43:14:ff:fe:52:ae:17
[ 27994][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 27994][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 27995][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 15, rx_time: 0
[ 27997][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 27997][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(1)
Toggling light
[ 28000][V][ZigbeeSwitch.cpp:119] lightToggle(): Sending 'light toggle' command
[ 28045][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 28045][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 23, cluster_id: 0x0006, asdu_length: 7
[ 28046][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 30, rx_time: 0
[ 28050][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 28051][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 24, cluster_id: 0x0006, asdu_length: 5
[ 28051][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 40, rx_time: 0
[ 28052][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0xac98), src_endpoint(1) to dst_endpoint(5), cluster(0x6) with status 0x0
[ 28053][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 5
[ 28054][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 28054][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 2
[ 29993][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 29993][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 29994][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 25, rx_time: 0
[ 29996][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 29996][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
Light state changed to 0
[ 31994][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 31995][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 31996][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 20, rx_time: 0
[ 31997][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 31998][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
Toggling light
[ 33133][V][ZigbeeSwitch.cpp:119] lightToggle(): Sending 'light toggle' command
[ 33173][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 33173][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 15, cluster_id: 0x0006, asdu_length: 7
[ 33174][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 25, rx_time: 0
[ 33179][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 33179][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 16, cluster_id: 0x0006, asdu_length: 5
[ 33180][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 30, rx_time: 0
[ 33181][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0xac98), src_endpoint(1) to dst_endpoint(5), cluster(0x6) with status 0x0
[ 33182][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 5
[ 33182][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 33183][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 2
[ 33995][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 33996][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 33996][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 20, rx_time: 0
[ 33998][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 33998][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(1)
Light state changed to 1
[ 35998][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 35999][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 35999][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 20, rx_time: 0
[ 36001][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 36001][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(1)
Toggling light
[ 36948][V][ZigbeeSwitch.cpp:119] lightToggle(): Sending 'light toggle' command
[ 36987][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 36987][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 19, cluster_id: 0x0006, asdu_length: 7
[ 36988][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 20, rx_time: 0
[ 36993][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 36993][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 5
[ 36994][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 20, rx_time: 0
[ 36995][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0xac98), src_endpoint(1) to dst_endpoint(5), cluster(0x6) with status 0x0
[ 36996][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 5
[ 36997][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 36997][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 2
Bound devices:
Device on endpoint 1, short address: 0xac98, ieee address: 0c:43:14:ff:fe:52:ae:17
[ 38001][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 38002][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 38002][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 66, rx_time: 0
[ 38004][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 38004][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
Light state changed to 0
[ 39999][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 39999][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 40000][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 66, rx_time: 0
[ 40002][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 40002][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
[ 42000][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 42000][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 42001][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac98, profile_id: 0x0104, security_status: 0, lqi: 66, rx_time: 0
[ 42002][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xac98) src endpoint(1) to dst endpoint(5) cluster(0x6)
[ 42003][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
