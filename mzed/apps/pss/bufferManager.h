#ifndef BUF_MAN_H
#define BUF_MAN_H 
#include <stdint.h>

volatile uint32_t ocmBufferPointer;
volatile uint32_t ocmBufferLimit;

struct packetDescriptorNode
{
	uint32_t id; 
	struct packetDescriptorNode* previous;
	struct packetDescriptorNode* next;
	uint32_t* packetDescriptor;
};

struct packetDescriptorNode* CreateDescriptorList(uint32_t size,uint32_t bufferSize);

#endif
