#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[105][105];
char str0[10005],sp,*str1;
int main(){
    scanf("%s",str0);
    getchar();
    scanf("%c",&sp);
    int i=0;
    str1 = strtok(str0,&sp);
    while(str1 != NULL){
        strcpy(*(str+i),str1);
        i++;
        str1 = strtok(NULL,&sp);
    }
    qsort(str,i,sizeof(str[0]),strcmp);
    for(int j = 0; j < i; j++){
        printf("%s\n",str[j]);
    }
    return 0;
}