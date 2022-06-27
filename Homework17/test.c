#include <stdio.h>
#include <stdlib.h>

void print(int* res, int count);

int main(int argc, char** argv){
    int a,qoutient, remainder;
    int result;
    for (int i = 1; i < ((argc / 2)+ 1); i++){
        a = atoi(argv[i]);
        printf("a = %d", a);
        remainder = a % 10;
        qoutient = a / 10;
        result = remainder + qoutient;
        //printf("result: %d ", result);
    }
    putchar('\n');
    
        int a1,qoutient1, remainder1;
    int result1;
      for (int i = ((argc / 2) + 1); i < argc; i++){
        a1 = atoi(argv[i]);
        printf("a1 = %d", a1);
        remainder1 = a % 10;
        qoutient1 = a / 10;
        result1 = remainder + qoutient;
        //printf("result1: %d \n", result1);
    }
    
    return 0;
}
void print(int* res, int count){
     for (int i = 0; i < count; i++){
            printf("%d ", *res);
        }
}