#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdint.h>
#define COUNT 10

int main(int argc, char**argv){
    srand(time(NULL));
    FILE *fp;
    fp = fopen("numbers.data", "wb");
    uint16_t arr[COUNT];
    for (int i = 0; i < COUNT; i++){
        arr[i] = rand()%10;
        printf("%d ", arr[i]);
    }
    fwrite(&arr, sizeof(*arr), COUNT, fp);
    fclose(fp);

    fp = fopen("numbers.data", "rb");
    fread(&arr, sizeof(*arr), COUNT, fp);
    fclose(fp);
    return 0;
}