#ifndef ETH_H
#define ETH_H 

uint8* CreateEthernetPacket(uint8* sourceMac,uint8* destMac, uint8* ethType, uint8* packet, uint32 size);
#endif 
