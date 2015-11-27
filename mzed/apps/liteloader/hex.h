#ifndef HEX_H
#define HEX_H

//return codes 
#define HEX_EOF 0
#define HEX_CB_ERROR -1
#define HEX_LINE_SUCCESS 1
#define HEX_INVALID_CODE -2

uint32_t WriteLine(uint8_t* buf, uint32_t address, uint32_t byteCount);
int32_t ParseLine(uint8_t* workBuffer, uint32_t i);
uint32_t StrToHex(uint8_t *buf, uint32_t start, uint32_t end);
int32_t AsciiToHex(char ascii);
int32_t CalcCB(uint8_t *data, uint32_t len, uint8_t expected);


#endif 
