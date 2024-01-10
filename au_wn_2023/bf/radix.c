#include <stdio.h>
//1. put the 3 number in 3 groups
//2. try less than 60 time to find if we could such a 'b'
// 2.0. judge: P[0]*i+P[1] * Q[0]*i+Q[1] == R[0]*i+R[1]
int main(){
    int p,q,r;
    int P[2]={0},Q[2]={0},R[2]={0};
    scanf("%d %d %d",&p,&q,&r);
    P[0]=p/10;  P[1]=p%10;
    Q[0]=q/10;  Q[1]=q%10;
    R[0]=r/10;  R[1]=r%10;
    for (int i = 2; i <= 40; i++){
        if(((P[0]<i && P[1]<i) && (Q[0]<i && Q[1]<i)) && (R[0]<i && R[1]<i)){
            if ((P[0]*i+P[1]) * (Q[0]*i+Q[1]) == R[0]*i+R[1]){
                printf("%d",i);
                return 0;
            }
        }
    }
    printf("0");
    return 0;
}