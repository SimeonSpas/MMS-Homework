#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char** argv){
    int fd[2];
     if(pipe(fd) == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }
    

    pid_t pid =fork();
    int sum = 0;
    if (-1 == pid){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (0 == pid){
        close(fd[0]);
        int result = 0;
            int remainder, quotient;
        for (int i = 1; i < ((argc / 2)+ 1); i++){
             int first = atoi(argv[i]);
            remainder = first % 10;
            quotient = first / 10;
            sum = remainder + quotient;
            printf("Sum = %d\n",sum);
            
        }
        write(fd[1], &sum,sizeof(sum));
        close(fd[1]);
    }else {
        //parent
        close(fd[1]);
        wait(NULL);
        int sum1 = 0, remainder, quotient;
        for (int i = ((argc / 2) + 1); i < argc; i++){
            int second = atoi(argv[i]);
            remainder = second % 10;
            quotient = second / 10;
            sum1 = remainder + quotient;
            printf("Sum1 = %d\n",sum1);
        }
        read(fd[0], &sum, sizeof(sum));
        
        
        wait(NULL);
        close(fd[0]);
        for (int i = 0; i < argc + 1; i++){
            int total = sum + sum1;
            printf("%d\n", total);
        }
        //int total = sum + sum1;
        //printf("%d\n", total);
    }
    return EXIT_SUCCESS;
}


