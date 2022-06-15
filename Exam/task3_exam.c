#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char arr[501];
    scanf("%s", arr);
    for (int i =0; i < arr[i];i++){
        if ((i % 2) == 1){
            switch(arr[i]){
                case '0':
                    arr[i] = '!';
                    break;
                case '1':
                    arr[i] = '#';
                    break;
                case '2':
                    arr[i] = '/';
                    break;
                case '3':
                    arr[i] = '~';
                    break;
                case '4':
                    arr[i] = '=';
                    break;
                case '5':
                    arr[i] = '`';
                    break;
                case '6':
                    arr[i] = '\\';
                    break;
                case '7':
                    arr[i] = '>';
                    break;
                case'8':
                    arr[i] = '.';
                    break;
                case '9':
                    arr[i] = ',';
                    break;
            }
        }else {
            arr[i] = 'A' + (arr[i] - '0');
        }
    }
    printf("%s\n", arr);
    return 0;
}
//10296126782646987676234