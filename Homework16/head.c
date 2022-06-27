#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char** argv){
    int c;
    if (!strcmp(argv[2], "RE"));
    FILE *fp = fopen(argv[1], "r");
    if(NULL == fp){
        fprintf(stderr, "Invalid arg!\n");
        return EXIT_FAILURE;
    }
    fseek(fp, ((sizeof(argv[2]) / 2) +1 ), SEEK_CUR);
    while ((c = fgetc(fp)) != EOF){
        putchar(c);
    }
    putchar('\n');
    fclose(fp);
    return EXIT_SUCCESS;
}