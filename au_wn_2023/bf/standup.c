#include <stdio.h>
int main(){
    int n,p=0,t=0;
    int a[105];
    scanf("%d",&n);
    for (int i=0;i<=n;i++)  scanf("%d",&a[i]);
    p=a[0];
    for (int i=1;i<=n;i++){
        while(p<i){
            p++;
            t++;
        }
        p+=a[i];
    }
    printf("%d",t);
    return 0;
}