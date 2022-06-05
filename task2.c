#include <stdio.h>
int main ()
{
    int a, b, result; 
    printf("Enter 2 integers: ");
    scanf("%d %d", &a, &b);
    result = (a || b) && !(a && b);
    printf("result is: %d", result);
    return 0;
}