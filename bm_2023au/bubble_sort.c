#include <stdio.h>
int main(){
    int T,n,a[100],max=0;//strlen(a) need to be corrected
    scanf("%d",&T);
    for (int i = 0; i < T; i++){
        scanf("%d",&n);
        for (int i = 0; i < n; i++){
            scanf("%d",&a[i]);
            if(max<=a[i])   max=a[i];
        }
        //}
        //max=a[0];
        //for (int i = 0; i < n; i++){
        //    if(max<=a[i])   max=a[i];
        //}
        if(max<=a[n-1])   printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}