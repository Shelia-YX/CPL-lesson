#include <stdio.h>
int ans[20]={0};
void fd(int n,int min,int nfd);
int main(){
    int n;
    scanf("%d",&n);
    //for(int i = 0; i < n; i++)    printf("1 ");
    fd(n,1,0);
    return 0;
}
void fd(int n,int min,int nfd){
    if (n == 0){
        for(int i = 0; i < nfd; i++)     printf("%d ",ans[i]);
        printf("\n");
    }
    else if (n >= min){
        for (int i = min; i <= n; i++){
            ans[nfd] = i;
            fd(n - i, i, nfd + 1);
        }
    }
}