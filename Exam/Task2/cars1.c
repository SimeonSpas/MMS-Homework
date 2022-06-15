#include "cars.h"
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
