#include <stdio.h>
char matrix[55][55]={0};
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//0.find '#''s direction
int find(int l,int c){
    int x1,y1,fini;
    for (int i = 0; i < 4; i++){
        x1 = l + dir[i][0];
        y1 = c + dir[i][1];
        if (matrix[x1][y1]=='#'){
            fini=i;
            break;
        }
    }
    return fini;
}
int main(){
    int n,m,x0,y0,ans=0,drct;
    scanf("%d %d %d %d",&n,&m,&x0,&y0);
    getchar();
    //1.get the matrix,and count '#'
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m+1; j++){
            scanf("%c",&matrix[i][j]);
            if (matrix[i][j] == '#')    ans++;
        }
    }
    printf("%d\n",ans);
    //tip:around matrix is 0
    //2.goto x0,y0 and find the next place 
    //tip:fini is the direction of '#'  //tip:print the place now,then change it,then move
    for (int i = 0; i < ans; i++){
        printf("%d %d\n",x0,y0);
        drct = find(x0,y0);
        matrix[x0][y0] = '0';
        x0+=dir[drct][0];
        y0+=dir[drct][1];
    }
    return 0;
}