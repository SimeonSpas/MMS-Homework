#include <stdio.h>
#include <stdint.h>
#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8 5
#define TUINT16 6
#define TUINT32 7
#define TUINT64 8
void printValue(const void* valuePtr, uint8_t flag){
    int a = 5;
    if (flag == TINT){
        printf("%d\n", *(int*)valuePtr);
    }else if (flag == 2){
        printf("%c", *(char*)valuePtr);
    }else if (flag == 3){
        printf("%.2lf", *(double*)valuePtr);
    }else if (flag == 4){
        printf("%f", *(float*)valuePtr);
    }else if (flag == 5){
        printf("%u", *(uint8_t*)valuePtr);
    }else if (flag == 6){
        printf("%u", *(uint16_t*)valuePtr);
    }else if (flag == 7){
        printf("%u", *(uint32_t*)valuePtr);
    }else if (flag == 8){
        printf("%lu", *(uint64_t*)valuePtr);
    }
}

int main(){
    int opt;
    int num = 23;
    char sym = 'z';
    double d = 56.7;
    float f = 45.3;
    uint8_t u = 1;
    uint16_t u1 = 3;
    uint32_t u2 = 5;
    uint64_t u3 = 1245435;
    scanf("%d", &opt);
    switch(opt){
        case 1: printValue(&num, TINT);
        break;
        case 2: printValue(&sym, TCHAR);
        break;
        case 3: printValue(&d,TDOUBLE);
        break;
        case 4: printValue(&f, TFLOAT);
        break;
        case 5: printValue(&u, TUINT8);
        break;
        case 6: printValue (&u1, TUINT16);
        break;
        case 7: printValue(&u2, TUINT32);
        break;
        case 8: printValue(&u3, TUINT64);
    }

    return 0;
}