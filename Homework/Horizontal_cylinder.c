#include <stdio.h>
#include <math.h>
int main ()
{
    
    double H, R, L, x;
    double Area, Volume;
    printf("Enter the height of the cylinder: ");
    scanf("%lf", &H);
    printf("Enter the radius of the cylinder: ");
    scanf("%lf", &R);
    printf("Enter the length of the cylinder: ");
    scanf("%lf", &L);
    Area =((R - H)/R)*pow(R, 2) - (R - H)*sqrt(2*R*H - pow(H, 2));
    x = pow(cos(Area), -1);
    printf("%lf", x);
    Volume = x * L;
    printf("The volume of the cylinder is: %lf", Volume);
    return 0;
}