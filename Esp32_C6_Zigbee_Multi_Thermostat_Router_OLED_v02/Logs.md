Logfile of the coordinator:

1. Short address: 0x7663 | IEEE: a4:c1:38:a7:e0:f2:57:3e LQI: 0
2. Short address: 0x10b7 | IEEE: 54:32:04:ff:fe:3d:dc:64 LQI: 5

Current LQI devices: 3
0 10b7:46.6   5R
1 ca53:22.9  15I
2 7663: 0.0   0E
3 0000: 0.0   0E
4 0000: 0.0   0E

Logfile of the router:

REQUEST:
get the LQI values from the first router 0x10b7
start getLQIFromRouter for 0x10b7 (Index: 0)
done getLQIFromRouter

RESPONSE:
[1500186][D][ZigbeeCore.cpp:473] zb_apsde_data_indication_handler(): APSDE INDICATION - Received APSDE-DATA indication, status: 0
[1500187][D][ZigbeeCore.cpp:474] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_endpoint: 0, src_endpoint: 0, dst_addr_mode: 255, src_addr_mode: 0, cluster_id: 0x8031, asdu_length: 71
[1500188][D][ZigbeeCore.cpp:478] zb_apsde_data_indication_handler(): APSDE INDICATION - dst_short_addr: 0x0000, src_short_addr: 0x10b7, profile_id: 0x0000, security_status: 0, lqi: 5, rx_time: 0
Ready: All 3 Neighbors of 0x10b7 stored.

--- Current Router Neighbor table ---
Short Address: 0x0000 | IEEE: 58:8C:81:FF:FE:30:3E:20 | LQI:  45 | Depth: 0
Short Address: 0x6D64 | IEEE: 9C:9E:6E:FF:FE:43:83:68 | LQI:   0 | Depth: 2
Short Address: 0xCA53 | IEEE: A4:C1:38:A8:3F:D4:A0:B8 | LQI:  56 | Depth: 2
--- Current Router Neighbor table END ---
