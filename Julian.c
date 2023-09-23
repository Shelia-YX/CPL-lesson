#include <stdio.h>
#include <math.h>
int main(){
    int a,month,year,y,m,jdn,day;
    scanf("%d %d %d",&year,&month,&day);
    a=floor((14-month)/12);
    y=year+4800-a;
    m=month+12*a-3;
    jdn=day+floor((153*m+2)/5)+365*y+floor(y/4)-floor(y/100)+floor(y/400)-32045;
    printf("%d",jdn);    
    return 0;
}