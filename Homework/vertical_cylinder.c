#include <stdio.h>
#include <math.h>
int main ()
{
    double H, R, V;
    const double pi = 3.14159265359;
    printf("Enter the height of the cylinder: ");
    scanf("%lf", &H);
    printf("Enter the radius of the cylinder: ");
    scanf("%lf", &R);
    V = pi*pow(R, 2)*H;
    printf("The volume of the cylinder is: %lf \n", V);
    return 0;

}