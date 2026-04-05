...
[110907][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NWK Device Associated (0x12), status: ESP_OK
[111198][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[111198][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 38, cluster_id: 0x0013, asdu_length: 12
[111199][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xfffd, src_short_addr: 0xadef, profile_id: 0x0000, security_status: 0, lqi: 81, rx_time: 0
[111201][I][ZigbeeCore.cpp:360] esp_zb_app_signal_handler(): New device commissioned or rejoined (short: 0xadef)
[111201][V][ZigbeeCore.cpp:364] esp_zb_app_signal_handler(): Device capabilities: 0x8e
[111201][D][ZigbeeCore.cpp:378] esp_zb_app_signal_handler(): Checking endpoint 5
[111202][D][ZigbeeCore.cpp:393] esp_zb_app_signal_handler(): Device not bound to endpoint 5 and it is free to bound!
[111203][D][ZigbeeCore.cpp:395] esp_zb_app_signal_handler(): Endpoint 5 is searching for device
[111229][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[111230][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8006, asdu_length: 6
[111231][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0000, security_status: 0, lqi: 96, rx_time: 0
[111232][D][ZigbeeSwitch.cpp:62] findCbWrapper(): findCbWrapper on EP 5
[111232][D][ZigbeeSwitch.cpp:70] findCb(): Found light endpoint
[111232][D][ZigbeeSwitch.cpp:77] findCb(): Light found: short address(0xadef), endpoint(1)
[111233][V][ZigbeeSwitch.cpp:86] findCb(): Try to bind On/Off
[111233][D][ZigbeeSwitch.cpp:90] findCb(): Find callback on EP 5
[111235][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[111236][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0021, asdu_length: 22
[111237][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[111238][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x0000
[111242][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[111242][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[111243][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[111245][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[111245][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8021, asdu_length: 2
[111246][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[111247][D][ZigbeeSwitch.cpp:53] bindCbWrapper(): bindCbWrapper on EP 5
[111247][I][ZigbeeSwitch.cpp:37] bindCb(): Bound successfully!
[111248][I][ZigbeeSwitch.cpp:40] bindCb(): The light originating from address(0xadef) on endpoint(1)
[111248][D][ZigbeeSwitch.cpp:41] bindCb(): Light bound to a switch on EP 5
[111249][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[111249][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8033, asdu_length: 26
[111250][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[111251][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x0000 with status 0
[111252][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 1, index 0, count 1
[111252][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 5, dst_endp 1, cluster_id 0x0006, dst_addr_mode 3
[111253][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 1
[111253][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 5
[111254][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 5
[111254][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[111255][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
[111859][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[111860][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[111861][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[111862][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[111863][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[111863][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[111864][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[111867][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=12
Device on endpoint 1, short address: 0xadef
IEEE Address: A4:C1:38:54:51:56:50:A4
[111965][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[111965][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0000, asdu_length: 15
[111966][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 76, rx_time: 0
[111968][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xadef) src endpoint(1) to dst endpoint(5) cluster(0x0)
[111968][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x0), attribute(0x4), type(0x42), value(7)
[111969][I][ZigbeeEP.cpp:320] zbReadBasicCluster(): Peer Manufacturer is "Zbeacon"
[112062][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[112063][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0000, asdu_length: 14
[112064][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 117, rx_time: 0
[112065][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xadef) src endpoint(1) to dst endpoint(5) cluster(0x0)
[112066][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x0), attribute(0x5), type(0x42), value(6)
[112066][I][ZigbeeEP.cpp:333] zbReadBasicCluster(): Peer Model is "TS011F"
Light manufacturer: Zbeacon
Light model: TS011F

Bound devices:
Device on endpoint 1, short address: 0xadef, ieee address: a4:c1:38:54:51:56:50:a4
[112082][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[112083][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[112084][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[112084][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[112085][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[112086][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[112087][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[112089][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=34
[112131][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[112132][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[112133][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 86, rx_time: 0
[112134][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xadef) src endpoint(1) to dst endpoint(5) cluster(0x6)
[112135][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
[112159][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[112160][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0002, asdu_length: 3
[112161][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0000, security_status: 0, lqi: 96, rx_time: 0
=========== After Setup Start ============
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   426828 B ( 416.8 KB)
  Free Bytes        :   346068 B ( 338.0 KB)
  Allocated Bytes   :    71928 B (  70.2 KB)
  Minimum Free Bytes:   345908 B ( 337.8 KB)
  Largest Free Block:   327668 B ( 320.0 KB)
------------------------------------------
GPIO Info:
------------------------------------------
  GPIO : BUS_TYPE[bus/unit][chan]
  --------------------------------------  
     9 : GPIO
    10 : I2C_MASTER_SDA[0]
    11 : I2C_MASTER_SCL[0]
    12 : USB_DM
    13 : USB_DP
    15 : GPIO
    16 : UART_TX[0]
    17 : UART_RX[0]
============ After Setup End =============
[115091][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[115092][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[115093][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 91, rx_time: 0
[115094][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xadef) src endpoint(1) to dst endpoint(5) cluster(0x6)
[115095][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
[117167][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[117167][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0002, asdu_length: 3
[117168][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0000, security_status: 0, lqi: 96, rx_time: 0
[117263][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Device Authorized (0x2f), status: ESP_OK
[117390][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[117390][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 43, cluster_id: 0x0036, asdu_length: 3
[117391][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0xfffc, src_short_addr: 0xadef, profile_id: 0x0000, security_status: 0, lqi: 102, rx_time: 0
[117392][I][ZigbeeCore.cpp:445] esp_zb_app_signal_handler(): Network(0xd946) is open for 180 seconds
[118138][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[118139][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[118140][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 112, rx_time: 0
[118141][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xadef) src endpoint(1) to dst endpoint(5) cluster(0x6)
[118142][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
[118322][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[118323][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 49, cluster_id: 0x000a, asdu_length: 5
[118324][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 81, rx_time: 0
[118499][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[118500][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 46, cluster_id: 0x0b04, asdu_length: 8
[118501][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 142, rx_time: 0
[120520][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[120521][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 35, cluster_id: 0x0b04, asdu_length: 8
[120522][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 107, rx_time: 0
[121091][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[121092][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[121093][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 86, rx_time: 0
[121094][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xadef) src endpoint(1) to dst endpoint(5) cluster(0x6)
[121095][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
Toggling light
[121147][V][ZigbeeSwitch.cpp:119] lightToggle(): Sending 'light toggle' command
[121155][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[121156][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[121157][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[121158][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[121158][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[121159][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[121160][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[121165][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[121170][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[121171][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 5
[121172][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 91, rx_time: 0
[121173][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0xadef), src_endpoint(1) to dst_endpoint(5), cluster(0x6) with status 0x0
[121174][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 5
[121174][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[121175][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 2
[121177][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[121180][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[121183][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[121186][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[121189][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[121191][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=64
[121268][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[121268][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 39, cluster_id: 0x0006, asdu_length: 7
[121269][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 91, rx_time: 0
[122507][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: NLME Status Indication (0x32), status: ESP_OK
Bound devices:
Device on endpoint 1, short address: 0xadef, ieee address: a4:c1:38:54:51:56:50:a4
[123209][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[123210][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 40, cluster_id: 0x0006, asdu_length: 7
[123211][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 66, rx_time: 0
[123407][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[123408][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 37, cluster_id: 0x0006, asdu_length: 7
[123408][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 107, rx_time: 0
[123573][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[123574][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 41, cluster_id: 0x0006, asdu_length: 7
[123574][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 127, rx_time: 0
Toggling light
[123660][V][ZigbeeSwitch.cpp:119] lightToggle(): Sending 'light toggle' command
[123735][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[123735][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 5
[123736][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 96, rx_time: 0
[123737][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0xadef), src_endpoint(1) to dst_endpoint(5), cluster(0x6) with status 0x0
[123738][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 5
[123739][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[123739][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 2
[123783][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[123783][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 43, cluster_id: 0x0006, asdu_length: 7
[123784][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 96, rx_time: 0
[123901][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[123902][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 44, cluster_id: 0x000a, asdu_length: 5
[123903][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 102, rx_time: 0
[123980][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[123980][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 43, cluster_id: 0x0b04, asdu_length: 8
[123981][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 96, rx_time: 0
[124219][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[124220][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[124221][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 96, rx_time: 0
[124222][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xadef) src endpoint(1) to dst endpoint(5) cluster(0x6)
[124223][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
[124252][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[124253][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 49, cluster_id: 0x0b04, asdu_length: 8
[124254][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 102, rx_time: 0
[124353][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[124354][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 46, cluster_id: 0x0b04, asdu_length: 8
[124355][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 112, rx_time: 0
[124650][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[124650][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 35, cluster_id: 0xe000, asdu_length: 9
[124651][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 91, rx_time: 0
[124825][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[124825][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 36, cluster_id: 0xe000, asdu_length: 9
[124826][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 91, rx_time: 0
[124993][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[124994][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 36, cluster_id: 0x0006, asdu_length: 8
[124994][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 102, rx_time: 0
[125200][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[125201][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 38, cluster_id: 0x0006, asdu_length: 8
[125202][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 107, rx_time: 0
[127113][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[127114][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[127114][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 107, rx_time: 0
[127116][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xadef) src endpoint(1) to dst endpoint(5) cluster(0x6)
[127117][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
[130184][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[130185][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[130185][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 107, rx_time: 0
[130187][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xadef) src endpoint(1) to dst endpoint(5) cluster(0x6)
[130187][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
Toggling light
[929718][V][ZigbeeSwitch.cpp:119] lightToggle(): Sending 'light toggle' command
[929728][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[929729][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[929730][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[929731][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[929731][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[929732][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=2
[929733][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[929736][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[929741][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=128
[929744][V][esp32-hal-i2c-ng.c:272] i2cWrite(): i2c_master_transmit: bus=0 addr=0x3c handle=0x408200f8 size=50
[929762][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[929763][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 5
[929764][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 71, rx_time: 0
[929765][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0xadef), src_endpoint(1) to dst_endpoint(5), cluster(0x6) with status 0x0
[929766][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 5
[929767][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[929767][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 2
[929840][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[929841][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 1, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 169, cluster_id: 0x0006, asdu_length: 7
[929841][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 96, rx_time: 0
[931114][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[931114][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 5, src_endpoint: 1, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 8
[931115][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0xadef, profile_id: 0x0104, security_status: 0, lqi: 71, rx_time: 0
[931116][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0xadef) src endpoint(1) to dst endpoint(5) cluster(0x6)
[931117][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0x6), attribute(0x0), type(0x10), value(0)
Light state changed to 0