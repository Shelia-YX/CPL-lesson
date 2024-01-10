#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(char *s1,char *s2);
void mystrcat(char *s1,char *s2,int lc);
int main(){
    char *str1,*str2;
    str1 = malloc(2000 * sizeof(char));
    str2 = malloc(1000 * sizeof(char));
    int n,loc;
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i++){
        scanf("%s",str1);
        scanf("%s",str2);
        loc = cmp(str1,str2);
        mystrcat(str1,str2,loc);
        printf("%s\n",str1);
    }
    free(str1);
    free(str2);
    return 0;
}

int cmp(char *s1,char *s2){
    int len1=strlen(s1),len2=strlen(s2),judge=(len1>len2)?len2:len1;
    for(int i = len1 - judge; i < len1; i++){
        if(*(s1+i) == *s2){
            if(i == len1 - 1)    return i;
            for(int j = 1; j < len1 - i; j++){
                if(*(s1 + i + j) != *(s2 + j))    break;
                if(j == len1 - i - 1)   return i;
            }
        }
    }
    return len1;
}

void mystrcat(char *s1,char *s2,int lc){
    int len=strlen(s2);
    for(int i = 0; i < len; i++){
        *(s1 + lc + i) = *(s2 + i);
    }
    *(s1 + lc + len) = '\0';
}

