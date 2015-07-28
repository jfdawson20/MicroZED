#include <stdlib.h>
#include <stdio.h>
#include "xil_io.h"
#include "xil_mmu.h"
#include "xil_exception.h"
#include "xpseudo_asm.h"
#include "xscugic.h"

#define sev() __asm__("sev")
#define CPU1STARTADR 0xfffffff0
#define semaphore  (*(volatile unsigned long *)(0xFFFF0000))

int main()
{
	int Status;

    //Disable cache on (upper 64k) of OCM
    //S=b1 TEX=b100 AP=b11, Domain=b1111, C=b0, B=b0
    Xil_SetTlbAttributes(0xFFFF0000,0x14de2);           

    //init semaphore flag to 0
    semaphore = 0;

    print("CPU0: writing startaddress for cpu1\n\r");

    Xil_Out32(CPU1STARTADR, 0x1FF80000);

    dmb(); // data memory sync, waits until write has finished

    print("CPU0: sending the SEV to wake up CPU1\n\r");
    //send multicore event signal to wake core 1
    sev();

    while(1){

		print("CPU0: Hello World CPU 0\n\r");
		semaphore = 1;
        
        //block on semaphore lock 
		while(semaphore == 1);

    }
	return(0);
}
