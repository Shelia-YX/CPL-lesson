#include <stdio.h>
int main(){
    int n,i=0,max=0;
    scanf("%d",&n);
    while(n!=1){
        if(max<n) max=n;
        if(n%2==0) n/=2;
        else n=3*n+1;
        i++;
    }
    printf("%d %d",i,max);
    return 0;
}