#include <stdio.h>
int main(){
    int n,k,j=0,cnt=1;//j for counting the death time
    int suv[505]={0};
    scanf("%d %d",&n,&k);
    while(j<(n-1)){
        for(int i=1;i<=n;i++){
            if(suv[i]==0&&cnt!=k)   cnt++;
            else if(suv[i]==0&&cnt==k){
                cnt=1;
                suv[i]=1;
                j++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(suv[i]==0){
            printf("%d",i);
            break;
        }
    }
    return 0;
}