#include <stdio.h>
#include <math.h>
char paint[2011][2011]={0};//change!!!!
//int dir[6][2]={{0,0},{0,1},{1,-1},{1,0},{1,1},{1,2}};
void print(int n,int x,int y);
int main(){
    int n;
    scanf("%d",&n);
    print(n,0,(int)pow(2,n)-1);
    for (int i = 0; i < pow(2,n); i++){
        for (int j = 0; j <pow(2,n+1); j++){
            if(paint[i][j] == 0)    printf(" ");
            else printf("%c",paint[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void print(int n,int r,int c){
    if(n == 1){
        paint[r][c] = '/';
        paint[r][c+1] = '\\';
        paint[r+1][c-1] = '/';
        paint[r+1][c] = '_';
        paint[r+1][c+1] = '_';
        paint[r+1][c+2] = '\\';
    }
    else{
        print(n-1,r,c);
        print(n-1,r+(int)pow(2,n-1),c-(int)pow(2,n-1));
        print(n-1,r+(int)pow(2,n-1),c+(int)pow(2,n-1));
    }
}