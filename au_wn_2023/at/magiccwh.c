#include<stdio.h>
#include<math.h>
char bu[5000][5000]={0};
void paint(int n,int x,int y){
    if(n==1){
        bu[y][x]='/';
        bu[y][x+1]='\\';
        bu[y+1][x-1]='/';
        bu[y+1][x]='_';
        bu[y+1][x+1]='_';
        bu[y+1][x+2]='\\';
    }  
    else{ 
        paint(n-1,x,y);
        paint(n-1,x-pow(2,n-1),y+pow(2,n-1));
        paint(n-1,x+pow(2,n-1),y+pow(2,n-1));
        }
}
int main()
{
    int n;
    scanf("%d",&n);
    paint(n,pow(2,n)-1,0);
    for (int i = 0; i < pow(2,n); i++){
        for (int j = 0; j< pow(2,n+1); j++){
            if(bu[i][j]==0) printf(" ");
            else printf("%c",bu[i][j]);
        }
        printf("\n");
    }
}