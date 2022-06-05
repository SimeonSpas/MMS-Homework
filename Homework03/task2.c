/*#include <stdio.h>
#include <math.h>
int floatCompare(float a, float b){
    return a == b;
}
int floatCompare2(float a, float b){
    return fabs(a - b) < 1.0e-5f;
}
int floatCompare3(float a, float b){
    return fabs(a - b) < 1.05e-5f* fmax(fabs(a), fabs(b));
}
int main(){
    float a = 1.1;
    float b = 0.1;
    float e;
    for (int i = 0; i <10; i++){
        b += 0.1;
    }if (floatCompare(a, b)){
        printf("true\n");
    }else {
        printf("false\n");
    }if (floatCompare2(a, b)){
        printf("true\n");
    }else {
        printf("false\n");
    } if (floatCompare3(a, b)){
        printf("true\n");
    }else {
        printf("false\n");
    }
    return 0;
}*/ // FLOAT VS DOUBLE
/*#include <stdio.h>
#include <math.h>
int floatCompare(double a, float b){
    return a == b;
}
int floatCompare2(double a, float b){
    return fabs(a - b) < 1.0e-5f;
}
int floatCompare3(double a, float b){
    return fabs(a - b) < 1.05e-5f* fmax(fabs(a), fabs(b));
}
int main(){
    double a = 1.1;
    float b = 0.1;
    float e;
    for (int i = 0; i <10; i++){
        b += 0.1;
    }if (floatCompare(a, b)){
        printf("true\n");
    }else {
        printf("false\n");
    }if (floatCompare2(a, b)){
        printf("true\n");
    }else {
        printf("false\n");
    } if (floatCompare3(a, b)){
        printf("true\n");
    }else {
        printf("false\n");
    }
    return 0;
}*/ // DIFFERENT METHODS (FALSE AGAIN)
#include <stdio.h>
#include <math.h>
int doubleCompare(double a, double b){
    return a == b;
}
int doubleCompare2(double a, double b){
    return fabs(a - b) < 0.5e-1f;
}
int doubleCompare3(double a, double b){
    return fabs(a - b) < 0.5e-1f* fmax(fabs(a), fabs(b));
}
int doubleCompare4(double a, double b){
    return (pow(a, 2) == pow(b, 2));
}
int doubleCompare5(double a, double b){
    return (sqrt(a) == sqrt(b));
}
int main(){
    double a = 1.1;
    double b = 0.1;
    for (int i = 0; i <10; i++){
        b += 0.1;
    }if (doubleCompare(a, b)){
        printf("true\n");
    }else {
        printf("false\n");
    }if (doubleCompare2(a, b)){
        printf("true\n");
    }else {
        printf("false\n");
    } if (doubleCompare3(a, b)){
        printf("true\n");
    }else {
        printf("false\n");
    }if (doubleCompare4(a, b)){
        printf("true\n");
    }else {
        printf("false\n");
    }if (doubleCompare5(a, b)){
        printf("true\n");
    }else {
        printf("false\n");
    }
    return 0;
}