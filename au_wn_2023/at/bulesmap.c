#include <stdio.h>
#include <math.h>
int main(){
    int num,*a=&num,map[16][16]={0},ord=0;
    printf("--------------------------------------------------------\n");
    printf("-THIS IS A PROGRAM WHICH COULD PRINT CHINESE CHARACTERS-\n");
    printf("--------------------------------------------------------\n");
    printf("----------------PRINT '-1' TO EXIT----------------------\n");
    printf("---------PRINT '1' TO PRINT ANOTHER CHARACTERS----------\n");
    printf("--------------------------------------------------------\n");
    printf("----------------------FOR LWWC -------------------------\n");
    printf("--------------DESIGN BY LWWC--CODE BY GYX---------------\n");
    printf("--------------------------------------------------------\n");
    printf("YOUR ORDER:");
    scanf("%d",&ord);
    while(ord == 1){
        for(int i = 0; i < 16; i++){
            num = -1;
            printf("LINE %d:",i+1);
            scanf("%x",a);
            if(num == -1){
                printf("WRONG GB CODE\n");
                getchar();
                i--;
                continue;
            }   
            for(int j = 0; j < 16; j++){
                map[i][15-j] = *a % 2;
                *a /= 2;
            }
        }
        printf("\n");
        printf("YOUR CHARACTER:\n");
        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 16; j++){
            if(map[i][j] == 1)  printf("▇▇");
                else printf("  ");
            }
            printf("\n");
        }
        printf("\n");
        printf("YOUR ORDER:");
        scanf("%d",&ord);
    }
    printf("WE APPRECIATE YOUR PATRONAGE.");
    return 0;
}