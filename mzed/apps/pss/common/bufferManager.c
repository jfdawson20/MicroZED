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

struct packetDescriptorNode* CreateDescriptorList(uint32_t size)
{
	/* variable decs */
        struct packetDescriptorNode* temp; 
        struct packetDescriptorNode* prev; 
        struct packetDescriptorNode* head; 
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
		
		/* update previous nodes next field */
		prev->next     		= temp;

		/* update new node fields*/
		temp->previous 		= prev;
		temp->next              = head;
		temp->id       		= i;
		temp->packetDescriptor 	= packetDescriptorList + descriptorIndex;
		
		/* update previous pointer and descriptor Index */
		prev 			= temp;
		descriptorIndex 	= descriptorIndex + 2; 
	}	

	
	return(head);
}


