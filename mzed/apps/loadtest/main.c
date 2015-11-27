#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "xil_io.h"
#include "xil_mmu.h"
#include "xil_exception.h"
#include "xpseudo_asm.h"
#include "sleep.h"

//#include "bufferManager.h"

int main()
{

	//Disable cache on (upper 64k) of OCM
	//Xil_SetTlbAttributes(0xFFFF0000,0x14de2);
	
    char buf[255];
	char command[16];
    uint32_t ret = 0;

    while(1)
    {
        printf("hello from loaded application\n");
        sleep(1);
    }
	return(0);
}
