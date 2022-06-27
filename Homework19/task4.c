#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <semaphore.h>
#include <signal.h>


#define COUNT 11
#define PROD 10

//global variables
int prod[PROD];
int count = 0;
sem_t semFull;
sem_t semEmpty;
pthread_mutex_t mux;

//product characteristics
typedef struct products{
    char str[20];
    int barcode;
    double price;
}products_t;

//list node
typedef struct node{
    products_t products[PROD];
    struct node* next;
}node_t;


//functions
int randint(int, int);
double randReal(double, double);
char* randProd(char*);
int push(node_t**);
int pop(node_t**, int);
void* BUYERS(void*);
void* WORKER(void*);
void interrupt(int);
void freemalloc(node_t*);
void stop(int sig);


int main(){
    srand(time(NULL));
    pthread_t th[COUNT];
    node_t* arr = NULL;

    //push(&arr);
    pthread_mutex_init(&mux, NULL);
    sem_init(&semEmpty, 0, 10); //ostava maksimum mqsto 10 produkta
    sem_init(&semFull, 0, 0);   //ostava mqsto za oshte 0 produkta
    
       for (int i = 0; i < COUNT; i++){
        if(i & 1){
            if(pthread_create(th + i, NULL, BUYERS, &arr)){
                    perror("create buyer");
                    exit(EXIT_FAILURE);
                }
            
        }else {
            if(pthread_create(th + i, NULL, WORKER, &arr)){
                perror("create worker");
                exit(EXIT_FAILURE);
            }
        }
    }

    for (int i = 0; i < COUNT; i++){
        if(pthread_join(th[i], NULL)){
            perror("join");
            exit(EXIT_FAILURE);
        }
    }

    pthread_mutex_destroy(&mux);
    sem_destroy(&semFull);
    sem_destroy(&semEmpty);
    freemalloc(arr);

    return EXIT_SUCCESS;
}


int push(node_t** head){
    node_t* current = *head;
    current = malloc(sizeof(node_t)*10);
    for (int i = 0; i < PROD; i++){
        current->products->barcode = randint(13123123, 342432321);
        current->products->price = randReal(5.0, 20.0);
        randProd(current->products->str);
    }
     printf("Name: %s, Price: %.2lf, BARCODE: %d\n", current->products->str, current->products->price,current->products->barcode );
    current->next = *head;
    *head = current;
}

char* randProd(char* str){
    int index = 0;
    str[index++] = randint('A', 'Z');
    int n = randint(5, 15);
    for (int i = 0; i < n; i++){
        str[index++] = randint('a','z');
    }
    str[index++] = ' ';
    str[index++] = '\0';
    return str;
}
int randint(int min, int max){
    return min + rand() % (max - min + 1);
}
double randReal(double min ,double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
int pop(node_t** head, int position){
  node_t* current = *head;
  node_t* previous = *head;
  if (*head == NULL){
    perror("Empty");
    exit(EXIT_FAILURE);
  }
  while(position != 1){
    previous = current;
    current = current->next;
    position--;
  }
  previous->next = current->next;
  free(current);
  current = NULL;
}
void* WORKER(void* arg){
    //printf("I AM WORKER!\n");
    node_t* work = (node_t*)arg;
    
    while(1){
        sem_wait(&semEmpty);
        pthread_mutex_lock(&mux);
        sleep(2);
        printf("I put: \n");
        push(&work);
        prod[count++];
        pthread_mutex_unlock(&mux);
        sem_post(&semFull);
        if(signal(SIGINT, interrupt) != 0){
            FILE* fp;
            fp = fopen("Products.txt", "w");
            if(fp == NULL){
                    perror("File error");
                    exit(EXIT_FAILURE);
                }
            fwrite(&arg, sizeof(*arg), PROD, fp);
            fclose(fp);
        }
    }
}
void* BUYERS(void* arg){
    //printf("I AM BUYER!\n");
   node_t* buy = (node_t*)arg;
    while(1){
        int random = randint(1,10);
        sem_wait(&semFull); // -1
        pthread_mutex_lock(&mux);
        sleep(2);
        //pop(&buy, random);
        prod[--count];
        printf("I got product: %d\n", count);
        pthread_mutex_unlock(&mux);
        sem_post(&semEmpty); //+1
        if(signal(SIGINT, interrupt) != 0){
            FILE* fp;
            fp = fopen("Products.txt", "w");
            if(fp == NULL){
                    perror("File error");
                    exit(EXIT_FAILURE);
                }
            fwrite(&arg, sizeof(*arg), PROD, fp);
            fclose(fp);
        }
    }
    //sleep(100);
}
void interrupt(int sig){
    printf("I just made the file Products.txt!\n");
}

void freemalloc(node_t* arr){
    for (int i = 0; i < PROD; i++){
        free(arr);
    }
}