#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int T,d[3]={0},cnt;
    char *str1,*str2,*str0,*st;
    const char spl={';'};
    str1 = malloc(1005 * sizeof(char));
    str2 = malloc(1005 * sizeof(char));
    str0 = malloc(3000 * sizeof(char));
    st = malloc(2005 * sizeof(char));
    scanf("%d",&T);
    getchar();
    for(int i = 0; i < T; i++){
        cnt = 1;
        scanf("%s",str0);
        str1 = strtok(str0,spl);
        str2 = strtok(NULL,spl);
        d[0] = atoi(strtok(NULL,spl));
        d[1] = atoi(strtok(NULL,spl));
        d[2] = atoi(strtok(NULL,spl));
        while(cnt < d[2]){
            for(int j = 0; j < d[0]; j++){
                if(*str1 != '\0' && cnt < d[2]){
                    *(st + cnt - 1) = *str1;
                    str1++;
                    cnt++;
                }
                else break;
            }
            for(int j = 0; j < d[1]; j++){
                if(*str2 != '\0' && cnt < d[2]){
                    *(st + cnt - 1) = *str2;
                    str2++;
                    cnt++;
                }
                else break;
            }
            if(*str1 == '\0' && *str2 == '\0')  break;
        }
        *(st + cnt - 1) = '\0';
        printf("%s\n",st);
    }
    return 0;
}