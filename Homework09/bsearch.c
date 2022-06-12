#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define COUNT 10


typedef struct Books{
    char title[151];
    char author[101];
    int pages;
    double price;
}Books_t;

int randint(int, int);
char* myrandomName(char*);
double randReal (double, double);
int compareTitleASC(const void*,const void*);
int compareTitleDESC(const void*, const void*);
int compareAuthorASC(const void*, const void*);
int compareAuthorDESC(const void*, const void*);
int comparePriceASC(const void*, const void*);
int comparePriceDESC(const void*, const void*);
int comparePagesASC(const void*, const void*);
int comparePagesDESC(const void*, const void*);
void printBook(Books_t*);
int main(){
    srand(time(NULL));
    Books_t books[COUNT];

    for (int i = 0; i < COUNT; i++){
        myrandomName(books[i].title);
        myrandomName(books[i].author);
        books[i].pages = randint(5, 10);
        books[i].price = randint(20.00, 30.00);
    }   
    

    //Sort
    //qsort(books, COUNT, sizeof(*books), compareAuthorASC);
    //qsort(books, COUNT, sizeof(*books), compareAuthorDESC);
    //qsort(books, COUNT, sizeof(*books), compareTitleASC);
    //qsort(books, COUNT, sizeof(*books), compareTitleDESC);
    //qsort(books, COUNT, sizeof(*books), comparePriceASC);
    //qsort(books, COUNT, sizeof(*books), comparePriceDESC);
    //qsort(books, COUNT, sizeof(*books), comparePagesASC);
    //qsort(books, COUNT, sizeof(*books), comparePagesDESC);

    //Binary search
    Books_t key = {.title = "Do moeto purvo libe", .author = "Hristo Botev", .pages = 8, .price = 20.5};
    Books_t *element = bsearch(&key, books, COUNT, sizeof(*books),comparePagesASC);
    if (!element){
        printf("Not found!\n");
    }else{
        printf("Found!\n");
        printBook(element);
    }

    return 0;
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}
double randReal (double min, double max){
    return max + (rand() / RAND_MAX) * (max - min);
}

int compareTitleASC(const void* p1, const void* p2){
    Books_t* bp1 = (Books_t*)p1;
    Books_t* bp2 = (Books_t*)p2;
    return strcmp(bp1 -> title, bp2 -> title);
}
int compareTitleDESC(const void* p1, const void* p2){
    Books_t* bp1 = (Books_t*)p1;
    Books_t* bp2 = (Books_t*)p2;
    return strcmp(bp2 -> title, bp1 -> title);
}
int compareAuthorASC(const void* p1, const void* p2){
    Books_t* bp1 = (Books_t*)p1;
    Books_t* bp2 = (Books_t*)p2;
    return strcmp(bp1 -> author, bp2 -> author);
}
int compareAuthorDESC(const void* p1, const void* p2){
    Books_t* bp1 = (Books_t*)p1;
    Books_t* bp2 = (Books_t*)p2;
    return strcmp(bp2 -> author, bp1 -> author);
}
int comparePriceDESC(const void* p1, const void* p2){
     Books_t* bp1 = (Books_t*)p1;
    Books_t* bp2 = (Books_t*)p2;
    return (bp1 -> price - bp2 -> price) < 0.0001;
      if (bp1 -> price < bp2 -> price){
        return 0;
    }else{
        return -1;
    }
}
int comparePriceASC(const void* p1, const void* p2){
     Books_t* bp1 = (Books_t*)p1;
    Books_t* bp2 = (Books_t*)p2;
    return (bp1 -> price - bp2 -> price) < 0.0001;
    if (bp1 -> price > bp2 -> price){
        return 0;
    }else{
        return -1;
    }
}
int comparePagesASC(const void* p1, const void* p2){
    Books_t* bp1 = (Books_t*)p1;
    Books_t* bp2 = (Books_t*)p2;
    return bp1 -> pages - bp2 -> pages;
}
int comparePagesDESC(const void* p1, const void* p2){
    Books_t* bp1 = (Books_t*)p1;
    Books_t* bp2 = (Books_t*)p2;
    return bp2 -> pages - bp1 -> pages;
}
void printBook(Books_t * b){
        printf("Title: %s\t", b->title);
        printf("Author: %s\t", b ->author);
        printf("Pages: %d\t", b -> pages);
        printf("Price: %.2lf\t\n", b -> price);
}

char* myrandomName(char* arr){
    int index = 0;
    arr[index++] = randint('A', 'Z');
    int n = randint(10,20);
    for (int i = 0; i < n; i++){
        arr[index++] = randint('a', 'z');
    }
    arr[index++] = ' ';
    arr[index++] = randint('A', 'Z');
    int n1 = randint(10, 20);
    for(int i = 0; i < n1; i++){
        arr[index++] = randint('a', 'z');
    }
    arr[index++] = '\0';
    return arr;
}
