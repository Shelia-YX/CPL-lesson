#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int AbsPrime(int num);
int Overturn(int num);
int main(){
    int n,count=1;
    scanf("%d",&n);
    if (n < 2){
        printf("0");
        return 0;
    }
    //for every number<n,judge if it and another is prime
    for (int i = 3; i <= n; i++)    count += AbsPrime(i);
    printf("%d",count);
    return 0;
}
//1. make up-side-down of the number
int AbsPrime(int num){
    bool flag;
    int cnum; // 1 表示该数是素数
    for (int i = 1; i <= sqrt(num + 0.5); i+=2) {
        if (i == 1){
            flag = (num % 2 != 0);
            if (flag == 0)  break;
        }
        else{
            flag = (num % i != 0);
            if (flag == 0)  break;
        }    
    }
    if (flag != 0){
        cnum = Overturn(num);
        for (int i = 1; i <= sqrt(cnum + 0.5); i+=2) {
            if (i == 1){
                flag = (cnum % 2 != 0);
                if (flag == 0)  break;
            }      
            else{
                flag = (cnum % i != 0);
                if (flag == 0)  break;
            }    
        }
    }
    return flag;
}
int Overturn(int num){
    int n0 = num,cnt=0;
    int svnb[1005]={0};
    //overturn
    while (n0 > 0){
        svnb[cnt] = n0 % 10;
        n0 /= 10;
        cnt++;
    }
    //mutiply
    for (int i = 0; i < cnt; i++){
        n0 += svnb[i]*pow(10,cnt-1-i);
    }
    return n0;
}