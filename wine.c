#include <stdio.h>
int fm(int *pnt,int len);//find the dirct
int main(){
    int list[2][10005]={0};
    int *p = list[0];
    int n,l,add=0,max,tot=0;
    scanf("%d %d",&n,&l);
    for(int i = 0; i < n; i++){
        scanf("%d",&list[0][i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d",&list[1][i]);
    }
    while (add != l){
        max = fm(p,n);
        if(list[1][max] >= l - add){
            tot += list[0][max] * (l - add);
            add = l;
        }
        else{
            add += list[1][max];
            tot += list[0][max] * list[1][max];
            list[0][max] = 0;
        }
    }
    printf("%d",tot);
    return 0;
}
int fm(int *pnt,int len){
    int mx = 0,dir;
    for (int i = 0; i < len; i++){
        if(*(pnt + i) > mx){
            mx = *(pnt + i);
            dir = i;
        }
    }
    return dir;
}
