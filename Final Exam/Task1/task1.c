#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define ITEMS_COUNT 10

typedef struct item{
    uint16_t number;
    char description[250];
    double weigth;
    double price;
}item;

typedef struct node{
    item data[ITEMS_COUNT];
    struct node* next;
}node_t;

int push(node_t**, item);
int createitems(node_t**);
int randint(int, int);
char* randName(char*);
double randReal(double, double);
void printList(node_t*);
uint16_t randint1(int min, int max);
double totalItemsWeight(node_t*);
node_t* minPriceItem(node_t*);
int freemalloc(node_t*);

int main(){
    item* arr;
    node_t* ptr = NULL;
    ptr = malloc(sizeof(node_t));
    createitems(&ptr);
    printList(ptr);
    minPriceItem(ptr);
    printf("Total weight: %.2lf \n", totalItemsWeight(ptr));
    return EXIT_SUCCESS;
}


int createitems(node_t** ptr){
    
    for (int i = 0; i < ITEMS_COUNT; i++){
        item generator;
        randName(generator.description);
        generator.number = randint1(1, 10);
        generator.weigth = randReal(0.100, 100.0);
        generator.price = randReal(1.00, 1500.00);
        push(ptr, generator);
        }
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

uint16_t randint1(int min, int max){
    return min + (uint16_t)rand() % (max - min + 1);
}

char* randName(char* arr){
    int index = 0;
    arr[index++] = randint('A', 'Z');
    int n = randint(1,5);
    for (int i = 0; i < n; i++){
        arr[index++] = randint('a', 'z');
    }
    arr[index++] = ' ';
    int n1 = randint(1, 5);
    for (int i = 0; i < n1; i++){
        arr[index++] = randint('a', 'z');
    }
    arr[index++] = '\0';
    return arr;

}

double totalItemsWeight(node_t* items){
    item* res;
    double result = 0;
    if (items->data == NULL){
        perror("RESULT FAILED");
        exit(EXIT_FAILURE);
    }
    while(items){
        result += items->data->weigth;
        items = items->next;
    }
    return result;
}

void printList(node_t* ptr){
    node_t* current = ptr;
    while(current){
        printf("Number: %d ", current->data->number);
        printf("Description: %s ", current->data->description);
        printf("Price: %.2lf ", current->data->price);
        printf("Weigth: %.2lf \n", current->data->weigth);
        current = current->next;
    }
    putchar('\n');
}
int push(node_t** head, item val){
    node_t* new_node;
    new_node = malloc(sizeof(node_t));
    *new_node -> data = val;
    new_node->next = *head;
    *head = new_node;
}

node_t* minPriceItem(node_t* items){
    node_t* current;
    double arr[ITEMS_COUNT];
    for (int i = 0; i < ITEMS_COUNT; i++){
        arr[i] = items->data->weigth;
        items = items->next;
    }
    for (int i = 0; i < ITEMS_COUNT; i++){
        for(int j = 0; j < ITEMS_COUNT - i -1; j++){
            if (arr[j] > arr[j+1]){
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("The minimum price item is: %.2lf ", (double)arr[0]);
    
    return 0;
}
