#include <stdio.h>
#include <stdint.h>
int main()
{
    int opt;
    uint32_t attendance = 0, mask = 0;
    while(1){
        printf("\n1.Set attendance \n");
        printf("2.Clear attendance \n");
        printf("3.Attendance info \n");
        printf("4.Change attendance \n");
        scanf("%d", &opt);
        if (opt < 0 ){
            printf("Invalid option.\n");
            break;
        }
        else if (opt >= 8){
            break; 
        }else if (opt == 1){
            printf("Choose the student who attended: ");
            scanf("%d", &attendance);
             if (attendance > 32){
                 printf("Invalid number.\n");
                 break;
            }
            mask |= (1 << attendance);   //set bit HIGH
            printf("The attendance of %d is set to %d.\n", attendance, mask);
        }else if (opt == 2){
            printf("Choose the student who hasnt attended: ");
            scanf("%d", &attendance);
            if (attendance > 32){
                printf("Invalid number.\n");
                break;
            }
            mask &= ~(1 << attendance); //set bit LOW
            printf("The absence of %d is set to %d\n", attendance, mask);
        }else if (opt == 3){
            for (attendance = 32; attendance > 0; attendance--){
                printf("%d", !!(mask&(1<<attendance)));
            }
        }else if (opt == 4){
                scanf("%u", &attendance);
                mask ^= (1 << attendance);
                printf("The student, has been flipped to %u", !!(mask&(1<<attendance)));
            }
        }
    return 0;
}

    
