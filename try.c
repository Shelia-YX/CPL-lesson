#include <stdio.h>
int main(){
    int num=3,*a=&num;
    scanf("%x",a);
    printf("%d",num);
    return 0;
}