*** setTemperatureHumidityReporting interval min 30 max 60 seconds change Celsius 10 Humidity 100 ***
[ 38194][I][ZigbeeThermostatOwn.cpp:958] setTemperatureHumidityReporting(): Sending 'configure temperature and humidity reporting' command to endpoint 1, address 0x374
err temperature: 0

[ 39802][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 39803][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 61, cluster_id: 0x0402, asdu_length: 7
[ 39804][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0374, profile_id: 0x0104, security_status: 0, lqi: 81, rx_time: 0
[ 39805][V][ZigbeeHandlers.cpp:216] zb_configure_report_resp_handler(): Configure report response: status(0), cluster(0x402), direction(0xff), attribute(0xffff)

[ 39841][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 39842][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 54, cluster_id: 0x0405, asdu_length: 7
[ 39842][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0374, profile_id: 0x0104, security_status: 0, lqi: 81, rx_time: 0
[ 39844][V][ZigbeeHandlers.cpp:216] zb_configure_report_resp_handler(): Configure report response: status(0), cluster(0x405), direction(0xff), attribute(0xffff)

[ 58418][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 58419][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 67, cluster_id: 0x0001, asdu_length: 7
[ 58419][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac03, profile_id: 0x0104, security_status: 0, lqi: 96, rx_time: 0
[ 58421][V][ZigbeeHandlers.cpp:216] zb_configure_report_resp_handler(): Configure report response: status(0), cluster(0x1), direction(0xff), attribute(0xffff)

[ 58845][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 58846][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 68, cluster_id: 0x0001, asdu_length: 7
[ 58846][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xac03, profile_id: 0x0104, security_status: 0, lqi: 71, rx_time: 0
[ 58848][V][ZigbeeHandlers.cpp:216] zb_configure_report_resp_handler(): Configure report response: status(0), cluster(0x1), direction(0xff), attribute(0xffff)
