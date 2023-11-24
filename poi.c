#include <stdio.h>
int line[105]={0};//change!!
int judge(int p,int b);
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)    scanf("%d",&line[i]);
    for (int i = 1; i <= n; i++){
        line[i] = judge(i,line[i]);
        printf("%d ",line[i]);
    }
    return 0;
}
int judge(int p,int b){
    if(p == b)      return b;
    else    return judge(b,line[b]);
}