#include <stdio.h>
double func1(double a, char *choice, double b, double *a1){
    if (a <= 0 || b <= 0){
        fprintf(stderr, "Invalid input\n");
        return -1;
    }if (*choice == '*'){
        *a1 = a * b;
    }else if (*choice == '/'){
        *a1 = a / b;
    }else if (*choice == '+'){
        *a1 = a + b;
    }else if (*choice == '-'){
        *a1 = a - b;
    }
  
}

int main(){
    char choice;
    char ch;
    double a, b, result;
    printf("First enter number\nThen enter: \n1.*\n2./\n3.+\n4.-\nAnd enter second number\n");
    while(scanf("%lf %c %lf", &a,&choice, &b) != EOF){ 
    printf("The result is: %.2lf\n", func1(a, &choice, b, &result));
    }
    return 0;
}