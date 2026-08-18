=========== Before Setup Start ===========
Chip Info:
------------------------------------------
  Model             : ESP32-C6
------------------------------------------
Software Info:
------------------------------------------
  Compile Date/Time : Aug 18 2026 11:20:39
  Compile Host OS   : macosx
  ESP-IDF Version   : v5.5.5
  Arduino Version   : 3.3.11
------------------------------------------
Board Info:
------------------------------------------
  Arduino Board     : ESP32C6_DEV
  Arduino Variant   : esp32c6
  Arduino FQBN      : esp32:esp32:esp32c6:UploadSpeed=921600,CDCOnBoot=cdc,CPUFreq=160,FlashFreq=80,FlashMode=qio,FlashSize=4M,PartitionScheme=zigbee,DebugLevel=debug,EraseFlash=none,JTAGAdapter=default,ZigbeeMode=ed_debug
============ Before Setup End ============
ESP32 C6 Zigbee Light End Device Time Cluster with OLED V04
The SSD1306 OLED display is set up
Adding ZigbeeLight endpoint to Zigbee Core
[  1632][D][ZigbeeCore.cpp:127] addEndpoint(): Endpoint: 10, Device ID: 0x0100
[  1632][D][ZigbeeCore.cpp:175] zigbeeInit(): Initialize Zigbee stack
[  1680][D][ZigbeeCore.cpp:182] zigbeeInit(): Register all Zigbee EPs in list
[  1682][I][ZigbeeCore.cpp:190] zigbeeInit(): List of registered Zigbee EPs:
[  1682][I][ZigbeeCore.cpp:192] zigbeeInit(): Device type: On/Off Light Device, Endpoint: 10, Device ID: 0x0100
[  1696][I][ZigbeeCore.cpp:290] esp_zb_app_signal_handler(): Zigbee stack initialized
[  1697][D][ZigbeeCore.cpp:291] esp_zb_app_signal_handler(): Zigbee channel mask: 0x01000000
[  1965][I][ZigbeeCore.cpp:297] esp_zb_app_signal_handler(): Device started up in non factory-reset mode
[  1965][I][ZigbeeCore.cpp:310] esp_zb_app_signal_handler(): Device rebooted
[  1967][D][ZigbeeCore.cpp:778] searchBindings(): Requesting binding table for address 0xef0b
[  1968][D][ZigbeeCore.cpp:488] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[  1969][D][ZigbeeCore.cpp:489] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 1, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[  1970][D][ZigbeeCore.cpp:493] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x00ef, src_short_addr: 0xef0b, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[  1971][D][ZigbeeCore.cpp:488] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[  1972][D][ZigbeeCore.cpp:489] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 1, src_addr_mode: 0, cluster_id: 0x8033, asdu_length: 5
[  1973][D][ZigbeeCore.cpp:493] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x00ef, src_short_addr: 0xef0b, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[  1974][D][ZigbeeCore.cpp:586] bindingTableCb(): Binding table callback for address 0xef0b with status 0
[  1975][D][ZigbeeCore.cpp:590] bindingTableCb(): Binding table info: total 0, index 0, count 0
[  1976][D][ZigbeeCore.cpp:593] bindingTableCb(): No binding table entries found
[  1976][D][ZigbeeCore.cpp:596] bindingTableCb(): Clearing bound devices for EP 10
Connecting to network

Connected to Coordinator: wait for actions
-----------------------
###################################
[ 63410][D][ZigbeeCore.cpp:488] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 63411][D][ZigbeeCore.cpp:489] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 11
[ 63412][D][ZigbeeCore.cpp:493] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xef0b, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 255, rx_time: 0
[ 63415][D][ZigbeeEP.cpp:562] setTime(): Setting ZCL UTCTime to 840360741 s since 2000-01-01 UTC
[ 63439][D][ZigbeeCore.cpp:488] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 63439][D][ZigbeeCore.cpp:489] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 11
[ 63440][D][ZigbeeCore.cpp:493] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xef0b, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 255, rx_time: 0
[ 63444][D][ZigbeeEP.cpp:573] setTimezone(): Setting timezone to 7200
TimeCluster time 1082651216 zone 7200
###################################
System-RTC was synchronized with Zigbee-Time Cluster.
Local time:  18.08.2026 11:32:21
UTC time:    18.08.2026 09:32:21
Offset:      7200 seconds
###################################
