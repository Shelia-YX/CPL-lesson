#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b){
    if(*(int *)a > *(int *)b)   return 1;
    else if(*(int *)a == *(int *)b)     return 0;
    else    return -1;
}
int main(){
    int map[4][4]={0},fst[1][2]={0},snd[1][2]={0},srd[1][2]={0};
    int a[3],m1=0,m2=0,m3=0;
    for(int i = 1; i < 4; i++){
        for(int j = 1; j < 4; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] >= m1){
                m3 = m2;
                srd[0][0]=snd[0][0];
                srd[0][1]=snd[0][1];
                m2 = m1;
                snd[0][0]=fst[0][0];
                snd[0][1]=fst[0][1];
                m1 = map[i][j];
                fst[0][0]=i;
                fst[0][1]=j;
            }
            else if(map[i][j] >= m2){
                m3 = m2;
                srd[0][0]=snd[0][0];
                srd[0][1]=snd[0][1];
                m2 = map[i][j];
                snd[0][0]=i;
                snd[0][1]=j;
            }
            else if(map[i][j] >= m3){
                m3 = map[i][j];
                srd[0][0]=i;
                srd[0][1]=j;
            }
        }
    }
    
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    int max=0;
    if((srd[0][1]-snd[0][1])*(snd[0][0]-fst[0][0]) == (snd[0][1]-fst[0][1])*(srd[0][0]-snd[0][0])){
        for(int i = 1; i < 4; i++){
            for(int j = 1; j < 4; j++){
                if(((j == fst[0][1] && i == fst[0][0]) || (j == snd[0][1] && i == snd[0][0])) || (j == srd[0][1] && i == srd[0][0])){
                    continue;
                }
                else    if(map[i][j] > max)     max = map[i][j];
            }
        }
    }
    qsort(a,3,sizeof(int),cmp);
    if(max == 0) printf("%d",m1*a[2]+m2*a[1]+m3*a[0]);
    else printf("%d",m1*a[2]+m2*a[1]+max*a[0]);
    return 0;
}