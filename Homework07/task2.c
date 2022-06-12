#include <stdio.h>

unsigned sumArrayDigits(const int* arr, size_t n);

int main(){
    int arr[4] = {12, 34, 5, 70};
    printf("%d\n", sumArrayDigits(arr, 4));
    return 0;
}

unsigned sumArrayDigits(const int* arr, size_t n){
    int remainder, quotient, sum = 0;
    for (int i = 0; i < n; i++){
        quotient = arr[i] / 10;
        remainder = arr[i] % 10;
        sum += quotient + remainder;
    }
    return sum;
}
