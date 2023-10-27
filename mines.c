#include <stdio.h>
char map[105][105]={0};
int around[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
//1.count the bomb number around one point
int count(int l,int c){
    int bn=0,p,q;
    for (int i = 0; i < 8; i++){
        p=l+around[i][0];
        q=c+around[i][1];
        if (map[p][q] == '*')   bn++;
    }
    return bn;
}
int main(){
    int n;
    //2.get the map
    scanf("%d",&n);
    getchar();
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n+1; j++){
            scanf("%c",&map[i][j]);
        }
    }
    //3.if point isn't bomb,then it equals around numbers,and print out
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (map[i][j] != '*'){
                map[i][j] = count(i,j);
                printf("%d",map[i][j]);
            }
            else    printf("*");
        }
        printf("\n");
    }
    return 0;
}