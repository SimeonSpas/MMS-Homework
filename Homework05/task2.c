#include <stdio.h>
#include <math.h>
int triangle(double a, double b, double c,double *S, double *P);
int main(){
    double a, b, c, perimeter, area;
    printf("Enter sides of the triangle: \n");
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
        if (!triangle(a, b, c, &area, &perimeter)){
        printf("S = %lf, P = %lf\n", area, perimeter);

    }
    }
    return 0;
}
int triangle(double a, double b, double c,double *S, double *P){
    if (a <= 0 || b <= 0 || c <= 0){
        printf("Invalid triangle sides!\n");
        return -1;
    }
    double ha, hb;
     ha = cos((pow(a, 2) + pow(b, 2) - pow(c, 2))/ 2*(a*b));
    hb = sin(ha)* b;
    *P = a + b + c;
    *S = (a * hb)/2;
    return 0;
}