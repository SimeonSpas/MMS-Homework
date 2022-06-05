#include <stdio.h>
#include <math.h>
int main()
{
    double mass, height, BMI;
    printf("Enter mass: ");
    scanf("%lf", &mass);
    printf("Enter height: ");
    scanf("%lf", &height);
    printf("The body mass index is: %.4lf\n", BMI =1.3*(mass / pow(height, 2.5)));
    return 0;
}