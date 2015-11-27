#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "hex.h"

/* Write Hex file line to memory */
uint32_t WriteLine(uint8_t * buf, uint32_t address, uint32_t byteCount)
{
    uint32_t ret = 0;
    uint32_t i = 0;
    uint32_t adcounter = address;

    for(i = 0; i<byteCount*2;i = i + 2)
    {
        *((uint32_t*)adcounter) = StrToHex(buf,i,i+1);
        adcounter++;
    }
    
    return(HEX_LINE_SUCCESS);
}

/* Parse incoming hex file line */
int32_t ParseLine(uint8_t *workBuffer, uint32_t i)
{
    static uint32_t addressOffset = 0;
    uint8_t  byteCount  = 0; 
	uint32_t address    = 0;
    uint8_t  hexID      = 0;
    uint8_t  checkByte  = 0;
    uint8_t  cb         = 0;
    
    // decode fields of hex file line 
    byteCount  = StrToHex(workBuffer,0,1); 
	address    = StrToHex(workBuffer,2,5); 
	hexID      = StrToHex(workBuffer,6,7);
	checkByte  = StrToHex(workBuffer,i-2,i-1);
    
    //recalculate check byte and compare to received value 
	cb = CalcCB(workBuffer,i-2 , checkByte);
        
    if (cb == 0 )
    {
            
        /* write program data */
		if(hexID == 0x00)
		{
              WriteLine((workBuffer+8), (addressOffset + address), byteCount);
		}
		
		/* End of File */
		else if (hexID == 0x01) 
		{
			return(HEX_EOF);
		}
				
		/* extended segment address , no used/supported */
		else if (hexID == 0x02) 
		{
            //return(HEX_INVALID_CODE);
		}
				        
		/* Start Segment Address, sets instruction pointer to start of code base */
		else if (hexID == 0x03) 
		{
            //return(HEX_INVALID_CODE);
		}
				
		/* Extended linear address, 32 bit addressing, not used/supported */
		else if (hexID == 0x04) 
		{
            addressOffset =(StrToHex(workBuffer,8,11) << 16);
		}
				
		/* start linear address, not supported/used */
		else if (hexID == 0x05)
		{
		    //return(HEX_INVALID_CODE);
        }
				
		/* invalid hex ID */
		else
		{
		    return(HEX_INVALID_CODE);
        }
		
    }
	else
	{
    
	    return(HEX_CB_ERROR);
	}

	return(HEX_LINE_SUCCESS);
}

/* Convert subsection of a c string into a a hex integer */
uint32_t StrToHex(uint8_t * buf, uint32_t start, uint32_t end)
{
	uint32_t n  = 0;
	uint32_t c  = start;
	while(c <= end)
	{
		n = (n << 4) + AsciiToHex(buf[c]);
		c = c + 1;
	}
	
	return(n);
}

/* Convert ascii character to its hex representation 
   e.g. 'A' converts to 0xA */
int32_t AsciiToHex(char ascii) 
{

    int i = 0; 
    char Dict[16];   
    Dict[0]  = '0';
	Dict[1]  = '1';
	Dict[2]  = '2';
	Dict[3]  = '3';
	Dict[4]  = '4';
	Dict[5]  = '5';
	Dict[6]  = '6';
	Dict[7]  = '7';
	Dict[8]  = '8';
	Dict[9]  = '9';
	Dict[10] = 'A';
	Dict[11] = 'B';
	Dict[12] = 'C';
	Dict[13] = 'D';
	Dict[14] = 'E';
	Dict[15] = 'F';
	
	for (i = 0; i < 16;i++) 
	{
		if (Dict[i] == ascii)
		{
			return(i);
		}
	}

	return (-1);
}

/* Calculate checkbyte and compare to expected checkbyte value */
int32_t CalcCB(uint8_t *data, uint32_t len, uint8_t expected)
{
	uint32_t i;
	uint32_t sum = 0;
	for (i = 0; i< len;i=i+2)
	{
        sum += StrToHex(data,i,i+1);
	}
	
	sum = (~sum) + 1; 
	if ((uint8_t)sum != expected) 
	{
        return(-1);
	}
    else
    {
        return(0);
    }
}



