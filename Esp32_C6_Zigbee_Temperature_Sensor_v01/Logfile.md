Sketch uses 1025994 bytes (78%) of program storage space. Maximum is 1310720 bytes.
Global variables use 34352 bytes (10%) of dynamic memory, leaving 293328 bytes for local variables. Maximum is 327680 bytes.

[     0][V][ZigbeeEP.cpp:27] ZigbeeEP(): Endpoint: 10
=========== Before Setup Start ===========
Chip Info:
------------------------------------------
  Model             : ESP32-C6
  Package           : 1
  Revision          : 0.01
  Cores             : 1
  CPU Frequency     : 160 MHz
  XTAL Frequency    : 4    : No
  BT Low Energy     : Yes
  IEEE 802.15.4     : Yes
------------------------------------------
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   434380 B ( 424.2 KB)
  Free Bytes        :   399456 B ( 390.1 KB)
  Allocated Bytes   :    27956 B (  27.3 KB)
  Minimum Free Bytes:   394468 B ( 385.2 KB)
  Largest Free Block:   376820 B ( 368.0 KB)
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
[ 13326][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RX (2) cleared
[ 13326][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_TX (3) cleared
[ 13327][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_CTS (4) cleared
[ 13327][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RTS (5) cleared
[ 13328][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 17 successfully set to type UART_RX (2) with bus 0x40810f80
[ 13329][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_RX (2) successfully set to 0x42009e5e
[ 13329][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 16 successfully set to type UART_TX (3) with bus 0x40810f80
[ 13330][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_TX (3) successfully set to 0x42009d24
[ 13330][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 12 already has type USB_DM (38) with bus 0x4081410c
[ 13331][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 13 already has type USB_DP (39) with bus 0x4081410c
[ 13331][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type GPIO (1) successfully set to 0x42006fb0
[ 13332][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 9 successfully set to type GPIO (1) with bus 0xa
[ 13333][D][ZigbeeCore.cpp:116] addEndpoint(): Endpoint: 10, Device ID: 0x0302
Starting Zigbee...
[ 13333][D][ZigbeeCore.cpp:164] zigbeeInit(): Initialize Zigbee stack
[ 13387][D][ZigbeeCore.cpp:171] zigbeeInit(): Register all Zigbee EPs in list
[ 13389][I][ZigbeeCore.cpp:179] zigbeeInit(): List of registered Zigbee EPs:
[ 13390][I][ZigbeeCore.cpp:181] zigbeeInit(): Device type: Temperature Sensor, Endpoint: 10, Device ID: 0x0302
[ 13547][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Config Ready (0x17), status: ESP_FAIL
[ 13548][I][ZigbeeCore.cpp:275] esp_zb_app_signal_handler(): Zigbee stack initialized
[ 13548][D][ZigbeeCore.cpp:276] esp_zb_app_signal_handler(): Zigbee channel mask: 0x07fff800
[ 13550][I][ZigbeeCore.cpp:282] esp_zb_app_signal_handler(): Device started up in  factory-reset mode
[ 13551][I][ZigbeeCore.cpp:289] esp_zb_app_signal_handler(): Start network steering
Zigbee started successfully!
Connecting to network
.......................
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
[ 16314][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16315][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 11
[ 16316][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 224, rx_time: 0
[ 16323][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16324][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8002, asdu_length: 17
[ 16325][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 224, rx_time: 0
[ 16351][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16351][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0021, asdu_length: 22
[ 16352][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 224, rx_time: 0
[ 16353][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x697c
[ 16357][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16358][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 1, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[ 16359][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0069, src_short_addr: 0x697c, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 16361][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16361][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 1, src_addr_mode: 0, cluster_id: 0x8033, asdu_length: 26
[ 16362][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0069, src_short_addr: 0x697c, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 16363][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x697c with status 0
[ 16364][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 1, index 0, count 1
[ 16364][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 10, dst_endp 1, cluster_id 0x0402, dst_addr_mode 3
[ 16365][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 1
[ 16365][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 10
[ 16366][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 10
[ 16366][D][ZigbeeCore.cpp:734] bindingTableCb(): Device bound to EP 10 -> device endpoint: 1, ieee addr: 54:32:04:FF:FE:3D:DC:64
[ 16367][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
[ 16370][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16371][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0021, asdu_length: 22
[ 16372][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 219, rx_time: 0
[ 16372][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x697c
[ 16377][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16377][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 1, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[ 16378][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0069, src_short_addr: 0x697c, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 16380][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16381][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 1, src_addr_mode: 0, cluster_id: 0x8033, asdu_length: 47
[ 16382][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0069, src_short_addr: 0x697c, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 16383][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x697c with status 0
[ 16383][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 2, index 0, count 2
[ 16384][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 10, dst_endp 1, cluster_id 0x0402, dst_addr_mode 3
[ 16384][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 1: src_endp 10, dst_endp 1, cluster_id 0x0405, dst_addr_mode 3
[ 16385][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 2
[ 16385][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 10
[ 16386][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 10
[ 16386][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 16387][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 10
[ 16387][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 16388][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
[ 16391][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16392][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 9
[ 16393][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[ 16521][I][ZigbeeCore.cpp:343] esp_zb_app_signal_handler(): Joined network successfully (Extended PAN ID: 54:32:04:ff:fe:3d:dc:64, PAN ID: 0x2e1e, Channel:15, Short Address: 0x697c)
[ 16523][V][ZigbeeCore.cpp:775] setNVRAMChannelMask(): Channel mask set to 0x00008000

[ 16589][V][ZigbeeEP.cpp:448] getTime(): Reading time from endpoint 1
[ 16607][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16608][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 11
[ 16608][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[ 16610][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x0) src endpoint(1) to dst endpoint(10) cluster(0xa)
[ 16610][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0xa), attribute(0x0), type(0xe2), value(102)
[ 16611][V][ZigbeeEP.cpp:516] zbReadTimeCluster(): Time attribute received
[ 16611][V][ZigbeeEP.cpp:517] zbReadTimeCluster(): Time: 17079205888
[ 16614][D][ZigbeeEP.cpp:398] setTime(): Setting time to 1736771430
[ 16614][V][ZigbeeEP.cpp:501] getTimezone(): Reading timezone from endpoint 1
[ 16633][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 16633][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 11
[ 16634][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[ 16636][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x0) src endpoint(1) to dst endpoint(10) cluster(0xa)
[ 16636][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0xa), attribute(0x2), type(0x2b), value(16)
[ 16637][V][ZigbeeEP.cpp:521] zbReadTimeCluster(): Timezone attribute received
[ 16637][V][ZigbeeEP.cpp:522] zbReadTimeCluster(): Timezone: 3600
[ 16639][D][ZigbeeEP.cpp:411] setTimezone(): Setting timezone to 3600
UTC time:
Monday, January 13 2025 12:30:30
Local time with timezone:
Monday, January 13 2025 13:30:30
Updated temperature sensor value to 40.70°C
[ 16641][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 16642][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
=========== After Setup Start ============
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   434380 B ( 424.2 KB)
  Free Bytes        :   364652 B ( 356.1 KB)
  Allocated Bytes   :    61672 B (  60.2 KB)
  Minimum Free Bytes:   364524 B ( 356.0 KB)
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
Updated temperature sensor value to 39.70°C
[ 17642][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 17642][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3970
[ 17664][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17665][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 17665][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[ 17667][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 17667][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 17668][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 17668][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 39.70°C
[ 18643][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 18643][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3970
Updated temperature sensor value to 39.70°C
[ 19644][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 19644][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3970
Updated temperature sensor value to 39.70°C
[ 20645][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 20645][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3970
Updated temperature sensor value to 39.70°C
[ 21646][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 21646][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3970
Updated temperature sensor value to 39.70°C
[ 22647][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 22647][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3970
Updated temperature sensor value to 40.70°C
[ 23648][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 23648][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
[ 23668][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 23669][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 23670][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[ 23671][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 23672][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 23672][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 23673][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 40.70°C
[ 24649][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 24649][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 25650][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 25650][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 26651][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 26651][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 27652][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 27652][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 28653][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 28653][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 29654][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 29654][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 30655][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 30655][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 31656][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 31656][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 32656][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 32656][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 33657][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 33657][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 34657][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 34657][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 35657][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 35657][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 36658][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 36658][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 37658][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 37658][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 38659][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 38659][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 40.70°C
[ 39660][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 39660][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
Updated temperature sensor value to 41.70°C
[ 40660][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 40660][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
[ 40680][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 40681][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 40681][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[ 40683][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 40683][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 40684][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 40684][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 41.70°C
[ 41661][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 41661][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 42662][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 42662][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 43663][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 43663][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
[ 44187][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 44187][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 13
[ 44188][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 198, rx_time: 0
[ 44217][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 44218][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 44218][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 198, rx_time: 0
[ 44220][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 44220][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 44221][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 44221][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 41.70°C
[ 44663][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 44663][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 45664][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 45665][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 46665][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 46665][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 47666][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 47666][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
[ 48184][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 48185][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 13
[ 48185][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 204, rx_time: 0
[ 48217][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 48218][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 48219][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 198, rx_time: 0
[ 48220][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 48221][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 48221][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 48221][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 41.70°C
[ 48667][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 48667][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 49668][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 49668][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 50669][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 50669][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 51670][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 51670][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 52670][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 52670][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 53671][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 53671][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 54672][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 54672][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 55673][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 55673][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 56674][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 56674][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 57675][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 57675][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
[ 58211][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 58211][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 58212][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 234, rx_time: 0
[ 58214][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 58214][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 58215][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 58215][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 41.70°C
[ 58676][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 58676][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 59677][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 59677][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 60678][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 60678][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 61679][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 61679][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 62679][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 62679][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 63680][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 63680][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 64680][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 64680][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 42.70°C
[ 65681][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 65681][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 41.70°C
[ 66682][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 66682][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 41.70°C
[ 67683][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 67683][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
[ 68213][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 68214][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 68214][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[ 68216][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 68216][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 68217][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 68217][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 41.70°C
[ 68684][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 68684][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4170
Updated temperature sensor value to 42.70°C
[ 69685][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 69685][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 70686][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 70686][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 71686][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 71686][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 72687][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 72687][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 73688][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 73688][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 74688][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 74688][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 75689][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 75689][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 76690][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 76690][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 77691][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 77691][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
[ 78215][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 78216][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 78217][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[ 78218][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 78219][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 78219][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 78219][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 42.70°C
[ 78692][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 78692][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 79693][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 79693][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 80693][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 80693][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 81694][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 81694][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 82694][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 82694][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 83694][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 83694][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 84695][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 84695][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 85695][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 85695][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 86695][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 86695][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 87696][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 87696][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
[ 88217][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 88218][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 88218][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 219, rx_time: 0
[ 88220][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 88220][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 88221][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 88221][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 42.70°C
[ 88697][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 88697][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 89698][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 89698][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 90699][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 90699][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 91700][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 91700][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 92701][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 92701][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 93702][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 93702][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 94702][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 94702][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 95703][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 95703][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 96704][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 96704][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 97705][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 97705][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
[ 98219][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 98220][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 98220][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[ 98222][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 98222][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 98223][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 98223][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 42.70°C
[ 98705][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 98705][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[ 99706][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 99706][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[100706][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[100706][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[101706][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[101706][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[102707][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[102707][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[103707][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[103707][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[104707][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[104707][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[105708][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[105708][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[106709][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[106709][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[107710][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[107710][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
[108221][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[108222][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[108222][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 234, rx_time: 0
[108224][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[108224][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[108225][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[108225][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 42.70°C
[108711][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[108711][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[109712][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[109712][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[110713][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[110713][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[111714][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[111714][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[112715][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[112715][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[113716][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[113716][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[114717][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[114717][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[115718][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[115718][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[116719][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[116719][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[117720][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[117720][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
[118223][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[118224][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[118224][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 234, rx_time: 0
[118226][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[118227][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[118227][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[118227][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 42.70°C
[118721][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[118721][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[119722][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[119722][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[120723][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[120723][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[121724][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[121724][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[122725][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[122725][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[123726][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[123726][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[124727][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[124727][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[125728][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[125728][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[126729][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[126729][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 42.70°C
[127730][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[127730][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
[128225][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[128226][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[128227][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[128228][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[128229][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[128229][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[128229][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 42.70°C
[128731][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[128731][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 43.70°C
[129732][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[129732][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[130733][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[130733][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[131734][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[131734][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 42.70°C
[132735][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[132735][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
Updated temperature sensor value to 43.70°C
[133736][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[133736][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[134737][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[134737][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[135738][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[135738][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[136739][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[136739][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[137740][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[137740][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[138227][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[138228][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[138229][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[138230][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[138231][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[138231][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[138232][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[138741][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[138741][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[139742][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[139742][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[140743][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[140743][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[141744][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[141744][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[142745][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[142745][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[143746][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[143746][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[144747][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[144747][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[145748][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[145748][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[146749][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[146749][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[147750][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[147750][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[148229][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[148230][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[148230][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 229, rx_time: 0
[148232][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[148232][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[148233][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[148233][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[148751][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[148751][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[149752][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[149752][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[150753][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[150753][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[151754][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[151754][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[152755][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[152755][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[153756][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[153756][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[154757][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[154757][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[155758][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[155758][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[156759][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[156759][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[157760][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[157760][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[158231][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[158232][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[158232][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 229, rx_time: 0
[158234][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[158234][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[158235][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[158235][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[158761][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[158761][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[159762][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[159762][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[160763][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[160763][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[161764][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[161764][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[162765][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[162765][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[163766][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[163766][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[164767][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[164767][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[165768][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[165768][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[166769][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[166769][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[167770][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[167770][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[168234][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[168235][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[168235][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[168237][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[168237][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[168238][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[168238][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[168771][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[168772][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[169772][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[169772][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[170773][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[170773][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[171774][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[171774][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[172775][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[172775][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[173776][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[173776][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[174777][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[174777][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[175778][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[175778][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[176779][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[176779][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[177780][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[177780][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[178235][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[178236][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[178237][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[178238][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[178239][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[178239][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[178239][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[178781][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[178781][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[179782][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[179782][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[180783][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[180783][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[181784][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[181784][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[182785][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[182785][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[183786][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[183786][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[184786][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[184786][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[185786][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[185786][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[186787][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[186787][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[187787][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[187787][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[188237][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[188238][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[188238][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x697c, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 229, rx_time: 0
[188240][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[188240][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[188241][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[188241][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[188787][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[188787][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[189788][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[189788][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[     0][V][ZigbeeEP.cpp:27] ZigbeeEP(): Endpoint: 10
=========== Before Setup Start ===========
Chip Info:
------------------------------------------
  Model             : ESP32-C6
  Package           : 1
  Revision          : 0.01
  Cores             : 1
  CPU Frequency     : 160 MHz
  XTAL Frequency    : 4res Bitfield : 0x00000052
  Embedded Flash    : No
  Embedded PSRAM    : No
  2.4GHz WiFi       : Yes
  Classic BT        : No
  BT Low Energy     : Yes
  IEEE 802.15.4     : Yes
------------------------------------------
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   434380 B ( 424.2 KB)
  Free Bytes        :   399456 B ( 390.1 KB)
  Allocated Bytes   :    27956 B (  27.3 KB)
  Minimum Free Bytes:   394468 B ( 385.2 KB)
  Largest Free Block:   376820 B ( 368.0 KB)
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
[  1498][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RX (2) cleared
[  1498][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_TX (3) cleared
[  1499][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_CTS (4) cleared
[  1499][V][esp32-hal-periman.c:251] perimanClearBusDeinit(): Deinit function for type UART_RTS (5) cleared
[  1500][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 17 successfully set to type UART_RX (2) with bus 0x40810f80
[  1500][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_RX (2) successfully set to 0x42009e5e
[  1501][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 16 successfully set to type UART_TX (3) with bus 0x40810f80
[  1502][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type UART_TX (3) successfully set to 0x42009d24
[  1502][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 12 already has type USB_DM (38) with bus 0x4081410c
[  1503][I][esp32-hal-periman.c:141] perimanSetPinBus(): Pin 13 already has type USB_DP (39) with bus 0x4081410c
[  1503][V][esp32-hal-periman.c:235] perimanSetBusDeinit(): Deinit function for type GPIO (1) successfully set to 0x42006fb0
[  1504][V][esp32-hal-periman.c:160] perimanSetPinBus(): Pin 9 successfully set to type GPIO (1) with bus 0xa
[  1505][D][ZigbeeCore.cpp:116] addEndpoint(): Endpoint: 10, Device ID: 0x0302
Starting Zigbee...
[  1506][D][ZigbeeCore.cpp:164] zigbeeInit(): Initialize Zigbee stack
[  1556][D][ZigbeeCore.cpp:171] zigbeeInit(): Register all Zigbee EPs in list
[  1558][I][ZigbeeCore.cpp:179] zigbeeInit(): List of registered Zigbee EPs:
[  1558][I][ZigbeeCore.cpp:181] zigbeeInit(): Device type: Temperature Sensor, Endpoint: 10, Device ID: 0x0302
[  1715][V][ZigbeeCore.cpp:466] esp_zb_app_signal_handler(): ZDO signal: ZDO Config Ready (0x17), status: ESP_FAIL
[  1716][I][ZigbeeCore.cpp:275] esp_zb_app_signal_handler(): Zigbee stack initialized
[  1716][D][ZigbeeCore.cpp:276] esp_zb_app_signal_handler(): Zigbee channel mask: 0x07fff800
[  1718][I][ZigbeeCore.cpp:282] esp_zb_app_signal_handler(): Device started up in  factory-reset mode
[  1719][I][ZigbeeCore.cpp:289] esp_zb_app_signal_handler(): Start network steering
Zigbee started successfully!
Connecting to network
.......................ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: zdo/zdo_commissioning.c:212    Can't find PAN to join to! param 0
[  3949][I][ZigbeeCore.cpp:352] esp_zb_app_signal_handler(): Network steering was not successful (status: ESP_FAIL)
................................ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: zdo/zdo_commissioning.c:212    Can't find PAN to join to! param 0
[  7180][I][ZigbeeCore.cpp:352] esp_zb_app_signal_handler(): Network steering was not successful (status: ESP_FAIL)
................................ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: zdo/zdo_commissioning.c:212    Can't find PAN to join to! param 0
[ 10411][I][ZigbeeCore.cpp:352] esp_zb_app_signal_handler(): Network steering was not successful (status: ESP_FAIL)
.................................ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:251    No dev for join
ZB_TRACE_LOG[0]: zdo/zdo_commissioning.c:212    Can't find PAN to join to! param 0
[ 13646][I][ZigbeeCore.cpp:352] esp_zb_app_signal_handler(): Network steering was not successful (status: ESP_FAIL)
................................ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
ZB_TRACE_LOG[0]: nwk/nwk_join.c:186    low lqi 0
.....[ 17414][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17415][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0006, asdu_length: 11
[ 17416][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 234, rx_time: 0
[ 17423][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17424][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8002, asdu_length: 17
[ 17425][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 234, rx_time: 0
.[ 17446][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17447][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0021, asdu_length: 22
[ 17448][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 234, rx_time: 0
[ 17449][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x65f7
[ 17454][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17455][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 1, src_addr_mode: 4, cluster_id: 0x0033, asdu_length: 2
[ 17456][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0065, src_short_addr: 0x65f7, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 17458][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17458][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 1, src_addr_mode: 0, cluster_id: 0x8033, asdu_length: 26
[ 17459][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0065, src_short_addr: 0x65f7, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 17461][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x65f7 with status 0
[ 17462][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 1, index 0, count 1
[ 17462][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 10, dst_endp 1, cluster_id 0x0402, dst_addr_mode 3
[ 17463][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 1
[ 17464][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 10
[ 17464][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 10
[ 17464][D][ZigbeeCore.cpp:734] bindingTableCb(): Device bound to EP 10 -> device endpoint: 1, ieee addr: 54:32:04:FF:FE:3D:DC:64
[ 17465][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
[ 17469][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17469][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x0021, asdu_length: 22
[ 17470][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0000, security_status: 0, lqi: 234, rx_time: 0
[ 17471][D][ZigbeeCore.cpp:760] searchBindings(): Requesting binding table for address 0x65f7
[ 17476][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17477][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 1, src_addr_mode: 0, cluster_id: 0x0033, asdu_length: 2
[ 17478][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0065, src_short_addr: 0x65f7, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 17481][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17482][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 1, src_addr_mode: 0, cluster_id: 0x8033, asdu_length: 47
[ 17483][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0065, src_short_addr: 0x65f7, profile_id: 0x0000, security_status: 0, lqi: 0, rx_time: 0
[ 17484][D][ZigbeeCore.cpp:568] bindingTableCb(): Binding table callback for address 0x65f7 with status 0
[ 17484][D][ZigbeeCore.cpp:572] bindingTableCb(): Binding table info: total 2, index 0, count 2
[ 17485][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 0: src_endp 10, dst_endp 1, cluster_id 0x0402, dst_addr_mode 3
[ 17485][D][ZigbeeCore.cpp:617] bindingTableCb(): Processing record 1: src_endp 10, dst_endp 1, cluster_id 0x0405, dst_addr_mode 3
[ 17486][D][ZigbeeCore.cpp:632] bindingTableCb(): Processing final chunk of binding table, total records: 2
[ 17486][D][ZigbeeCore.cpp:653] bindingTableCb(): Processing endpoint 10
[ 17487][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 10
[ 17487][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 17488][D][ZigbeeCore.cpp:699] bindingTableCb(): Processing binding record for EP 10
[ 17488][D][ZigbeeCore.cpp:739] bindingTableCb(): Device already exists, freeing allocated memory
[ 17489][D][ZigbeeCore.cpp:747] bindingTableCb(): Filling bounded devices finished
.[ 17531][I][ZigbeeCore.cpp:343] esp_zb_app_signal_handler(): Joined network successfully (Extended PAN ID: 54:32:04:ff:fe:3d:dc:64, PAN ID: 0xfe6d, Channel:14, Short Address: 0x65f7)
[ 17533][V][ZigbeeCore.cpp:775] setNVRAMChannelMask(): Channel mask set to 0x00004000

[ 17629][V][ZigbeeEP.cpp:448] getTime(): Reading time from endpoint 1
[ 17647][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17647][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 11
[ 17648][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 234, rx_time: 0
[ 17650][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x0) src endpoint(1) to dst endpoint(10) cluster(0xa)
[ 17650][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0xa), attribute(0x0), type(0xe2), value(102)
[ 17651][V][ZigbeeEP.cpp:516] zbReadTimeCluster(): Time attribute received
[ 17651][V][ZigbeeEP.cpp:517] zbReadTimeCluster(): Time: 17079205888
[ 17653][D][ZigbeeEP.cpp:398] setTime(): Setting time to 1736771430
[ 17654][V][ZigbeeEP.cpp:501] getTimezone(): Reading timezone from endpoint 1
[ 17672][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17673][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x000a, asdu_length: 11
[ 17674][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 234, rx_time: 0
[ 17675][V][ZigbeeHandlers.cpp:144] zb_cmd_read_attr_resp_handler(): Read attribute response: from address(0x0) src endpoint(1) to dst endpoint(10) cluster(0xa)
[ 17676][V][ZigbeeHandlers.cpp:153] zb_cmd_read_attr_resp_handler(): Read attribute response: status(0), cluster(0xa), attribute(0x2), type(0x2b), value(16)
[ 17677][V][ZigbeeEP.cpp:521] zbReadTimeCluster(): Timezone attribute received
[ 17677][V][ZigbeeEP.cpp:522] zbReadTimeCluster(): Timezone: 3600
[ 17679][D][ZigbeeEP.cpp:411] setTimezone(): Setting timezone to 3600
UTC time:
Monday, January 13 2025 12:30:30
Local time with timezone:
Monday, January 13 2025 13:30:30
Updated temperature sensor value to 43.70°C
[ 17681][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 17681][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
=========== After Setup Start ============
INTERNAL Memory Info:
------------------------------------------
  Total Size        :   434380 B ( 424.2 KB)
  Free Bytes        :   364652 B ( 356.1 KB)
  Allocated Bytes   :    61672 B (  60.2 KB)
  Minimum Free Bytes:   364524 B ( 356.0 KB)
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
[ 17701][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17702][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 17703][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 229, rx_time: 0
[ 17704][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 17705][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 17705][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 17705][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
[ 17866][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 17867][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 9
[ 17867][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 234, rx_time: 0
Updated temperature sensor value to 42.70°C
[ 18681][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 18681][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
[ 18712][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 18713][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 18713][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 234, rx_time: 0
[ 18715][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 18715][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 18716][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 18716][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[ 19682][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 19682][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[ 19709][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 19710][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 19710][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 234, rx_time: 0
[ 19712][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 19712][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 19713][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 19713][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 42.70°C
[ 20683][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 20683][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
[ 20711][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 20712][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 20712][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 229, rx_time: 0
[ 20714][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 20714][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 20715][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 20715][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[ 21684][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 21684][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[ 21713][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 21714][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 21715][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 229, rx_time: 0
[ 21716][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 21717][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 21717][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 21717][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[ 22685][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 22685][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 23686][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 23686][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 24687][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 24687][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 42.70°C
[ 25688][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 25688][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
[ 25708][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 25709][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 25709][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 229, rx_time: 0
[ 25711][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 25711][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 25712][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 25712][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[ 26689][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 26689][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[ 26710][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 26711][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 26711][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 234, rx_time: 0
[ 26713][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 26713][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 26714][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 26714][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 42.70°C
[ 27690][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 27690][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4270
[ 27712][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 27713][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 27714][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 229, rx_time: 0
[ 27715][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 27716][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 27716][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 27716][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[ 28691][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 28692][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[ 28714][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 28715][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 28716][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 224, rx_time: 0
[ 28717][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 28718][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 28718][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 28718][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[ 29692][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 29692][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 30693][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 30693][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 31694][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 31694][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 32694][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 32694][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 33695][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 33695][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 34695][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 34695][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 35695][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 35695][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 36696][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 36696][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 37696][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 37696][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[ 38010][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 38011][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 13
[ 38012][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 219, rx_time: 0
[ 38044][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 38044][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 38045][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 219, rx_time: 0
[ 38046][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 38047][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 38048][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 38048][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[ 38697][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 38697][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 39698][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 39698][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 40698][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 40698][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 41699][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 41699][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 42700][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 42700][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 43700][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 43700][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 44701][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 44701][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 45702][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 45702][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 46702][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 46702][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 47702][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 47702][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
[ 48037][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 48038][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 48038][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 214, rx_time: 0
[ 48040][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 48041][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 48041][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 48041][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
[ 48236][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 48237][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 13
[ 48238][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 214, rx_time: 0
[ 48268][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 48268][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 48269][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 214, rx_time: 0
[ 48270][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 48271][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 48272][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 48272][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 43.70°C
[ 48703][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 48703][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 43.70°C
[ 49704][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 49704][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4370
Updated temperature sensor value to 40.70°C
[ 50704][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 50704][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 4070
[ 50724][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 50725][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 50725][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 35, rx_time: 0
[ 50727][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 50728][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 50728][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 50728][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 39.70°C
[ 51705][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 51705][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3970
Updated temperature sensor value to 38.70°C
[ 52706][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 52706][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3870
[ 52727][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 52727][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 52728][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 81, rx_time: 0
[ 52729][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 52730][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 52731][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 52731][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 38.70°C
[ 53707][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 53707][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3870
Updated temperature sensor value to 38.70°C
[ 54708][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 54708][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3870
Updated temperature sensor value to 36.70°C
[ 55708][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 55708][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3670
[ 55732][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 55733][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 55734][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 81, rx_time: 0
[ 55735][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 55736][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 55736][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 55736][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 37.70°C
[ 56709][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 56710][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3770
Updated temperature sensor value to 38.70°C
[ 57710][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 57710][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3870
[ 57730][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[ 57731][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 10, src_endpoint: 1, dst_addr_mode: 2, src_addr_mode: 0, cluster_id: 0x0402, asdu_length: 5
[ 57731][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x65f7, src_short_addr: 0x0000, profile_id: 0x0104, security_status: 0, lqi: 229, rx_time: 0
[ 57733][V][ZigbeeHandlers.cpp:458] zb_cmd_default_resp_handler(): Received default response: from address(0x0), src_endpoint(1) to dst_endpoint(10), cluster(0x402) with status 0x0
[ 57733][V][ZigbeeEP.cpp:662] zbDefaultResponse(): Default response received for endpoint 10
[ 57734][V][ZigbeeEP.cpp:663] zbDefaultResponse(): Status code: Success
[ 57734][V][ZigbeeEP.cpp:664] zbDefaultResponse(): Response to command: 10
Updated temperature sensor value to 39.70°C
[ 58711][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 58711][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3970
Updated temperature sensor value to 39.70°C
[ 59712][V][ZigbeeTempSensor.cpp:108] setTemperature(): Updating temperature sensor value...
[ 59712][D][ZigbeeTempSensor.cpp:110] setTemperature(): Setting temperature to 3970
