#include <stdio.h>
#include <stdlib.h>

#define uint32 unsigned int 
#define uint8  char
#define uint16 unsigned short 

const unsigned int crc_table[] =
{
  0x4DBDF21C, 0x500AE278, 0x76D3D2D4, 0x6B64C2B0,
  0x3B61B38C, 0x26D6A3E8, 0x000F9344, 0x1DB88320,
  0xA005713C, 0xBDB26158, 0x9B6B51F4, 0x86DC4190,
  0xD6D930AC, 0xCB6E20C8, 0xEDB71064, 0xF0000000
};
  
volatile uint8 packet[1526];
union ethpacket 
{
    struct __attribute__ ((__packed__))
    {
        uint8  preamble[8];
        uint8  sourceMAC[6];
        uint8  destMAC[6];
        uint16 therType;
        uint8  payload[1500]; 
        uint32 fcs;
    };
    uint8 raw[1526];
};

struct __attribute__ ((__packed__)) testx
{
    uint8 x;
    uint8 y;
};

uint32 eth_crc32(uint8 *ethpacket, uint32 size)
{
  uint32 n, crc=0;

  for (n=8; n<(8+12+size); n++)
  {
    crc = (crc >> 4) ^ crc_table[(crc ^ (ethpacket[n] >> 0)) & 0x0F];  /* lower nibble */
    crc = (crc >> 4) ^ crc_table[(crc ^ (ethpacket[n] >> 4)) & 0x0F];  /* upper nibble */
  }
  
  return crc;
}


int main()
{

    union ethpacket x = {0x55,0x55,0x55,0x55,0x55,0x55,0x55,0xD5};
    struct testx * y;

    printf("size of union: %u\n",(unsigned int)sizeof(union ethpacket));
    printf("preamble[0] (struct way): %x\n",0xFF & (unsigned int)x.preamble[0]);
    printf("preamble[1] (struct way): %x\n",0xFF & (unsigned int)x.preamble[1]);
    printf("preamble[2] (struct way): %x\n",0xFF & (unsigned int)x.preamble[2]);
    printf("preamble[3] (struct way): %x\n",0xFF & (unsigned int)x.preamble[3]);
    printf("preamble[4] (struct way): %x\n",0xFF & (unsigned int)x.preamble[4]);
    printf("preamble[5] (struct way): %x\n",0xFF & (unsigned int)x.preamble[5]);
    printf("preamble[6] (struct way): %x\n",0xFF & (unsigned int)x.preamble[6]);
    printf("preamble[6] (struct way): %x\n",0xFF & (unsigned int)x.preamble[7]);
    
    printf("array test:\n\n");
    
    printf("preamble[0] (array way): %x\n",0xFF & (unsigned int)x.raw[0]);
    printf("preamble[1] (array way): %x\n",0xFF & (unsigned int)x.raw[1]);
    printf("preamble[2] (array way): %x\n",0xFF & (unsigned int)x.raw[2]);
    printf("preamble[3] (array way): %x\n",0xFF & (unsigned int)x.raw[3]);
    printf("preamble[4] (array way): %x\n",0xFF & (unsigned int)x.raw[4]);
    printf("preamble[5] (array way): %x\n",0xFF & (unsigned int)x.raw[5]);
    printf("preamble[6] (array way): %x\n",0xFF & (unsigned int)x.raw[6]);
    printf("preamble[6] (array way): %x\n",0xFF & (unsigned int)x.raw[7]);
    
    y = (struct testx *)malloc(sizeof(struct testx));
    
    y->x = 0x55;
    y->y = 0xFF;
    
    printf("x value: %x\n",(0xFF) & y->x);
    printf("y value: %x\n",(0xFF) & y->y);
    
    printf("x value: %x\n",(0xFF) & ((char *)y)[0]);
    printf("y value: %x\n",(0xFF) & ((char *)y)[1]);
    
    
    
	return(0);
}
