#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char stct[130]={0},name[1030],ord[1030],res[600][1030],*p,*temp[600];
    int cnt=0;
    scanf("%s",stct);
    scanf("%s",name);
    printf("%s",name);
    while(scanf("%s",ord) != EOF){
        if(*ord == '-'){
            p = strstr(stct,ord+1);
            if(p){
                if(*(p + 1) == ':'){
                    res[cnt][0] = *p;
                    res[cnt][1] = '=';
                    if(scanf("%s",res[cnt]+2) != EOF){
                        *(temp + cnt) = res[cnt];
                        cnt++;
                    }    
                    else{
                        printf(": option requires an argument -- '%c'\n",*p);
                        return 0;
                    }
                }
                else{
                    res[cnt][0] = *p;
                    res[cnt][1] = '\0';
                    *(temp + cnt) = res[cnt];
                    cnt++;
                }
            }
            else{
                printf(": invalid option -- '%c'\n",*p);
                return 0;
            }
        }
    }
    printf("\n");
    for(int i = 0; i < cnt; i++){
        printf("%s\n",*(temp + i));
    }
    return 0;
}