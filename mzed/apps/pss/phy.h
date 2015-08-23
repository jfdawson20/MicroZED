#ifndef JPHY_H
#define JPHY_H

uint16_t ReadPhyRegister(uint8_t devAddress, uint8_t regAddress, uint8_t clause);
uint32_t D_IdentifyPhys(uint8_t clause);
#endif 
