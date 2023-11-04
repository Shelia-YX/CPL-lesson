#include <stdio.h>
#include <math.h>
int main(){
    double p,q,x,squ,fst,snd;
    scanf("%lf %lf",&p,&q);
    squ=sqrt((q/2)*(q/2)+(p/3)*(p/3)*(p/3));
    //printf("%lf\n",squ);
    //printf("%lf\n",(-q)/2-squ);
    fst=cbrt((-q)/2+squ);
    snd=cbrt((-q)/2-squ);
    //printf("%lf\n",pow(-1,1.0/3));
    //printf("%lf,%lf\n",fst,snd);
    x=fst+snd;
    printf("%.3lf",x);
    return 0;
}