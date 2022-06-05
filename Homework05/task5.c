#include <stdio.h>
#include <stdint.h>
unsigned onesCount(uint64_t mask){
    unsigned count = 0;
    while(mask){
        count += mask & 1;
        mask >>= 1;
    }
    return count;
}
int main ()
{
    int mask;
    printf("%d\n", onesCount(mask));
    return 0;
}