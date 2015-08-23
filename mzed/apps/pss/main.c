#include <stdlib.h>
#include <stdio.h>
#include "xil_io.h"
#include "xil_mmu.h"
#include "xil_exception.h"
#include "xpseudo_asm.h"

//#include "bufferManager.h"

int main()
{

	//Disable cache on (upper 64k) of OCM
	Xil_SetTlbAttributes(0xFFFF0000,0x14de2);

	//create pointers for Rx & Tx buffer descriptor lists	
	struct packetDescriptorNode* rxDescriptorList;
	struct packetDescriptorNode* txDescriptorList;

	//create each buffer list 
	rxDescriptorList = (struct packetDescriptorNode*) CreateDescriptorList(128,128);
	txDescriptorList = (struct packetDescriptorNode*) CreateDescriptorList(128,128);

	//init gigE controller 0 MAC
	GEM0ControllerConfig(0,0,128);

	//scan for phy devices 
	int ret = -1;
	ret = D_IdentifyPhys(2);
	while(1){

	}
	return(0);
}
