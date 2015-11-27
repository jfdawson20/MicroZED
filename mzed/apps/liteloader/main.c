#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "xil_io.h"
#include "xil_mmu.h"
#include "xil_exception.h"
#include "xpseudo_asm.h"
#include "sleep.h"
#include "hex.h"
//#include "bufferManager.h"

void FsblHandoffExit(u32 FsblStartAddr);

int main()
{

	//Disable cache on (upper 64k) of OCM
	//Xil_SetTlbAttributes(0xFFFF0000,0x14de2);
	
    char buf[255];
	char command;
    int32_t ret = 0;
    uint32_t executeAddr;
    //sleep(1);
    //printf("staring 3\n");
   //sleep(1);
    //printf("staring 2\n");
    //sleep(1);
    //printf("staring 1\n");

    while(1)
    {
        scanf("%s",buf);
        command = buf[0];

        if(command == 'l') 
        {
            printf("+\n");
            
            scanf("%s",buf);

            ret = ParseLine(buf+1,strlen(buf+1));
            while(ret != HEX_EOF)
            {
                
                if(ret < 0 )
                {
                    printf("-\n");
                }
                else
                {
                    printf("+\n");
                }
                scanf("%s",buf);
                ret = ParseLine((buf+1),strlen(buf+1));
            }
            
            buf[0] = '\0';
        }
        else if(command == 'x')
        {
            executeAddr = StrToHex(buf,3,10);
            printf("starting execute program at address: %x\n", executeAddr);
            FsblHandoffExit((u32)executeAddr);

            printf("after user program\n");
            while(1)
            {
                printf("after program\n");
                sleep(1);
            }

        }

        else if(command == 'r')
        {
            printf("starting reg read\n");
        }

        else if(command == 'w')
        {   
            printf("starting reg write\n");
        }
        else
        {
            printf("?\n");
        }

    }
	return(0);
}
