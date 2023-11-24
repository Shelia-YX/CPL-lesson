#include <stdio.h>
//2n+1:tail choose 1 and head choose 1 and 2n
//2n: tail choose 2 and head choose 2 and 2n-2
int way(int c);
int main(){
    int n,num;
    scanf("%d",&n);
    num = way(n);
    printf("%d",num);
    return 0;
}
int way(int c){
    if (c == 1)     return 1;
    else if (c == 2)     return 2;
    else return way(c - 2) + way(c - 1);
}