#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n=100005,cnt,len,*res,cr=0;
    char *s,*t;
    s = malloc(sizeof(char)*n);
    scanf("%s",s);
    cnt = strlen(s);
    t = malloc(sizeof(char) * cnt);
    res = malloc(sizeof(int) * cnt);
    scanf("%s",t);
    len = strlen(t);
    for(int i = 0; i <= cnt-len; i++){
        if(*(s + i) == *t){
            if(len == 1){
                *(res + cr) = i;
                cr++;
            }
            else{
                for(int j = 1; j < len; j++){
                    if(*(s + i + j) != *(t + j))    break;
                    if(j == len-1){
                        *(res + cr) = i;
                        cr++;
                    }
                }
            }
            
        }
    }
    free(s);
    free(t);
    for(int i = 0; i < cr; i++)    printf("%d ",*(res + i));
    free(res);
    return 0;
}
/*
if(cnt < n){
            scanf("%c",(s + cnt));
            cnt++;
        }
        else{
            char *temp;
            temp = malloc(sizeof(char) * n);
            for(int i = 0; i < n; i++)    *(temp + i) = *(s + i);
            free(s);
            n += 10;
            char *s;
            s = malloc(sizeof(char) * n);
            for(int i = 0; i < n-10; i++)    *(s + i) = *(temp + i);
            free(temp);
            scanf("%c",(s + n - 10));
            cnt++;
        }*/
