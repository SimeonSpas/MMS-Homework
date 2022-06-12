#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t* );

int main(){
    uint16_t x;
    swapBytes(&x);
    return 0;
}

void swapBytes(uint16_t* word){
    uint16_t temp;
    temp = *word;
    *word = (1 << 16) -1; // The first bit takes the 16-th bit value
    temp = (1>>16)+1;

    printf("%u %u\n",*word, temp);
}

//VTORI VARIANT S MASIV
/*#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t* );

int main(){
    uint16_t arr[] = {1, 65535};  
    swapBytes(arr);
    return 0;
}

void swapBytes(uint16_t* word){
    *word = (1 << 16) -1; // The first bit takes the 16-th bit value
    *(word + 1) = (1 >> 16) +1; //The last bit takes the first bit value;
    printf("%u, %u\n", *word, *(word + 1));
}*/