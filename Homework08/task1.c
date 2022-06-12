#include <stdio.h>
#include <string.h>
//STRLEN
/*size_t mystrlen(char*);

int main(){
    char ch[20] = "Hellomonkata";
    int n = 0;
    printf("%ld\n", mystrlen(ch));
    return 0;
}

size_t mystrlen(char*arr){
    size_t count = 0;
    while (arr[count]){
        count++;
    }
    return count;
}
*/

//STRCOPY
/*char* mystrcpy(char*, const char*);


int main(){
    char dest[1];
    const char source[20] = "Hello";
    printf("%s\n", mystrcpy(dest, source));
    return 0;
}

char* mystrcpy(char* dest, const char* source){
    int i = 0;
    if (dest == NULL){
        return NULL;
    }
    while (*(source + i) != '\0'){
        *(dest + i) = *(source + i);
        i++;
    }
    *(dest + i) = '\0';
    
    return dest;
}*/


//STRCAT

/*char* mystrcat(char*, char*);

int main(){
    char str1[20] = "Hello ";
    char str2[20] = "World!";
    printf("%s\n", mystrcat(str1, str2));
    return 0;
}

char*  mystrcat(char* dest, char* source){
    if (dest == NULL){
        return NULL;
    }
    int n = 0;
    int i, j;
    for (i = 0; *(dest + i) != '\0'; i++); // move to the end of dest string
    for (j = 0; *(source + j) != '\0'; j++){
        dest[i + j] = source [j];
    }
    dest[i + j] = '\0';

    return dest;

}*/

//STRCMP

/*int mystrcmp(const char*, const char*);

int main(){
    char str1[5] = "abc";
    char str2[5] = "cba";
    printf("%d\n", mystrcmp(str1, str2));
    return 0;
}

int mystrcmp(const char* str1, const char* str2){
    int i;
    while (*str1){
        if (*str1 != *str2){
            break;
        }
        str1++;
        str2++;
    }
    return str1 - str2;
    
}*/

char* mystrstr(const char*, const char*);
int compare(const char* str1, const char*str2);
int main(){
    char str1 [20] = "monkataluud";
    char str2 [20] = "luud";
    char * ret = mystrstr(str1, str2);
    printf("%s\n", ret);
    return 0;
}

char* mystrstr(const char* str1, const char* str2){
    while (*str1 != '\0'){
        if ((*str1 == *str2) && compare(str1, str2)){
            return str1;
        }
        str1++;
    }
    return NULL;
}
int compare(const char* str1, const char*str2){
    while (*str1 && str2){
        str1++;
        str2++;
        if (*str1 != *str2){
            return 0;
        }
    }
    return (*str2 == '\0');
}

