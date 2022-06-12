#include "my32bitmasks.h"

int main(){
    uint32_t maskArr[] = {1, 5, 10, 15,30};
    setBit(maskArr, 5, 0);
    clearBit(maskArr, 5, 0);
    checkBit(maskArr, 5, 0);
    return 0;
}
//gcc 32bitmask.c my32bitmasks.c
//my header file -> my32bitmasks.h
