.....................
[ 14227][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NWK Device Associated (0x12), status: ESP_OK
[ 14251][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14252][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 28, cluster_id: 0x0013, asdu_length: 12
[ 14252][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xfffd, src_short_addr: 0x46e1, profile_id: 0x0000, security_status: 0, lqi: 112, rx_time: 0
[ 14254][I][ZigbeeCore.cpp:360] esp_zb_app_signal_handler(): New device commissioned or rejoined (short: 0x46e1)
[ 14254][V][ZigbeeCore.cpp:364] esp_zb_app_signal_handler(): Device capabilities: 0x8c
[ 14255][D][ZigbeeCore.cpp:378] esp_zb_app_signal_handler(): Checking endpoint 5
[ 14255][D][ZigbeeCore.cpp:393] esp_zb_app_signal_handler(): Device not bound to endpoint 5 and it is free to bound!
[ 14256][D][ZigbeeCore.cpp:395] esp_zb_app_signal_handler(): Endpoint 5 is searching for device
[ 14261][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14261][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0002, asdu_length: 3
[ 14262][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x46e1, profile_id: 0x0000, security_status: 0, lqi: 107, rx_time: 0
[ 14288][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14288][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8006, asdu_length: 6
[ 14289][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x46e1, profile_id: 0x0000, security_status: 0, lqi: 112, rx_time: 0
[ 14290][D][ZigbeeSwitch.cpp:62] findCbWrapper(): findCbWrapper on EP 5
[ 14291][D][ZigbeeSwitch.cpp:70] findCb(): Found light endpoint
[ 14291][D][ZigbeeSwitch.cpp:77] findCb(): Light found: short address(0x46e1), endpoint(10)
[ 14292][V][ZigbeeSwitch.cpp:86] findCb(): Try to bind On/Off
[ 14292][D][ZigbeeSwitch.cpp:90] findCb(): Find callback on EP 5
[ 14294][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14295][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0021, asdu_length: 22
[ 14296][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 14297][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[ 14300][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14301][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[ 14302][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 14303][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14304][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8021, asdu_length: 2
[ 14305][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 14306][D][ZigbeeSwitch.cpp:53] bindCbWrapper(): bindCbWrapper on EP 5
[ 14307][I][ZigbeeSwitch.cpp:37] bindCb(): Bound successfully!
[ 14307][I][ZigbeeSwitch.cpp:40] bindCb(): The light originating from address(0x46e1) on endpoint(10)
[ 14307][D][ZigbeeSwitch.cpp:41] bindCb(): Light bound to a switch on EP 5
[ 14308][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14309][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8033, asdu_length: 26
[ 14309][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 14310][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[ 14311][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 1, index 0, count 1
[ 14312][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 5, dst_endp 10, cluster_id 0x0006, dst_addr_mode 3
[ 14312][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 1
[ 14313][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 5
[ 14313][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 5
[ 14314][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 14314][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
[ 14350][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Device Authorized (0x2f), status: ESP_OK
[ 14375][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14375][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 34, cluster_id: 0x0036, asdu_length: 3
[ 14376][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xfffc, src_short_addr: 0x46e1, profile_id: 0x0000, security_status: 0, lqi: 117, rx_time: 0
[ 14378][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0x8fbd) is open for 180 seconds
Device on endpoint 10, short address: 0x46e1
IEEE Address: 54:32:04:FF:FE:3D:DC:64
[ 14816][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14817][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 10, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0000, asdu_length: 21
[ 14818][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x46e1, profile_id: 0x0104, security_status: 0, lqi: 117, rx_time: 0
[ 14819][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x46e1) src endpoint(10) to dst endpoint(5) cluster(0x0)
[ 14820][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x0), attribute(0x4), type(0x42), value(13)
[ 14820][I][ZigbeeEP.cpp:320] zbReadBasicCluster(): Peer Manufacturer is "AndroidCrypto"
[ 14846][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14846][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 10, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0000, asdu_length: 19
[ 14847][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x46e1, profile_id: 0x0104, security_status: 0, lqi: 107, rx_time: 0
[ 14848][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x46e1) src endpoint(10) to dst endpoint(5) cluster(0x0)
[ 14849][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x0), attribute(0x5), type(0x42), value(11)
[ 14850][I][ZigbeeEP.cpp:333] zbReadBasicCluster(): Peer Model is "ZBLightBulb"
Light manufacturer: AndroidCrypto
Light model: ZBLightBulb

Bound devices:
Device on endpoint 10, short address: 0x46e1, ieee address: 54:32:04:ff:fe:3d:dc:64
[ 14874][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 14875][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 10, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 14876][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x46e1, profile_id: 0x0104, security_status: 0, lqi: 102, rx_time: 0
[ 14877][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x46e1) src endpoint(10) to dst endpoint(5) cluster(0x6)
[ 14878][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
=========== After Setup Start ============
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   426828 B ( 416.8 KB)
  Free Bytes        :   350536 B ( 342.3 KB)
  Allocated Bytes   :    67780 B (  66.2 KB)
  Minimum Free Bytes:   350452 B ( 342.2 KB)
  Largest Free Block:   335860 B ( 328.0 KB)
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
[ 17874][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17874][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 10, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 17875][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x46e1, profile_id: 0x0104, security_status: 0, lqi: 102, rx_time: 0
[ 17876][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x46e1) src endpoint(10) to dst endpoint(5) cluster(0x6)
[ 17877][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
[ 20874][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 20874][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 10, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 20875][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x46e1, profile_id: 0x0104, security_status: 0, lqi: 102, rx_time: 0
[ 20877][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x46e1) src endpoint(10) to dst endpoint(5) cluster(0x6)
[ 20878][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
[ 23874][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 23874][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 10, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[ 23875][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x46e1, profile_id: 0x0104, security_status: 0, lqi: 96, rx_time: 0
[ 23876][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x46e1) src endpoint(10) to dst endpoint(5) cluster(0x6)
[ 23877][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
Bound devices:
Device on endpoint 10, short address: 0x46e1, ieee address: 54:32:04:ff:fe:3d:dc:64
[ 26873][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NLME Status Indication (0x32), status: ESP_OK

