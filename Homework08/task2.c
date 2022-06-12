#include <stdio.h>

int map(int* array, size_t n, int (*func)(int)){
    for (int i = 0; i < n; i++){
        array[i] = func(array[i]);
        printf("%d\n", array[i]);
    }
    
}

int doubleNums(int i){
  return 2*i;
}

int main(){
    int nums[4] = {1, 2, 3, 4};
    map(nums, 4, &doubleNums);
    return 0;
}