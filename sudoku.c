#include <stdio.h>
#include <ctype.h>
const int cst=1^2^3^4^5^6^7^8^9;
int blk[15][15];
int checksquare(int m,int n){
    int s=cst;
    s^=blk[m-1][n-1]^blk[m-1][n]^blk[m-1][n+1]^blk[m][n-1]^blk[m][n]^blk[m][n+1]^blk[m+1][n-1]^blk[m+1][n]^blk[m+1][n+1];
    return s;
}
int main(){
    int yn=1,tfn,l=cst,c=cst,sc;
    //fill in the blank
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            scanf("%d",&blk[i][j]);
            tfn=isdigit(blk[i][j]+'0');
            if (tfn == 0) yn=0;
        }
    }
    //1. if every line is legal?
    //2. if every column is leagal?
    if (yn != 0){
        for (int i = 0; i < 9; i++){
            l=cst;
            c=cst;
            for (int j = 0; j < 9; j++){
                l^=blk[i][j];
                c^=blk[j][i];
            }
            if (l!=0||c!=0){
                yn=0;
                break;
            }
        }    
    }
    //3. if every square is leagal? -point need to be check:
    //[1][1] [1][4] [1][7] [4][1] [4][4] [4][7] [7][1] [7][4] [7][7] 
    if(yn != 0){
        for (int i = 1; i < 8; i += 3){
            for (int j = 1; j < 8; j += 3){
                sc=checksquare(i,j);
                if (sc != 0){
                    yn=0;
                    break;
                }
            }
            if (yn == 0)    break;
        }
    }
    //4. print y or n accroding to yn
    switch (yn){
    case 0:    printf("NO"); break;
    case 1:    printf("YES"); break;
    }
    return 0;
}