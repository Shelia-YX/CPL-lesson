#include <stdio.h>
int C(int a,int b);
int main(){
    int a,b,res;
    scanf("%d %d",&a,&b);
    if(a == 1)   printf("1");
    else{
        res = C(a-1,b-1);
        printf("%d",res);
    }
    return 0;
}
int C(int a,int b){
    if(b == 0) return 1;
    else if(a == b) return 1;
    else return C(a-1,b-1)+C(a-1,b);
}