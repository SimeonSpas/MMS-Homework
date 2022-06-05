#include <stdio.h>
#include <math.h>
int quadEq(double a, double b, double c, double *S, double *P);

int main (){
     double a = 0, b = 0, c = 0, x1, x2;
    printf("Enter 3 numbers: \n");
    scanf("%lf %lf %lf", &a, &b, &c);
    quadEq(a, b, c, &x1, &x2);
    printf("x1 = %.2lf\nx2 = %.2lf", x1, x2);
    
    return 0;   
}
int quadEq(double a, double b, double c, double *S, double *P){
    double D, d ,e;
    D = b*b - 4 * a * c;
    printf("%.2lf\n", D); //prints the number.
    if (D < 0){
        printf("There is no real roots:\n");
        return -1;
    }else if(D ==  0){
        *S = -b / (2*a);
        *P = -b / (2*a);
    }else if (D > 0){
        *S = (-b + sqrt(b*b + 4*a*c))/(2*a);
        *P = (-b - sqrt(b*b - 4*a*c))/(2*a);
    }
    return 0;
    
}