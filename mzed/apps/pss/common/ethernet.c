#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8* CreateEthernetPacket(uint8* sourceMac, uint8* destMac, uint8* ethType, uint8* payload, uint32 size)
{	
	uint8* packet; 
	packet = (uint8*)malloc(sizeof(uint8)*(size+14));
	
	memcpy(packet,sourceMac,6);
	memcpy(packet+6,destMac,6);
	memcpy(packet+12,ethType,2);
	memcpy(packet+14,payload,size);
	
	return(packet);
}


