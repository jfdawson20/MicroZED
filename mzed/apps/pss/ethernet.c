#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t* CreateEthernetPacket(uint8_t* sourceMac, uint8_t* destMac, uint8_t* ethType, uint8_t* payload, uint32_t size)
{	
	uint8_t* packet; 
	packet = (uint8_t*)malloc(sizeof(uint8_t)*(size+14));
	
	memcpy(packet,sourceMac,6);
	memcpy(packet+6,destMac,6);
	memcpy(packet+12,ethType,2);
	memcpy(packet+14,payload,size);
	
	return(packet);
}


