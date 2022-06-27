#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>


int randint(int, int);
char* randchar(char*);

int main(int argc, char** argv){
    char ch[100];
    int N = atoi(argv[1]);

    if (argc){
        for (int i = 0; i < N; i++){
            srand(time(NULL) + 1);
            pid_t pid = fork();
            if (0 == pid){
                sleep(1);
                randchar(ch);
                printf("%s\n", ch);
                wait(NULL);
                exit(0);
            }else {
                wait(NULL);
            }
        }
    }

    return EXIT_SUCCESS;
}

char* randchar(char* arr){
    int i;
    for (i = 0; i < 10; i++){
        arr[i] = randint('a', 'z');
    }
    arr[i] = '\0';

}
int randint(int min, int max){
    return min + rand() % (max - min + 1);
}