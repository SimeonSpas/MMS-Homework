#include <stdio.h>
#include <stdarg.h>

unsigned counT(unsigned mask){
    int bitscnt = 0;
    while (mask){
        bitscnt += (mask & 1);
        mask >>= 1;
        
    }
    return bitscnt;
}

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...){
    unsigned check = 0, mask1 = 0;
    va_list mask;
    va_start (mask, bitscnt);
    for (int i = 0; i < count; i++){
        mask1 = 0;
        mask1 += va_arg(mask, unsigned);
        if (counT(mask1) == bitscnt){
            check++;
        }
    }
    va_end(mask);
    return check;
}
    
int main(){
    printf("%u\n", bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa));
    return 0;
}