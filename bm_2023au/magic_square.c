#include <stdio.h>
int squ[1000][1000]={0};
void PutInNum(int r,int c,int num,int n);
int main(){
    int n;
    scanf("%d",&n);
    squ[0][(n+1)/2-1]=1;
    PutInNum(0,(n+1)/2-1,1,n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == n-1) printf("%d\n",squ[i][j]);
            else printf("%d ",squ[i][j]);
        }
    }
    return 0;
}
void PutInNum(int r,int c,int num,int n){
    int x=r,y=c;
    num++;
    if (r-1 < 0)    r = n;
    if (c+1 >= n)    c = -1;
    if (squ[r-1][c+1] != 0){
        r = x+1;
        c = y;
        squ[x+1][y]=num;
    }     
    else {
        r-=1;
        c+=1;
        squ[r][c]=num;
    }
    if (num < n*n)    PutInNum(r,c,num,n);
}