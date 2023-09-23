#include <stdio.h>
int main(){
    int a50=1,b20=2,c10=3,d5=4,e1=5,pay;
    scanf("%d",&pay);
    a50=pay/50;
    printf("%d\n",a50);
    b20=(pay-50*a50)/20;
    printf("%d\n",b20);
    c10=(pay-50*a50-20*b20)/10;
    printf("%d\n",c10);
    d5=(pay-50*a50-20*b20-10*c10)/5;
    printf("%d\n",d5);
    e1=(pay-50*a50-20*b20-10*c10-5*d5);
    printf("%d\n",e1);
    return 0;
}