#include <stdio.h>
#include <stdint.h>
int setBit(uint32_t* maskArr, size_t n, size_t bit){
    if (bit -1 < -1){
        fprintf(stderr, "Invalid bit\n");
        return -1;
    }
    for (int i = 0; i < n; i++){
        maskArr[i] |= (1 << bit);
        printf("The %ld bit of array element %u is set to: %u\n",bit,i ,!!(maskArr[i] &= (1 << bit)));
    }
}
int clearBit(uint32_t* maskArr, size_t n, size_t bit){
    if (bit -1 < -1){
        fprintf(stderr, "Invalid bit\n");
        return -1;
    }
    for (int i = 0; i < n; i++){
        maskArr[i] &= ~(1 << bit);
        printf("The %ld bit of array element %u is set to: %u\n",bit,i ,!!(maskArr[i] &= (1 << bit)));
    }
}
int checkBit(uint32_t* maskArr, size_t n, size_t bit){
      if (bit -1 < -1){
        fprintf(stderr, "Invalid bit\n");
        return -1;
    }
    for (int i = 0; i < n; i++){
        printf("%u\n",!!(maskArr[i] &= (1 << bit)));
    }
}