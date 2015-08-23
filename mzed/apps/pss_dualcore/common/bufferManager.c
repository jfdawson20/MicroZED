#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "bufferManager.h"
/**
 * @file bufferManager.c  
 * @author Jack Dawson
 * @date 08/2/2015
 * @brief contains functions to create and manipulate packet buffers  	
*/


/**
 * @brief 
 *
 * Detailed explanation.
 */

struct packetDescriptorNode* CreateDescriptorList(uint32_t size,uint32_t buffersize)
{
	/* variable decs */
        struct packetDescriptorNode* temp; 
        struct packetDescriptorNode* prev; 
        struct packetDescriptorNode* head; 
	uint8_t* frameBuffer;
	uint32_t* packetDescriptorList;
	uint32_t i,descriptorIndex;
	
	/* Create Packet Descriptor array in memory */
	packetDescriptorList = (uint32_t*)malloc(sizeof(uint32_t)*size*2);
	descriptorIndex = 2;

	/* allocate head */	
	prev = (struct packetDescriptorNode*)malloc(sizeof(struct packetDescriptorNode));
	prev->id       = 0;
	prev->previous = prev;
	prev->next     = prev;
	prev->packetDescriptor = packetDescriptorList;	
	head = prev;

	/* create linked list */
	for(i =1;i<size;i++)
	{	
		/* create temp node */
		temp = (struct packetDescriptorNode*)malloc(sizeof(struct packetDescriptorNode));

		/* create frame buffer*/
		frameBuffer = (uint8_t*)malloc(sizeof(uint8_t)*buffersize*size);
		
		/* update previous nodes next field */
		prev->next     		= temp;

		/* update new node fields*/
		temp->previous 		  = prev;
		temp->next                = head;
		temp->id       		  = i;
		temp->packetDescriptor 	  = packetDescriptorList + descriptorIndex;
		
		/* set first word of packetDescriptor to base address of frame buffer */
		/* if the descriptor has the last frame buffer, set bit 1 to 1 (wrap field)*/
		if(i == (size-1))
		{	
			(*temp->packetDescriptor) = (frameBuffer | 0x00000002);
		}
		else
		{
			(*temp->packetDescriptor) = frameBuffer;
		}
		/* update previous pointer and descriptor Index */
		prev 			= temp;
		descriptorIndex 	= descriptorIndex + 2; 
	}	

	
	return(head);
}

struct packetDescriptorNode* FreeBufferResources(struct packetDescriptorNode* buffer,uint32_t listSize, uint32_t bufferSize)
{
	uint32_t i;
	for(i=0;i<listSize;i++)
	{
		for(i=0;i<bufferSize;i++)
		{
			free(packetDescriptorMode->
		}
	}	
}
}
