#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main(){
    int n,ptin,j=0,len1,len,tfn,sign;
    int a=0;
    char typein[20];
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        sign=0;
        char finn[25]={0},dgtcp[25]={0};
        fgets(typein,20,stdin);
        len1=strlen(typein)-1;
        for(int j=0;j<len1;j++){
            tfn=isdigit(typein[j]);
            if(tfn==0&&typein[j]!='-'){
                printf("Radix Error\n");
                goto T1;
            }
            else if(typein[j]=='-') sign=1;
        }
        ptin=atoi(typein);
        ptin=abs(ptin);
        if(ptin==0) printf("%d",ptin);
        j=0;
        while(ptin/3>=1){
            a=ptin%3;
            finn[j]=a;
            dgtcp[j]=1;
            ptin/=3;
            j++;
        }
        finn[j]=ptin;
        for(int i=0;i<25;i++){
            if (sign==0){
                switch (finn[i]){
                    case 1:dgtcp[i]=1;break;
                    case 2:finn[i]='Z';finn[i+1]+=1;dgtcp[i]=1;dgtcp[i+1]=1;break;
                    case 3:finn[i]=0;finn[i+1]+=1;dgtcp[i]=1;dgtcp[i+1]=1;break;
                    default:break;
                }
            }
            else {
                switch (finn[i]){
                    case 1:finn[i]='Z';dgtcp[i]=1;break;
                    case 2:finn[i]=1;finn[i+1]+=1;dgtcp[i]=1;dgtcp[i+1]=1;break;
                    case 3:finn[i]=0;finn[i+1]+=1;dgtcp[i]=1;dgtcp[i+1]=1;break;
                    default:break;
                }
            }
        }
        len=strlen(dgtcp)-1;
        for(int i=0;i<=len;i++){
            if(finn[len-i]==90)   printf("%c",finn[len-i]);
            else printf("%d",finn[len-i]);
        }
        printf("\n");
        T1:;
    }
    return 0;
}