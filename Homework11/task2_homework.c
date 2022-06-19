#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double randReal(double, double);

int main(){
    srand(time(NULL));
    int n, n1, n2;
    double *arr = malloc(sizeof(double) * n);
    if(NULL == arr){
        fprintf(stderr, "Malloc error!\n");
        return EXIT_FAILURE;
    }
    printf("Enter length of the array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        arr[i] = randReal(0.00, 1.00);
    }
    printf("Enter second length of the array: ");
    scanf("%d", &n1);
    arr = realloc(arr, sizeof(double)*(n + n1));
    if(NULL == arr){
        fprintf(stderr, "Realloc error!\n");
        return EXIT_FAILURE;
    }
    for (int i = n; i < n+n1; i++){
        arr[i] = randReal(1.0, 2.0);
    }
    printf("Enter third length of the array: ");
    scanf("%d", &n2);
    arr = realloc(arr, sizeof(double) * (n + n1 + n2));
    if(NULL == arr){
        fprintf(stderr, "Realloc error!\n");
        return EXIT_FAILURE;
    }
    for (int i = n+n1; i < n+n1+n2; i++){
        arr[i] = randReal(2.0, 3.0);
    }
    for (int i = 0; i < n+n1+n2; i++){
        printf("%.2lf\n", arr[i]);
    }
    putchar('\n');
    free(arr);
    return 0;
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}