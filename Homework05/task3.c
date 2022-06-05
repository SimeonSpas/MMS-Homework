#include <stdio.h>
int rectangle(double w, double h, double *S, double *P);

int main(){
    double a, b, area, perimeter;
    printf("Enter rectangle sides: \n");
    while(scanf("%lf %lf", &a, &b)){
        if (rectangle(a, b, &area, &perimeter)){
        printf("S = %.2lf\n P = %.2lf\n", area, perimeter);
        }
    }
    return 0;
}
int rectangle(double w, double h, double *S, double *P){
    if (w <= 0 || h <= 0){
        printf("Invalid rectangle sizes: \n");
        return -1;
    }
    *S = w * h;
    *P = 2* (w + h);
}