#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char** argv){
    int n;
    char buff[BUFSIZ];

    if (argv[1] == NULL){
        while (n = read(STDIN_FILENO, buff, BUFSIZ)){
            write(STDOUT_FILENO, buff, n);
        }

    }if (argc > 0){
        int fd;
        for (int i = 1; i < argc; i++){
            fd = open(argv[i], O_RDONLY);
            if (-1 == fd){
                perror("Couldnt open file!\n");
                exit(1);
            }
            
            while (read(fd, buff, BUFSIZ)){
                write(STDOUT_FILENO, buff, strlen(buff));
                putchar('\n');
            }
            
        }
        close(fd);
    }
    
    return EXIT_FAILURE;
}