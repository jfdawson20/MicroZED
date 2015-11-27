#include <stdio.h>
#include <stdlib.h>
#include "gem.h"
#include <stdint.h>

uint16_t ReadPhyRegister(uint8_t devAddress, uint8_t regAddress, uint8_t clause)
{
	uint32_t data = 0; 
	
	//set clause field 
	data = (data | (1 << 30));
	//printf("data0: %x\n",data);	

	//set op field to read 
	data = (data | (2 << 28));

	//set phy address 
	data = (data | (devAddress << 23));
	
	//set register address 
	data = (data | (regAddress << 18));

	//set must_10 field to... 0b10
	data = (data | (2 << 16));
	
	//write val
	Xil_Out32((XEMACPS0_BASE+XEMACPS_PHYMNTNC_OFFSET),data);

	//wait for phy not busy 
	data = Xil_In32(XEMACPS0_BASE+XEMACPS_NWSR_OFFSET);
	
	//printf("return : %x\n",data);
	while((data & 0x4) != 0x4)
	{
		data = Xil_In32(XEMACPS0_BASE+XEMACPS_NWSR_OFFSET); 
	}	

	data = Xil_In32(XEMACPS0_BASE+XEMACPS_PHYMNTNC_OFFSET);
	return((uint16_t)data);
}

uint32_t D_IdentifyPhys(uint8_t clause)
{

	uint32_t i = 0;
	uint16_t reg = 0;
	for (i =0;i<32;i++)
	{
		printf("Register Address %d\n",i);
		reg = ReadPhyRegister(0,i,clause);

		printf("\tDevice Register %x\n",reg);
	}
	return (0);
} 
