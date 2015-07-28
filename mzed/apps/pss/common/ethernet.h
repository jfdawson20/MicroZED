#ifndef ETH_H
#define ETH_H 

/* CRC32 Polynomial Coefficent Table */
const unsigned int crc_table[] =
  {
    0x4DBDF21C, 0x500AE278, 0x76D3D2D4, 0x6B64C2B0,
    0x3B61B38C, 0x26D6A3E8, 0x000F9344, 0x1DB88320,
    0xA005713C, 0xBDB26158, 0x9B6B51F4, 0x86DC4190,
    0xD6D930AC, 0xCB6E20C8, 0xEDB71064, 0xF0000000
  };
  
  
/* Ethernet Packet Union */
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
    
uint32 eth_crc32(union ethpacket);

#endif 