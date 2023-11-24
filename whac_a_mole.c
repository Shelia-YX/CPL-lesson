#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int map[705][705]={0};
int d=0;
int allpoint(int *rs,int x,int y,int od);
int main(){
    int r0,c0,max=-249950001,temp,cnt=0;
    //res store the last result
    int res=0,*rs=&res;
    int maxs[2][360000];
    scanf("%d %d %d",&r0,&c0,&d);
    int r=d,c=d,cnc=1;
    for(int i = d; i < r0+d; i++){
        for (int j = d; j < c0+d; j++){
            scanf("%d",&map[i][j]);
        }
    }
    //cnt is the end place of the xy
    for(int i = 1; i <= r0*c0; i++){
        //1.move and calculate the point
        if(i == 1)//first
            temp = allpoint(rs,r,c,0);
        else if(i % c0 == 1 && i != 1){//next line
            r++;
            cnc++;
            temp = allpoint(rs,r,c,-1);
        }
        else if(cnc % 2 == 1){//2n+1 line
            c++;
            temp = allpoint(rs,r,c,0);
        }
        else{
            c--;
            temp = allpoint(rs,r,c,1);
        }
        //2.judge the max
        if(max < temp){
            max = temp;
            cnt = 0;
            maxs[0][0] = r;
            maxs[1][0] = c;
        }
        else if(max == temp){
            cnt++;
            maxs[0][cnt] = r;
            maxs[1][cnt] = c;
        }
    }
    printf("%d %d\n",max,cnt+1);
    for(int i = 0; i <= cnt; i++){
        printf("%d %d\n",maxs[0][i] - d + 1,maxs[1][i] - d + 1);
    }
    return 0;
}

//0:right 1:left -1:down
int allpoint(int *rs,int r,int c,int od){
    if(r == d && c == d){
        for(int i = -d; i <= d; i++){
            for(int j = abs(i)-d; j <= d - abs(i);j++){
                *rs += map[r + i][c + j];
            }
        }
        return *rs;
    }
    else if(od == 0){
        for(int i = -d; i <= d; i++){
            *rs = *rs - map[r+i][c+abs(i)-d-1] + map[r+i][c+d-abs(i)];
        }
        return *rs;
    }
    else if(od == 1){
        for(int i = -d; i <= d; i++){
            *rs = *rs + map[r+i][c+abs(i)-d] - map[r+i][c+d-abs(i)+1];
        }
        return *rs;
    }
    else{
        for(int i = -d; i <= d; i++){
            *rs = *rs - map[r+abs(i)-d-1][c+i] + map[r+d-abs(i)][c+i];
        }
        return *rs;
    }
}
