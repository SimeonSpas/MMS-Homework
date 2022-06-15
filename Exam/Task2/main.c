#include "cars.h"
#define COUNT 10
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
