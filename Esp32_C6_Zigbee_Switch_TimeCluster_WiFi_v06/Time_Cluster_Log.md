=========== Before Setup Start ===========
Chip Info:
------------------------------------------
  Model             : ESP32-C6
------------------------------------------
Software Info:
------------------------------------------
  Compile Date/Time : Aug 18 2026 11:20:43
  Compile Host OS   : macosx
  ESP-IDF Version   : v5.5.5
  Arduino Version   : 3.3.11
------------------------------------------
Board Info:
------------------------------------------
  Arduino Board     : ESP32C6_DEV
  Arduino Variant   : esp32c6
  Arduino FQBN      : esp32:esp32:esp32c6:UploadSpeed=921600,CDCOnBoot=cdc,CPUFreq=160,FlashFreq=80,FlashMode=qio,FlashSize=8M,PartitionScheme=zigbee_zczr_8MB,DebugLevel=debug,EraseFlash=none,JTAGAdapter=default,ZigbeeMode=zczr_debug
============ Before Setup End ============

ESP32-C6 Zigbee Switch with Time Cluster NTP Time Sync WiFi Coordinator V05
The SSD1306 OLED display is set up
[NTP] Connecting to WiFi...
....
[NTP] Successfully connected to WiFi.
[NTP] Waiting for NTP synchronization...
[NTP] Time successfully synchronized!
[NTP] Current configured local time: Tuesday, August 18 2026 11:31:27
[NTP] WiFi disconnected and RF module turned off.
Local: 18.08.26 11:31:27
UTC:   18.08.26 09:31:27
Offset:7200
Time synchronization done
[  8565][D][ZigbeeCore.cpp:127] addEndpoint(): Endpoint: 1, Device ID: 0x0000
[  8578][D][ZigbeeCore.cpp:175] zigbeeInit(): Initialize Zigbee stack
[  8581][D][ZigbeeCore.cpp:182] zigbeeInit(): Register all Zigbee EPs in list
[  8583][I][ZigbeeCore.cpp:190] zigbeeInit(): List of registered Zigbee EPs:
[  8583][I][ZigbeeCore.cpp:192] zigbeeInit(): Device type: General On/Off switch, Endpoint: 1, Device ID: 0x0000
Zigbee started successfully with the received time.
Waiting for Light to bound to the switch
[ 15093][I][ZigbeeCore.cpp:375] esp_zb_app_signal_handler(): New device commissioned or rejoined (short: 0xef0b)
[ 15093][D][ZigbeeCore.cpp:393] esp_zb_app_signal_handler(): Checking endpoint 1
[ 15094][D][ZigbeeCore.cpp:403] esp_zb_app_signal_handler(): Device already bound to endpoint 1
Local: 18.08.26 11:32:21
UTC:   18.08.26 09:32:21
###################################
[ 60001][D][ZigbeeEP.cpp:562] setTime(): Setting ZCL UTCTime to 840360741 s since 2000-01-01 UTC
[ 60002][D][ZigbeeEP.cpp:573] setTimezone(): Setting timezone to 7200
Zigbee Time Cluster updated UTC timestamp 1082651040 localOffset 7200

[ 60004][D][ZigbeeCore.cpp:488] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 60005][D][ZigbeeCore.cpp:489] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 5
[ 60006][D][ZigbeeCore.cpp:493] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 0, rx_time: 0
[ 60008][D][ZigbeeCore.cpp:488] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 60009][D][ZigbeeCore.cpp:489] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 11
[ 60010][D][ZigbeeCore.cpp:493] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 0, rx_time: 0

[ 60012][D][ZigbeeEP.cpp:573] setTimezone(): Setting timezone to 7200
Zigbee Time Cluster
local Offset in Coordinator: 7200 seconds
Local time: 18.08.2026 11:32:21
UTC time:   18.08.2026 09:32:21
###################################
[ 76519][D][ZigbeeCore.cpp:488] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 76520][D][ZigbeeCore.cpp:489] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 10, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 5
[ 76521][D][ZigbeeCore.cpp:493] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xef0b, profile_id: 0x0104, security_status: 0, lqi: 255, rx_time: 0
[ 76548][D][ZigbeeCore.cpp:488] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 76549][D][ZigbeeCore.cpp:489] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 10, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 5
[ 76550][D][ZigbeeCore.cpp:493] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xef0b, profile_id: 0x0104, security_status: 0, lqi: 255, rx_time: 0
Local: 18.08.26 11:33:21
UTC:   18.08.26 09:33:21
###################################
[120014][D][ZigbeeEP.cpp:562] setTime(): Setting ZCL UTCTime to 840360801 s since 2000-01-01 UTC
[120015][D][ZigbeeEP.cpp:573] setTimezone(): Setting timezone to 7200
Zigbee Time Cluster updated UTC timestamp 1082651040 localOffset 7200
[120017][D][ZigbeeCore.cpp:488] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[120018][D][ZigbeeCore.cpp:489] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 5
[120019][D][ZigbeeCore.cpp:493] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 0, rx_time: 0
[120021][D][ZigbeeCore.cpp:488] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[120022][D][ZigbeeCore.cpp:489] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 11
[120023][D][ZigbeeCore.cpp:493] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 0, rx_time: 0
