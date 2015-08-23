#include <stdlib.h>
#include <stdio.h>
#include "xparameters.h"
#include "xil_io.h"
#include "gem.h"

uint32_t GEM0ControllerInit()
{
	uint32_t ctrlWord;
	
	//clear network control register 
	ctrlWord = 0x00000000;
	Xil_Out32((XEMACPS0_BASE+XEMACPS_NWCTRL_OFFSET),ctrlWord);

	//clear stats register
	ctrlWord = (0x1 << 5);	
	Xil_Out32((XEMACPS0_BASE+XEMACPS_NWCTRL_OFFSET),ctrlWord);

	//clear rx stats
	ctrlWord = 0x0000000F;
	Xil_Out32((XEMACPS0_BASE+XEMACPS_RXSR_OFFSET),ctrlWord);
	
	//clear tx stats 
	ctrlWord = 0x000000F0;
	Xil_Out32((XEMACPS0_BASE+XEMACPS_TXSR_OFFSET),ctrlWord);
	
	//disable interrupts 
	ctrlWord = 0x07FFFFFF;
	Xil_Out32((XEMACPS0_BASE+XEMACPS_IDR_OFFSET),ctrlWord);

	//clear buffer queues 
	ctrlWord = 0x00000000;
	Xil_Out32((XEMACPS0_BASE+XEMACPS_RXQBASE_OFFSET),ctrlWord);
	Xil_Out32((XEMACPS0_BASE+XEMACPS_TXQBASE_OFFSET),ctrlWord);

	return(0);
}

uint32_t GEM0ControllerConfig(uint32_t MAC_ADDR_MSW,uint32_t MAC_ADDR_LSW,uint32_t bufferSize)
{
	uint32_t ctrlWord;
	ctrlWord = 0;

	/* configure controller net.cfg  */
	
	//set checksum offload 
	ctrlWord = (ctrlWord | (1<<24));

	//dont copy pause frames to memory 
	ctrlWord = (ctrlWord | (1<<23));

	//set MDC clock diviser to max (edit once clock rate is chosen)
	ctrlWord = (ctrlWord | (7<<20));

	//remove FCS from packet before mem copy 
	ctrlWord = (ctrlWord | (1 << 17));

	//enable full duplex operation 
	ctrlWord = (ctrlWord | (1 << 1));
	//set default speed to 100 mb/s
	ctrlWord = (ctrlWord | 1);

	//write register 	
	Xil_Out32((XEMACPS0_BASE+XEMACPS_NWCFG_OFFSET),ctrlWord);

	//set MAC Address 
	Xil_Out32((XEMACPS0_BASE+XEMACPS_LADDR1L_OFFSET),MAC_ADDR_LSW);
	Xil_Out32((XEMACPS0_BASE+XEMACPS_LADDR1H_OFFSET),MAC_ADDR_MSW);

	/* DMA controller config */
	//set buffer size
	ctrlWord = (ctrlWord | (bufferSize << 23));
	
	//set Tx checksum offload 
	ctrlWord = (ctrlWord | (1 << 11));

	//set tx packet buffer size to 4Kb
	ctrlWord = (ctrlWord | ( 1 <<10));
	
	//set rx packet buffer size to 8 Kb
	ctrlWord = (ctrlWord | (3 << 9));

	//set little endian mode 
	ctrlWord = (ctrlWord | (1 << 7));

	//attmept to use INCR16 AHB burst writes 
	ctrlWord = (ctrlWord | (1 << 4));

	//write word 
	Xil_Out32((XEMACPS0_BASE+XEMACPS_DMACR_OFFSET),ctrlWord);

	/* program control register */

	ctrlWord = Xil_In32((XEMACPS0_BASE+XEMACPS_NWCTRL_OFFSET));
	//enable MDIO
	ctrlWord = (ctrlWord | (1 << 4));
	
	//enable Tx Now?
	//ctrlWord = (ctrlWord | (1 << 3))

	//enable Rx Now?
	//ctrlWord = (ctrlWord | (1 << 2));

	//write control word
	Xil_Out32((XEMACPS0_BASE+XEMACPS_NWCTRL_OFFSET),ctrlWord);

	/* Phy Configuration */
	
	return(0);
	
}
