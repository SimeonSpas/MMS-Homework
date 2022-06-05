#include <stdio.h>
#include <math.h>
int main()
{
    double mass, height, BMI;
    printf("Enter mass: ");
    scanf("%lf", &mass);
    printf("Enter height: ");
    scanf("%lf", &height);
    printf("The body mass index is: %.2lf\n", BMI = mass / pow(height, 2));
    return 0;
}