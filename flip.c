#include <stdio.h>
int main(){
    int a[2005]={0},n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int b=n/i;
        for(int j=1;j<=b;j++){
            if(a[i*j]==1) a[i*j]=0;
            else a[i*j]=1;
        }
    }
    printf("1");
    for(int i=2;i<=n;i++){
        if(a[i]==1) printf(" %d",i);
    }
    return 0;
}