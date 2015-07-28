

uint32 eth_crc32(struct ethpacket)
{
  unsigned int n, crc=0;

  for (n=0; n<sizeof(ethpacket); n++)
  {
    crc = (crc >> 4) ^ crc_table[(crc ^ (ethpacket[n] >> 0)) & 0x0F];  /* lower nibble */
    crc = (crc >> 4) ^ crc_table[(crc ^ (ethpacket[n] >> 4)) & 0x0F];  /* upper nibble */
  }
  
  return crc;
}