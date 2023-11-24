#include <stdio.h>
int a0,b0,c0,va,vb,vc;
void pour(int k,int a,int b,int c,int *p);
int main(){
    int k,a,b,c;
    int tf;
    int *p = &tf;
    scanf("%d %d %d %d %d %d %d %d %d %d",&k,&va,&vb,&vc,&a,&b,&c,&a0,&b0,&c0);
    pour(k,a,b,c,p);
    if(tf == 0)     printf("No");
    else    printf("Yes");
    return 0;
}
void pour(int k,int a,int b,int c,int *p){
    if(*p == 1) return;
    if(k == 0){
        if((a == a0 && b == b0) && c == c0)    *p = 1;
        else *p = 0;
    }
    else{
        int lst[6]={va-b-a,va-c-a,vb-a-b,vb-b-c,vc-a-c,vc-b-c};
        for(int i = 0; i < 6; i++){
            if(lst[i] <= 0) lst[i] = 0; 
        }
        pour(k-1,-lst[0]+va,0,c,p);
        pour(k-1,-lst[1]+va,b,0,p);
        pour(k-1,0,-lst[2]+vb,c,p);
        pour(k-1,a,-lst[3]+vb,0,p);
        pour(k-1,0,b,-lst[4]+vc,p);
        pour(k-1,a,0,-lst[5]+vc,p);
    }
}