#include <stdio.h>
#include <stdint.h>
float* printMask(float);
int main(){
    float mask = 0;
    printf("Enter a number: ");
    scanf("%f", &mask);
    printMask(mask);
    return 0;
}

float* printMask(float checkmask){
    float bit = 0;
    for (bit = 0; bit < 31; bit++){
        printf("%u ", !!((int)checkmask&(1 << (int)bit))); //nai mladshiq bit e nai ot lqvo
           
    }
}
