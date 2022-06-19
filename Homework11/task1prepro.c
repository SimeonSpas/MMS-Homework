#include <stdio.h>
#define MAX(x,y,z) (x) > (y) ? ((x) > (z) ? (x):((z) > (y) ? (z) : (y))) : (((y) > (z) ? (y) : (z)))
#define MIN(x,y,z) (x) < (y) ? ((x) < (z) ? (x):((z) < (y) ? (z) : (y))) : (((y) < (z) ? (y) : (z)))
#define SETBIT(mask,bit) mask|(1 << bit)
#define CLEARBIT(mask, bit) mask &~(1 << bit)
#define INVERSEBIT(mask,bit) mask^(1<<bit)
#define CHECKBIT(mask,bit) !!(mask&(1 << bit))
#define SWAP(a,b) ((a) ^= (b), (b) ^= (a), (a) ^=(b))



int main(void){
    int num = MAX(100,200,50);
    int num1 = MIN(10, 200,50);
    int num2 = SETBIT(10, 2);
    int num3 = CLEARBIT(10,1);
    int num4 = CHECKBIT(10,1);
    int num5 = INVERSEBIT(10,0);
    int x =50, y= 60;
    int num6 = SWAP(x, y);
    printf("%d\n", num);
    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
    printf("%d\n", num4);
    printf("%d\n", num5);
    printf("%d %d\n", x, y);
    return 0;
}

