#include <stdio.h>
#include <stdlib.h>
#include "../bufferManager.h"

int main()
{
	struct packetDescriptorNode *descriptorList;	
	descriptorList = CreateDescriptorList(32);
	int i = 0;
	for(i=0;i<32;i++)
	{
		printf("ID: %d\n",descriptorList->id);
		descriptorList = descriptorList->next;
		
	}
	return(0);
}
