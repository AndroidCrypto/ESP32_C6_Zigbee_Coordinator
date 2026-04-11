Resetting Zigbee to factory and rebooting in 1s.

ESP32 C6 Zigbee Coordinator Thermostat OLED V01
The OLED display is set up
All callbacks are registered

[  4695][D][ZigbeeCore.cpp:116] addEndpoint(): Endpoint: 1, Device ID: 0x0301
[  4696][D][ZigbeeCore.cpp:164] zigbeeInit(): Initialize Zigbee stack
[  4756][D][ZigbeeCore.cpp:171] zigbeeInit(): Register all Zigbee EPs in list
[  4758][I][ZigbeeCore.cpp:179] zigbeeInit(): List of registered Zigbee EPs:
[  4758][I][ZigbeeCore.cpp:181] zigbeeInit(): Device type: Thermostat Device, Endpoint: 1, Device ID: 0x0301
[  4762][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Config Ready (0x17), status: ESP_FAIL
[  4762][I][ZigbeeCore.cpp:275] esp_zb_app_signal_handler(): Zigbee stack initialized
[  4763][D][ZigbeeCore.cpp:276] esp_zb_app_signal_handler(): Zigbee channel mask: 0x07fff800
[  4765][I][ZigbeeCore.cpp:282] esp_zb_app_signal_handler(): Device started up in  factory-reset mode
[  4765][I][ZigbeeCore.cpp:286] esp_zb_app_signal_handler(): Start network formation
[  9217][I][ZigbeeCore.cpp:447] esp_zb_app_signal_handler(): Network(0xb615) closed, devices joining not allowed.
[  9218][I][ZigbeeCore.cpp:319] esp_zb_app_signal_handler(): Formed network successfully (Extended PAN ID: 98:a3:16:ff:fe:8e:bb:ec, PAN ID: 0xb615, Channel:14, Short Address: 0x0000)
[  9686][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0xb615) is open for 180 seconds
[  9687][I][ZigbeeCore.cpp:335] esp_zb_app_signal_handler(): Network steering started
The Zigbee Coordinator has started
Waiting for a temperature sensor to bound to the thermostat
..................................................................................
[ 50480][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NWK Device Associated (0x12), status: ESP_OK
[ 51032][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51032][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 31, cluster_id: 0x0013, asdu_length: 12
[ 51033][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xfffd, src_short_addr: 0x9d1f, profile_id: 0x0000, security_status: 0, lqi: 168, rx_time: 0
[ 51034][I][ZigbeeCore.cpp:360] esp_zb_app_signal_handler(): New device commissioned or rejoined (short: 0x9d1f)
[ 51035][V][ZigbeeCore.cpp:364] esp_zb_app_signal_handler(): Device capabilities: 0x80
[ 51035][D][ZigbeeCore.cpp:378] esp_zb_app_signal_handler(): Checking endpoint 1
[ 51036][D][ZigbeeCore.cpp:393] esp_zb_app_signal_handler(): Device not bound to endpoint 1 and it is free to bound!
[ 51036][D][ZigbeeCore.cpp:395] esp_zb_app_signal_handler(): Endpoint 1 is searching for device
[ 51300][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51301][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0002, asdu_length: 3
[ 51302][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0000, security_status: 0, lqi: 122, rx_time: 0
[ 51460][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51460][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 31, cluster_id: 0x0402, asdu_length: 8
[ 51461][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0104, security_status: 0, lqi: 168, rx_time: 0
[ 51462][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x9d1f) src endpoint(1) to dst endpoint(1) cluster(0x402)
1 Temperature sensor value: 21.21°C from endpoint 1, address 0x9d1f
[ 51717][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51718][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8006, asdu_length: 6
[ 51718][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0000, security_status: 0, lqi: 158, rx_time: 0
[ 51720][D][ZigbeeThermostatOwn.cpp:84] findCbWrapper(): findCbWrapper on EP 1
[ 51721][I][ZigbeeThermostatOwn.cpp:92] findCb(): Found temperature sensor
[ 51721][D][ZigbeeThermostatOwn.cpp:100] findCb(): Temperature sensor found: short address(0x9d1f), endpoint(1)
[ 51722][I][ZigbeeThermostatOwn.cpp:111] findCb(): Request temperature sensor to bind us
[ 51722][I][ZigbeeThermostatOwn.cpp:114] findCb(): Request humidity sensor to bind us
[ 51723][I][ZigbeeThermostatOwn.cpp:128] findCb(): Try to bind Humidity Measurement
[ 51723][I][ZigbeeThermostatOwn.cpp:134] findCb(): Try to bind Temperature Measurement
[ 51724][V][ZigbeeThermostatOwn.cpp:143] findCb(): Try to bind ESP_ZB_ZCL_CLUSTER_ID_POWER_CONFIG
[ 51726][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51727][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0021, asdu_length: 22
[ 51728][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51729][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[ 51729][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51730][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0021, asdu_length: 22
[ 51731][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51732][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[ 51732][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51733][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0021, asdu_length: 22
[ 51734][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51735][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[ 51742][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51743][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[ 51743][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51744][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51745][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[ 51746][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51747][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51747][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[ 51748][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51749][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51750][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8021, asdu_length: 2
[ 51751][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51752][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51752][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 105, cluster_id: 0x8021, asdu_length: 2
[ 51753][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51754][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51755][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8021, asdu_length: 2
[ 51756][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51757][D][ZigbeeThermostatOwn.cpp:76] bindCbWrapper(): bindCbWrapper on EP 1
[ 51757][I][ZigbeeThermostatOwn.cpp:60] bindCb(): Bound successfully!
[ 51758][I][ZigbeeThermostatOwn.cpp:63] bindCb(): The sensor originating from address(0x9d1f) on endpoint(1)
[ 51758][D][ZigbeeThermostatOwn.cpp:64] bindCb(): Sensor bound to thermostat on EP 1
[ 51759][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51759][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 134, cluster_id: 0x8033, asdu_length: 68
[ 51760][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51761][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51762][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 255, cluster_id: 0x8033, asdu_length: 68
[ 51763][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51763][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51764][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 255, cluster_id: 0x8033, asdu_length: 68
[ 51765][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 51766][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[ 51766][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 3, index 0, count 3
[ 51767][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 1, dst_endp 1, cluster_id 0x0405, dst_addr_mode 3
[ 51768][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 1: src_endp 1, dst_endp 1, cluster_id 0x0402, dst_addr_mode 3
[ 51768][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 2: src_endp 1, dst_endp 1, cluster_id 0x0001, dst_addr_mode 3
[ 51769][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 3
[ 51769][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 1
[ 51770][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 51770][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 51771][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 51771][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 51771][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 51772][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 51772][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
[ 51773][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[ 51773][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 3, index 0, count 3
[ 51774][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 1, dst_endp 1, cluster_id 0x0405, dst_addr_mode 3
[ 51774][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 1: src_endp 1, dst_endp 1, cluster_id 0x0402, dst_addr_mode 3
[ 51775][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 2: src_endp 1, dst_endp 1, cluster_id 0x0001, dst_addr_mode 3
[ 51775][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 3
[ 51776][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 1
[ 51776][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 51777][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 51777][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 51778][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 51778][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 51778][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 51779][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
[ 51779][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[ 51780][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 3, index 0, count 3
[ 51780][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 1, dst_endp 1, cluster_id 0x0405, dst_addr_mode 3
[ 51781][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 1: src_endp 1, dst_endp 1, cluster_id 0x0402, dst_addr_mode 3
[ 51781][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 2: src_endp 1, dst_endp 1, cluster_id 0x0001, dst_addr_mode 3
[ 51782][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 3
[ 51782][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 1
[ 51783][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 51783][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 51784][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 51784][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 51784][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 1
[ 51785][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 51785][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
[ 51789][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 51789][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 31, cluster_id: 0x0405, asdu_length: 8
[ 51790][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0104, security_status: 0, lqi: 168, rx_time: 0
[ 51792][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x9d1f) src endpoint(1) to dst endpoint(1) cluster(0x405)

A device is bounded to the Coordinator
1 Humidity sensor value: 43.99 percent from endpoint 1, address 0x9d1f
[ 52127][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 52128][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8021, asdu_length: 2
[ 52128][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0000, security_status: 0, lqi: 158, rx_time: 0
[ 52133][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 52133][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8021, asdu_length: 2
[ 52134][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0000, security_status: 0, lqi: 158, rx_time: 0
[ 52144][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Device Authorized (0x2f), status: ESP_OK
[ 52187][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 52188][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 52, cluster_id: 0x0036, asdu_length: 3
[ 52188][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xfffc, src_short_addr: 0x9d1f, profile_id: 0x0000, security_status: 0, lqi: 158, rx_time: 0
[ 52190][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0xb615) is open for 180 seconds
Device on endpoint 1, short address: 0x9d1f
IEEE Address: A4:C1:38:A7:E0:F2:57:3E
[ 52477][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 52478][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0000, asdu_length: 15
[ 52478][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0104, security_status: 0, lqi: 168, rx_time: 0
[ 52480][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x9d1f) src endpoint(1) to dst endpoint(1) cluster(0x0)
[ 52480][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x0), attribute(0x4), type(0x42), value(7)
[ 52481][I][ZigbeeEP.cpp:320] zbReadBasicCluster(): Peer Manufacturer is "Zbeacon"
[ 52745][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 52746][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0000, asdu_length: 12
[ 52747][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0104, security_status: 0, lqi: 168, rx_time: 0
[ 52748][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x9d1f) src endpoint(1) to dst endpoint(1) cluster(0x0)
[ 52749][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x0), attribute(0x5), type(0x42), value(4)
[ 52750][I][ZigbeeEP.cpp:333] zbReadBasicCluster(): Peer Model is "TH01"
Device manufacturer: Zbeacon
Device model: TH01

Temperature: 21.21 Celsius Humidity: 44.0 %rH Battery voltage: 0.00 voltage remaining capacity:   0 %
Last update for Temperature: 1 (21.21) Humidity: 0 (43.99) Battery voltage: 52 (0.00) percentage: 52 (0) seconds
[ 58256][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 58257][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 31, cluster_id: 0x0402, asdu_length: 8
[ 58258][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0104, security_status: 0, lqi: 173, rx_time: 0
[ 58259][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x9d1f) src endpoint(1) to dst endpoint(1) cluster(0x402)
1 Temperature sensor value: 21.46°C from endpoint 1, address 0x9d1f
[ 58512][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 58512][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0405, asdu_length: 8
[ 58513][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0104, security_status: 0, lqi: 173, rx_time: 0
[ 58514][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x9d1f) src endpoint(1) to dst endpoint(1) cluster(0x405)
1 Humidity sensor value: 43.23 percent from endpoint 1, address 0x9d1f
Temperature: 21.46 Celsius Humidity: 43.2 %rH Battery voltage: 0.00 voltage remaining capacity:   0 %
Last update for Temperature: 4 (0.25) Humidity: 4 (-0.76) Battery voltage: 62 (0.00) percentage: 62 (0) seconds
[ 68501][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 68502][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 31, cluster_id: 0x0402, asdu_length: 8
[ 68502][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0104, security_status: 0, lqi: 178, rx_time: 0
[ 68504][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x9d1f) src endpoint(1) to dst endpoint(1) cluster(0x402)
1 Temperature sensor value: 21.58°C from endpoint 1, address 0x9d1f
[ 68756][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 68757][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 31, cluster_id: 0x0405, asdu_length: 8
[ 68757][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x9d1f, profile_id: 0x0104, security_status: 0, lqi: 178, rx_time: 0
[ 68759][V][ZigbeeHandlers.cpp:120] zb_attribute_reporting_handler(): Received report from address(0x9d1f) src endpoint(1) to dst endpoint(1) cluster(0x405)
1 Humidity sensor value: 42.14 percent from endpoint 1, address 0x9d1f
