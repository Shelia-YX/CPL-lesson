#include <stdio.h>
int grp[105][3]={0};
void FdMx(int h,int t);
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)    scanf("%d",&grp[i][0]);
    FdMx(1,n);
    for (int i = 1; i <= n; i++){
        printf("%d %d\n",grp[i][1],grp[i][2]);
    }
    return 0;
}
void FdMx(int h,int t){
    int max=0,flag=0;
    //more than 1 number
    if(h < t){
        //find the max
        for(int i = h; i <= t; i++){
            if (grp[i][0]>max){
                flag = i;
                max = grp[i][0];
            }
        }
        //give s t
        grp[flag][1] = h;
        grp[flag][2] = t;
        if(flag > h) FdMx(h,flag-1);
        if(flag < t) FdMx(flag+1,t);
    }
    //only 1 num
    else {
        grp[h][1]=h;
        grp[h][2]=h;
    }
}