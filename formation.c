#include <stdio.h>
int main(){
    int fm[205][205]={0};
    char a[205];
    int m,n;
    scanf("%d %d",&m,&n);
    //read the number and make sure column 0 and n+1 is 0
    getchar();
    fgets(a,205,stdin);
    for (int i = 1; i <= n; i++){
        if(a[i-1] == '1')   fm[0][i]=1;
    }
    //give line n number accroding to the last line and print
    for (int i = 1; i < m; i++){
        for (int j = 1; j <= n; j++){
            if (fm[i-1][j-1] + fm[i-1][j] + fm[i-1][j+1]==2 || fm[i-1][j] + fm[i-1][j+1]==1){
                fm[i][j]=1;
            }
            printf("%d",fm[i][j]);
        }
        if (i < m-1) printf("\n");
    }
    return 0;
}