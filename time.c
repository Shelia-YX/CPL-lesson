#include <stdio.h>
int main(){
    char week[100],month[100];
    int day,year,hour,minu,sec;
    //scanf("%s %d %d %s %d %d %d",month,&day,&year,week,&hour,&minu,&sec);
    scanf("%s",month);
    scanf("%d",&day);
    scanf("%d",&year);
    scanf("%s",week);
    scanf("%d",&hour);
    scanf("%d",&minu);
    scanf("%d",&sec);
    printf("%.3s ",week);
    printf("%.3s ",month);
    printf("%02d ",day);
    printf("%02d:",hour);
    printf("%02d:",minu);
    printf("%02d ",sec);
    printf("%04d",year);
    //printf("%.3s %.3s %02d %02d:%02d:%02d %04d\n",week,month,day,hour,minu,sec,year);
    return 0;
}