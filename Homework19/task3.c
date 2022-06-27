#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

char str[20];
int count = 0;
pthread_mutex_t mux;

void* routine(void* arg){
    *str = *(char*)arg;
    sleep(2);
    pthread_mutex_lock(&mux);
    count++;
    printf("I am %d thread %s\n", count , str);
    pthread_mutex_unlock(&mux);
}

int main(int argc, char** argv){
    pthread_t th;
    char* MSG;
    pthread_mutex_init(&mux, NULL);
    int P = atoi(argv[1]);
    int T = atoi(argv[2]);
    for (int i = 0; i < P; i++){
        pid_t pid = fork();
        if (-1 == pid){
            perror("fork");
        }
        if(0 == pid){
            //child
            printf("I am procces: %d\n", i);
            for (int i = 0; i < T; i++){
                MSG = malloc(sizeof(char));
                MSG = strcpy(str,argv[3]);
                if(pthread_create(&th, NULL, routine, MSG)){
                    perror("create");
                    exit(EXIT_FAILURE);
                }
            }

            for (int i = 0; i < *(*argv + 2); i++){
                if(pthread_join(th, NULL)){
                    perror("join");
                    exit(EXIT_FAILURE);
                }
            }

        }else {
            //parent
            wait(NULL);
        }
    }
    pthread_mutex_destroy(&mux);
    return EXIT_SUCCESS;
}