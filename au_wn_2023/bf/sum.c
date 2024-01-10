#include <stdio.h>
int main(){
    //get n and t
    int n,t,muti,sum=0;
    scanf("%d %d",&n,&t);
    sum = t;
    muti = t;
    //sum the number for n times
    for (int i = 1; i < n; i++){
        muti = 10*muti + t;
        sum = sum + muti;
    }
    printf("%d",sum);
    return 0;
}
