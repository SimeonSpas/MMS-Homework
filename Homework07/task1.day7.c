#include <stdio.h>

int secondMax(const int* arr, size_t n, int* secondMax){
   int max = 0;
    *secondMax = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > max){
            *secondMax = max;
            max = arr[i];
        }else if (arr[i] > *secondMax){
            *secondMax = arr[i];
        }
    }
    return *secondMax;
}

int main(){
    int arr[] = {12, 130, 5, 70, 90};
    int sm = 0;
    printf("%d\n",secondMax(arr, 5, &sm));
    return 0;
}

