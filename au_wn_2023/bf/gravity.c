#include <stdio.h>
# define G 6.674e-11
int main(){
    double m,r,gra;
    scanf("%lf %lf",&m,&r);
    gra=G*77.15*m/(r*r);
    printf("%.3e",gra);
    return 0;
}