#include <stdio.h>
#include <stdbool.h>
int main(){
    int n,e,f=0,max=0;
    scanf("%d",&n);
    int a[100]={0};
    for(int i=0;i<2*n-1;i++){
        scanf("%d",&e);
        if(max<e) max=e;
        if(a[e]!=0) a[e]=0;
        else a[e]=e;
    }
    for(int i=0;i<=max;i++){
        if(a[i]!=0) f=a[i];
    }
    printf("%d",f);
    return 0;
}
