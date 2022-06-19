#include <stdio.h>
#include <stdint.h>

unsigned char CheckBit(unsigned int);

int main(){
    uint16_t n = 0x4000;
    CheckBit(n);
    return 0;
}
unsigned char CheckBit(unsigned int uValue){
    int result = 0, count = 0;
    for (int i = 0; i < 15; i++){
         result = !!(uValue&(1<<i));
         if (result == 1){
             count++;
         }
    }
    if(count == 1){
        printf("%x\n", count);
    }else {
        return 0;
     }
}



/*Write C function which takes 16 bit number and should determine whether exactly one bit in this
number is set. If one bit is set, the function should return "1" otherwise "0". The prototype of function is
"unsigned char CheckBit(unsigned int uValue)".akes 16 bit number and should determine whether exactly one bit in this
number is set. If one bit is set, the function should return "1" otherwise "0". The prototype of function is
"unsigned char CheckBit(unsigned int uValue)".

Example:
Input = 0x0400, Output = 0x01
Input = 0x0600, Output = 0x00
Input = 0x0000, Output = 0x00*/