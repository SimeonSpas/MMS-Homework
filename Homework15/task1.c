#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define COUNT 10

typedef struct{
    char title [151];
    char author [101];
    int pages;
    double price;
}Book;

int randint(int, int);
int randReal(double, double);
char* randName(char*);
void print(Book*);

int main(){
    srand(time(NULL));
    Book books[COUNT];
    for (int i = 0; i < COUNT; i++){
        randName(books[i].title);
        randName(books[i].author);
        books[i].pages = randint(5, 2000);
        books[i].price = randReal(1.00, 1000.00);
    }
    FILE *fp;
    fp = fopen("books1.txt", "wb");
    fwrite(&books, sizeof(*books), COUNT, fp);
    fclose(fp);

    for (int i = 0; i < COUNT; i++){
        print(books + i);
    }
    return 0;
}

int randint(int min, int max){
    return min + rand()%(max - min + 1);
}

int randReal(double min, double max){
    return min + ((double)rand()/RAND_MAX) * (max - min);
}
char* randName(char* str){
    int index = 0;
    str[index++] = randint('A', 'Z');
    int n = randint(10, 20);
    for (int i = 0; i < n; i++){
        str[index++] = randint('a', 'z');
    }
    str[index++] = ' ';
    str[index++] = randint('A', 'Z');
    int n1 = randint(10, 20);
    for (int i = 0; i < n1; i++){
        str[index++] = randint('a', 'z');
    }
    str[index++] = '\0';
    return str;
}
void print(Book* b){
        printf("Title: %s ", b -> title);
        printf("Author: %s ", b -> author);
        printf("Pages: %d ", b -> pages);
        printf("Price: %.2lf\n", b -> price);
}