#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void *a,const void *b);
int main(){
    char *a[3],b[2][10],c[10];
    scanf("%s",b[0]);
    a[0] = b[0];
    scanf("%s",b[1]);
    a[1] = b[1];
    qsort(a,2,sizeof(char*),comp);
    return 0;
}
int comp(const void *a,const void *b){
    return strcmp((char*)a,(char*)b);
}