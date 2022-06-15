#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <math.h>
#define COUNT 10

typedef struct Car{
    char model[21];
    uint8_t maxspeed;
    double price;
}car;

int randint(int , int);
double randreal(double, double);
char* myrandname(char*);
int compareModelASC(const void*, const void*);
int compareModelDESC(const void*, const void*);
int compareMaxSpeedASC(const void*, const void*);
int compareMaxSpeedDESC(const void*, const void*);
int comparePriceASC(const void*, const void*);
int comparePriceDESC(const void*, const void*);
void printInfo(car*);


int main(){
    srand(time(NULL));
    car cars[COUNT];
    int opt;
    int (*option[])(const void*, const void*) = {
        compareModelASC,
        compareModelDESC,
        compareMaxSpeedASC,
        compareMaxSpeedDESC,
        comparePriceASC,
        comparePriceDESC
    };
    for (int i = 0; i < COUNT; i++){
        myrandname(cars[i].model);
        cars[i].maxspeed = randint(100, 300);
        cars[i].price = randreal(1000.00, 100000.00);
    }

    scanf("%d", &opt);
    if (opt < 1 && opt > 6){
        return 0;
    }
    qsort(cars, COUNT, sizeof(*cars), option[opt - 1]);
    for (int i = 0; i < COUNT; i++){
        printInfo(cars + i);
    }
    return 0;
}

int randint(int min, int max){
    return min + rand() % (max - min + 1); 
}
double randreal(double min, double max){
    return min + ((double)rand() / RAND_MAX) *(max - min);
}

char* myrandname(char* arr){
    int index = 0;
    arr[index++] = randint('A', 'Z');
    int n = randint(4, 10);
    for (int i = 0; i < n; i++){
        arr[index++] = randint('a', 'z');
    }
    arr[index++] = ' ';
    arr[index++] = randint('A', 'Z');
    int n1 = randint(4,10);
    for(int i = 0; i < n1; i++){
        arr[index++] = randint('a', 'z');
    }
    arr[index++]  = '\0';
    return arr;
}
int compareModelASC(const void* arr1,const void* arr2){
    car* p1 = (car*) arr1;
    car* p2 = (car*) arr2;
    return strcmp(p1 -> model, p2 -> model);
}
    
int compareModelDESC(const void* arr1,const void* arr2){
     car* p1 = (car*) arr1;
    car* p2 = (car*) arr2;
    return strcmp(p2 -> model, p1 -> model);
}

int compareMaxSpeedASC(const void* a, const void* b){
    car* c1 = (car*)a;
    car* c2 = (car*)b;
    return c1 -> maxspeed - c2 -> maxspeed;
}
int compareMaxSpeedDESC(const void* a, const void* b){
    car* c1 = (car*)a;
    car* c2 = (car*)b;
    return c2 -> maxspeed - c1 -> maxspeed;
}
int comparePriceASC(const void* a, const void* b){
    car* c1 = (car*)a;
    car* c2 = (car*)b;
    if(fabs(c1 -> price - c2 -> price) < 0.001){
        return 0;
    }else if (c1 -> price < c2 ->price){
        return -1;
    }
}
int comparePriceDESC(const void* a, const void* b){
    car* c1 = (car*)a;
    car* c2 = (car*)b;
     if(fabs(c1 -> price - c2 -> price) < 0.001){
        return 0;
    }else if (c1 -> price > c2 ->price){
        return -1;
    }
}
void printInfo(car* c){
    printf("%s\t", c -> model);
    printf("%d\t", c -> maxspeed);
    printf("%.2lf\n", c -> price);
}
