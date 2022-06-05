#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main ()
{
    float a, b, c;
    float max = INT_MIN;
    for (a = 0; a < 3; a++){
        scanf("%f", &b);
        if (b > max){
            max = b;
        }
    }printf("the max number is: %.2f\n", max);
    
    return EXIT_SUCCESS;
} 
// ./task1 < numbers.txt - chete chislata ot teksta
// ./task1 >> numbers.txt. Sled tova -> cat numbers.txt, za da se vidi koe e nai golqmoto chislo
// ./task1 >> numbers.txt | cat numbers.txt (vuzmojna kombinaciq)
