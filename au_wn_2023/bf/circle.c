#include <stdio.h>
#define PI 3.14159
int main(){
    int a,i=1;
    float sum=0;
    char m='m';
    scanf("%d",&a);
    while(i<=a){
        sum+=PI*i;
        i++;
    }
    printf("%f",sum);
    putchar (m);
    return 0;
}