#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char** argv){
        FILE* fp;
        int fd[2];
        if(pipe(fd) == -1){
                perror("pipe");
                exit(EXIT_FAILURE);
        }
        int arr[20], total, j = 0, temp = 0, temp1,sum = 0, total_sum = 0;
        for (int i = 1; i < argc; i++){
                pid_t pid = fork();
                if(-1 == pid){
                        perror("fail");
                        exit(EXIT_FAILURE);
                }
                if(0 == pid){
                         
                        //child
                        fp = fopen(argv[i], "r");
                        while(fscanf(fp, "%d", &arr[j]) == 1){
                                temp = arr[j] / 10;
                                temp1 = arr[j] % 10;
                                total = temp1 + temp;
                                j++;
                                sum += total;
                                write(fd[1], &sum, sizeof(sum));
                                close(fd[1]);
                        }
                        printf("%d ", sum);
                        putchar('\n');
                        exit(0);
                        
                }else{
                        
                       /*read(fd[0], &sum, sizeof(sum));
                       close(fd[0]);
                        wait(NULL);
                        while(sum){
                            total_sum += sum;
                        }
                        printf("%d ", total_sum);*/
                        wait(NULL);
                }

        }
        return EXIT_SUCCESS;
}