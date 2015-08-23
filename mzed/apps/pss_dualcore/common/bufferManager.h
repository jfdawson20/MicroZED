#ifndef BUF_MAN_H
#define BUF_MAN_H 
#include <stdint.h>

struct packetDescriptorNode
{
	uint32_t id; 
	struct packetDescriptorNode* previous;
	struct packetDescriptorNode* next;
	uint32_t* packetDescriptor;
};

struct packetDescriptorNode* CreateDescriptorList(uint32_t size);

#endif
