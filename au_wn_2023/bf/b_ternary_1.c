#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int main(){
    int n,len[100],tfn,tfa,finn[100]={0},skip=0;
    char num[20][100]={0};
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        fgets(num[i],20,stdin);
        len[i]=strlen(num[i]);
    }
    for(int i=0;i<n;i++){
        skip=0;
        for(int j=0;j<len[i]-1;j++){
            tfn=isdigit(num[i][j]);
            tfa=isalpha(num[i][j]);
            if((num[i][j]!='Z'&&tfn==0)||(abs(num[i][j])>'1'&&tfa==0)){
                printf("Radix Error\n");
                skip=1;
                break;
            } 
            else{
                switch (num[i][j]){
                case 'Z':finn[i]+=(-1)*pow(3,len[i]-2-j);break;
                case '0':finn[i]+=0;break;
                case '1':finn[i]+=1*pow(3,len[i]-2-j);break;
                default:break;
                }
            }
        }
        if(skip==1) continue;
        else printf("%d\n",finn[i]);
    }
    return 0;
}