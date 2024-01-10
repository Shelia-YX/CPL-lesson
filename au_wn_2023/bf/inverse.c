#include <stdio.h>
int main(){
    int n,k;
    char a[100]={0},b[100]={0};
    scanf("%d",&n);
    getchar();
    fgets(a,n+1,stdin);
    scanf("%d",&k);
    for(int i=0;i<k;i++)    b[i]=a[k-1-i];
    for(int i=k;i<n;i++)    b[i]=a[n-1-i+k];
    puts(b);
    return 0;
}