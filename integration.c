#include <stdio.h>
#include <math.h>
int A[25]={0};
int n,p;
//figure out the f(x)
double wf(double x);
//figure out the sab
double S(double a,double b,double epc0);
int main(){
    double res;
    double a,b;
    scanf("%d %d",&n,&p);
    for(int i = 0; i <= n; i++)  scanf("%d",&A[i]);
    scanf("%lf %lf",&a,&b);
    res=S(a,b,0.0001);
    printf("%lf",res);
    return 0;
}
double wf(double x){
    double ins = 0;
    for (int i = 0; i <= n; i++){
        ins += A[i] * pow(x,i);
    }
    return pow(ins,p*1.0);
}
double S(double a,double b,double epc){
    double res,rel,rer,mid,ab; 
    mid = (a + b) / 2;
    double fa = wf(a),fmid = wf(mid),fb = wf(b),fma = wf((mid + a) / 2),
        fmb =wf((mid + b) / 2);
    res = (4 * fmid + fa + fb) * (b - a) / 6;
    rel = (4 * fma + fa + fmid) * (mid - a) / 6;
    rer = (4 * fmb + fmid + fb) * (b - mid) / 6;
    ab = rel + rer - res;
    if (ab <= 15*epc && ab >= -15*epc){
        return rel + rer + ab/15;    
    }
    else return S(a,mid,epc/2) + S(mid,b,epc/2);
}