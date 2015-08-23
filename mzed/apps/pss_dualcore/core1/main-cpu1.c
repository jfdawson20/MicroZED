#include <stdlib.h>
#include <stdio.h>
#include "xparameters.h"
#include "xil_io.h"
#include "xil_mmu.h"
#include "xil_cache.h"
#include "xil_exception.h"
#include "xscugic.h"
#include "sleep.h"


#define semaphore  (*(volatile unsigned long *)(0xFFFF0000))

int main()
{
    int Status;


    //Disable cache on OCM
    // S=b1 TEX=b100 AP=b11, Domain=b1111, C=b0, B=b0
    Xil_SetTlbAttributes(0xFFFF0000,0x14de2);

     print("CPU1: init_platform\n\r");

     while(1)
     {
     	while(semaphore == 0){};
     	print("CPU1: Hello World CPU 1\n\r");
     	sleep(1);
	semaphore = 0;
     }

     return(0);
}
