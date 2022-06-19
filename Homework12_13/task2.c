#include <stdio.h>

void Reverse(char*);
int Count(int*);

int main(){
    char sym[] = "This is a test";
    int count = 0;
    Reverse(sym);
    return 0;
}
void Reverse(char* ptr){
    int i = 0, count = 0;
    while (*(ptr + i)){
        count++;        //check the number of elements in str
        i++;
    }
    for (i = count; i >= 0; i--){ //prints them reversed 
       printf("%c", ptr[i]);
    }
    putchar('\n');
}


/*Realize function that reverses null terminated string. The prototype of the function is "void
Reverse(char* ptr);”. Do not use standard library functions.
Example: If e.g. “This is a test\0” is passed to the function, the function must produce “tset a si sihT\0”*/