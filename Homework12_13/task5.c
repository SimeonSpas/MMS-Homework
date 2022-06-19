#include <stdio.h>
#include <stdlib.h>

void Bubble(int*, unsigned int);
void print(int* arr, int value);

int main(){
    int arr[5] = {5,2,30,1,6};
    Bubble(arr, 5);
    print(arr, 5);
    return 0;
}

void Bubble(int* pArray, unsigned int uValue){
    int k = 0;
    int arr[] = {};
    for(int i = 0; i < uValue; i++){
        for (int j = 0; j < uValue; j++){
            if (pArray[j] > pArray[j+1]){
                k = pArray[j];            
                printf("%d %d ", pArray[i], pArray[j]); 
                pArray[j] = pArray[j + 1];
                pArray[j + 1] = k;
                
            }   
        }
    }
}

void print(int* arr, int value){
    for (int i =0; i < value; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
}
