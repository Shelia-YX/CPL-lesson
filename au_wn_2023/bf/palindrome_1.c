#include <stdio.h>
int main(){
    char st[2005];
    int n;
    scanf("%d",&n);
    getchar();
    fgets(st,n+1,stdin);
    for(int i=0;i<n;i++){
        if(st[i]=='?')   st[i]=st[n-1-i];
    }
    puts(st);
    return 0;
}