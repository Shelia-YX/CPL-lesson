#include <stdio.h>
int main(){
    int n,len=1,cgnum=2000,pls,temp;
    int hd,tl;
    int num[2005];
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&num[i]);
    }
    //get the maximum low len(equal is not exist)
    for (int i = n-1; i > 0; i--){
        if (num[i] < num[i-1])  len++;
        else break;
    }//get the nearest number :num[n-1-len]
    //get the under number
    for(int i = n-len; i < n; i++){
        if (num[i]>num[n-1-len]&&num[i]<cgnum){
            pls = i;
            cgnum = num[i];
        }
    }
    //change the number
    temp = num[pls];
    num[pls] = num[n-1-len];
    num[n-1-len] = temp;
    //overturn the maximum low
    hd=n-1-len;   tl=n;
    while (tl-hd>1){
        tl--;hd++;
        temp = num[hd];
        num[hd] = num[tl];
        num[tl] = temp;
    }
    //printf
    for(int i = 0; i < n; i++){
        if (i != n-1)   printf("%d ",num[i]);
        else printf("%d",num[i]);
    }
    return 0;
}