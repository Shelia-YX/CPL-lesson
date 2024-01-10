#include <stdio.h>
int main(){
    int m,n,p;
    int A[105][105]={0},B[105][105]={0},C[105][105]={0};
    //read m,n,p
    scanf("%d %d %d",&m,&n,&p);
    //READ DIGITGROUP A
    for( int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d",&A[i][j]);
        }
    }
    //READ DIGITGROUP B
    for( int i = 0; i < n; i++){
        for (int j = 0; j < p; j++){
            scanf("%d",&B[i][j]);
        }
    }
    //MUTIPLY AND PRINT C
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            for (int k = 0; k < n; k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
            if (j==0)   printf("%d",C[i][j]) ;  
            else    printf(" %d",C[i][j]);
        }
        if (i<m-1)  printf("\n");
    }
    return 0;
}