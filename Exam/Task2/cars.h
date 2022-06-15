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

#ifndef __MY_CARS__
#define __MY_CARS__
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
#endif
