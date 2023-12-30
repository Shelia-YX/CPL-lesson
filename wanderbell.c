#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char map[305][305]={0};//3005
int ifsafe(int nl,int nc,int l,int c,char dir);//now point,l,c,the map
int search(int nl,int nc,int l,int c,char dir);
int main(){
    //1.initialize the map
    int l,c,cnt=0,tfs,sch;
    scanf("%d %d",&l,&c);
    for(int i = 0; i < l; i++){
        scanf("%s",map[i]);
    }
    //2.search for the danger arrow
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(isalpha(map[i][j])){
                tfs = ifsafe(i,j,l,c,map[i][j]);
                if(tfs == 0){//3.search for the other arrow
                    sch = search(i,j,l,c,map[i][j]);
                    if(sch == 0){
                        printf("-1");
                        return 0;
                    }
                    else cnt++;
                }
            }
            
        }
    }
    printf("%d",cnt);
    return 0;
}
int ifsafe(int nl,int nc,int l,int c,char dir){
    int flag=0;
    switch (dir){
    case 'L'://left
        for(int i = nc - 1; i >= 0; i--){
            if(map[nl][i] != '.'){
                flag = 1;
                break;
            }
        }
        break;
    case 'R'://right
        for(int i = nc + 1; i < c; i++){
            if(map[nl][i] != '.'){
                flag = 1;
                break;
            }
        }
        break;
    case 'U'://up
        for(int i = nl-1; i >= 0; i--){
            if(map[i][nc] != '.'){
                flag = 1;
                break;
            }
        }
        break;
    case 'D'://down
        for(int i = nl + 1; i < l; i++){
            if(map[i][nc] != '.'){
                flag = 1;
                break;
            }
        }
        break;
    default:
        break;
    }
    return flag;
}
int search(int nl,int nc,int l,int c,char dir){
    if(dir != 'U'){
        for(int i = nl - 1; i >= 0; i--){
            if(map[i][nc] != '.')    return 1;
        }
    }
    if(dir != 'D'){
        for(int i = nl + 1; i < l; i++){
            if(map[i][nc] != '.')    return 1;
        }
    }
    if(dir != 'L'){
        for(int i = nc - 1; i >= 0; i--){
            if(map[nl][i] != '.')    return 1;
        }
    }
    if(dir != 'R'){
        for(int i = nc + 1; i < c; i++){
            if(map[nl][i] != '.')    return 1;
        }
    }
    return 0;
}