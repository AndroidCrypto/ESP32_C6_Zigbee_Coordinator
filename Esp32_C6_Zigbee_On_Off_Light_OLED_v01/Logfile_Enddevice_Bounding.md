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
  Total Size        :   430860 B ( 420.8 KB)
  Free Bytes        :   395416 B ( 386.1 KB)
  Allocated Bytes   :    28252 B (  27.6 KB)
  Minimum Free Bytes:   390604 B ( 381.4 KB)
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
             spiffs : addr: 0x00290000, size:  1388.0 KB, type: DATA, subtype: SPIFFS
         zb_storage : addr: 0x003EB000, size:    16.0 KB, type: DATA, subtype: FAT
             zb_fct : addr: 0x003EF000, size:     4.0 KB, type: DATA, subtype: FAT
           coredump : addr: 0x003F0000, size:    64.0 KB, type: DATA, subtype: COREDUMP
------------------------------------------
Software Info:
------------------------------------------
  Compile Date/Time : Mar 28 2026 16:11:20
  Compile Host OS   : windows
  ESP-IDF Version   : v5.5.2-729-g87912cd291
  Arduino Version   : 3.3.7
------------------------------------------
Board Info:
------------------------------------------
  Arduino Board     : ESP32C6_DEV
  Arduino Variant   : esp32c6
  Arduino FQBN      : esp32:esp32:esp32c6:UploadSpeed=921600,CDCOnBoot=cdc,CPUFreq=160,FlashFreq=80,FlashMode=qio,FlashSize=4M,PartitionScheme=zigbee,DebugLevel=verbose,EraseFlash=all,JTAGAdapter=default,ZigbeeMode=ed_debug
============ Before Setup End ============
[   808][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RX (2) cleared
[   809][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_TX (3) cleared
[   809][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_CTS (4) cleared
[   810][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RTS (5) cleared
[   810][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 17 successfully set to type UART_RX (2) with bus 0x408114d4
[   811][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_RX (2) successfully set to 0x4200fd70
[   812][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 16 successfully set to type UART_TX (3) with bus 0x408114d4
[   812][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_TX (3) successfully set to 0x4200fc36
[   813][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 12 already has type USB_DM (38) with bus 0x40814a84
[   813][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 13 already has type USB_DP (39) with bus 0x40814a84
ESP32 C6 Zigbee On Off Light example with OLED V01
[  1313][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type GPIO (1) successfully set to 0x4200abee
[  1314][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 15 successfully set to type GPIO (1) with bus 0x10
[  1565][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type GPIO (1) successfully set to 0x4200abee
[  1566][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 9 successfully set to type GPIO (1) with bus 0xa
Adding ZigbeeLight endpoint to Zigbee Core
[  1567][D][ZigbeeCore.cpp:116] addEndpoint(): Endpoint: 10, Device ID: 0x0100
[  1567][D][ZigbeeCore.cpp:164] zigbeeInit(): Initialize Zigbee stack
[  1624][D][ZigbeeCore.cpp:171] zigbeeInit(): Register all Zigbee EPs in list
[  1626][I][ZigbeeCore.cpp:179] zigbeeInit(): List of registered Zigbee EPs:
[  1626][I][ZigbeeCore.cpp:181] zigbeeInit(): Device type: On/Off Light Device, Endpoint: 10, Device ID: 0x0100
[  1630][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Config Ready (0x17), status: ESP_FAIL
[  1631][I][ZigbeeCore.cpp:275] esp_zb_app_signal_handler(): Zigbee stack initialized
[  1631][D][ZigbeeCore.cpp:276] esp_zb_app_signal_handler(): Zigbee channel mask: 0x07fff800
[  1634][I][ZigbeeCore.cpp:282] esp_zb_app_signal_handler(): Device started up in  factory-reset mode
[  1635][I][ZigbeeCore.cpp:289] esp_zb_app_signal_handler(): Start network steering
Connecting to network
....................ZB_TRACE_LOG[0]: zdo/zdo_commissioning.c:212    Can't find PAN to join to! param 25
[  3862][I][ZigbeeCore.cpp:352] esp_zb_app_signal_handler(): Network steering was not successful (status: ESP_FAIL)
.................................ZB_TRACE_LOG[0]: zdo/zdo_commissioning.c:212    Can't find PAN to join to! param 25
[  7091][I][ZigbeeCore.cpp:352] esp_zb_app_signal_handler(): Network steering was not successful (status: ESP_FAIL)
.....................................[ 10857][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 10858][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 11
[ 10859][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xa621, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 183, rx_time: 0
[ 10868][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 10869][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8002, asdu_length: 17
[ 10869][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xa621, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 183, rx_time: 0
.[ 10963][I][ZigbeeCore.cpp:343] esp_zb_app_signal_handler(): Joined network successfully (Extended PAN ID: 58:8c:81:ff:fe:30:3e:20, PAN ID: 0xefd1, Channel:25, Short Address: 0xa621)
[ 10965][V][ZigbeeCore.cpp:775] setNVRAMChannelMask(): Channel mask set to 0x02000000

[ 11235][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 11235][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 5, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0000, asdu_length: 5
[ 11236][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xa621, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 183, rx_time: 0
=========== After Setup Start ============
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   430860 B ( 420.8 KB)
  Free Bytes        :   362364 B ( 353.9 KB)
  Allocated Bytes   :    60192 B (  58.8 KB)
  Minimum Free Bytes:   362364 B ( 353.9 KB)
  Largest Free Block:   344052 B ( 336.0 KB)
------------------------------------------
GPIO Info:
------------------------------------------
  GPIO : BUS_TYPE[bus/unit][chan]
  --------------------------------------  
     9 : GPIO
    12 : USB_DM
    13 : USB_DP
    15 : GPIO
    16 : UART_TX[0]
    17 : UART_RX[0]
============ After Setup End =============
[ 11264][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 11265][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 5, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0000, asdu_length: 5
[ 11266][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xa621, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 188, rx_time: 0
[ 11294][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 11294][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 5, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 5
[ 11295][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xa621, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 178, rx_time: 0
[ 14293][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14294][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 5, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 5
[ 14295][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xa621, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 188, rx_time: 0
[ 17293][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17294][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 5, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 5
[ 17295][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xa621, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 183, rx_time: 0
[ 20293][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 20294][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 5, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 5
[ 20294][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xa621, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 183, rx_time: 0
[ 23293][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 23294][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 5, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 5
[ 23295][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xa621, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 188, rx_time: 0

