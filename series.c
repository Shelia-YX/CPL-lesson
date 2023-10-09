#include <stdio.h>
#include <math.h>
int main(){
    double x,y=0;
    int n;
    scanf("%lf %d",&x,&n);
    for(int i=0;i<=n;i++){
        y+=4.0*pow(-1.0,i*1.0)*pow(x,2.0*i+1.0)/(2.0*i+1.0);
    }
    printf("%.10lf",y);
    return 0;
}