#include <stdio.h>
int main(){
    int n,x=0,y=1,op;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            y=y*j%10007;
        }
        y=y%10007;
        x+=y;
        y=1;
    }
    op=x%10007;
    printf("%d",op);
    return 0;
}