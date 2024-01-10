#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int comp(const void *a,const void *b);
int main(){
    int n,a[103]={0};
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),comp);
    for(int i = 0; i < n; i++)  printf("%d ",a[i]);
    return 0;
}
int comp(const void *a,const void *b){
    if(*(int *)a > *(int *)b)   return 1;
    else if(*(int *)a == *(int *)b) return 0;
    else return -1;
}