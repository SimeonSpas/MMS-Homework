#include <stdint.h>
#include <stdio.h>
#ifndef __MY_32_BIT_MASKS_
#define __MY_32_BIT_MASKS_
int clearBit(uint32_t*, size_t, size_t);
int setBit(uint32_t*, size_t, size_t);
int checkBit(uint32_t*, size_t, size_t);
#endif