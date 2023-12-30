#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int judge(int num,int gol,int time,int all);
int main(){
    int w,n,d,numb[1005]={0},mid,altim=0;
    scanf("%d %d %d",&w,&n,&d);
    for(int i = 1; i <= w; i++){
        scanf("%d",&numb[i]);
    }
    mid = ceil(w/2);
    for(int i = 1; i <= mid; i++){
        int tmp=judge(numb[i],numb[w+1-i],d,n);
        if(tmp == -1){
            printf("impossible\n");
            return 0;
        }
        else    altim += tmp;
    }
    printf("%d",altim);
    return 0;
}
int judge(int num,int gol,int plus,int all){//return the minimum time and if possible
    num--;
    gol--;
    int temp1=num,temp2=gol,flag=0,i=0,j=0;
    if(num == gol)  return 0;
    do{
        num = (num+plus) % all;
        i++;
        if(num == gol){
            flag = 1;
            break;
        }
    }while(num != temp1);
    do{
        gol = (gol + plus) % all;
        j++;
        if(gol == temp1){
            flag = 1;
            break;
        }
    }while(gol != temp2);
    if(flag == 1)   return (i>j?j:i);
    else return -1;
}