#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void* routine(void* arg){
    int temp;
    int arr[20];
    while(1){

        for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8 - i -1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;
            }
            //printf("%d\n", arr[j]);
        }
    }

    for(int i = 0; i < 8; i++){
        printf("%d\n", arr[i]);
        FILE* fp1;
        fp1 = fopen("nums1.txt", "wb");
        fwrite(&arr, sizeof(arr),sizeof(arr)/sizeof(*arr), fp);
        fclose(fp);
    }
    }
}

//2-ra zadacha bez nishki
int main(int argc, char** argv){
    FILE *fp;
    int c;
    for (int i = 0; i < (argc -1); i++){}
        fp = fopen("nums.txt", "r");
    int arr[20];
    int i =0;
    int temp;
    while(i < 8 && fscanf(fp, "%d", &arr[i]) == 1){
        printf("a[%d] = %d\n", i, arr[i]);
        i++;
    }
    return 0;
}