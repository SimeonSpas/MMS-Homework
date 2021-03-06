#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char** argv){
    pid_t pid = fork();
    if (-1 == pid){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (0 == pid){
        //child
        
        execlp(argv[1],argv[1], NULL);
    }else {
        //parent
        int wstatus;
        wait(&wstatus);
        if (WIFEXITED(wstatus)){
            int statuscode = WEXITSTATUS(wstatus);
            if (statuscode == 0){
                exit(EXIT_FAILURE);
            }else {
                
                execlp(argv[2],argv[2], NULL);
                exit(EXIT_SUCCESS);
            }
        }
        wait(NULL);
    }
    return EXIT_FAILURE;
}