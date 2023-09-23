#include <stdio.h>
#include <math.h>
int main(){
    double pia,pib,a;
    a=640320.0*640320.0*640320.0+744.0;
    //double a,b;
    //b=640320.0*640320.0;
    //a=b*640320+744;
    pia=log(a)/sqrt(163);
    printf("%.15lf\n",pia);
    pib=4*(4*atan(0.2)-atan(1/239.0));
    printf("%.15lf\n",pib);
    return 0;
}