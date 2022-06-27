#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

int randint(int, int);
char* message(char*);
void *routine(void*);

int main(int argc, char** argv){
    srand(time(NULL));
    int a = atoi(argv[1]);
    pthread_t th[a];
    
    for (int i = 0; i < a; i++){
        if(pthread_create(th + i, NULL, routine, NULL)){
            perror("threads:");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < a; i++){
        if(pthread_join(th[i], NULL)){
            perror("join");
            exit(EXIT_FAILURE);
        }
    }
    return EXIT_SUCCESS;
}

void *routine(void* arg){
    char str[100];
    message(str);
    char* buff = malloc(sizeof(char)*100);
    strcpy(buff, str);
    printf("%s\n", buff);
    free(buff);
}


char* message(char* arr){
    for (int i = 0; i < 10; i++){
        arr[i] = randint('a', 'z');
    }
    return arr;
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}