#include <stdio.h>
#include <math.h>
char dir[5]={'U','D','L','R','\0'};
int main(){
    //if c is in between a and b, then goto c then goto b
    //else, go straight down and right(or the opposite)
    int xa,ya,xb,yb,xc,yc,dx,dy,n;
    scanf("%d %d %d %d %d %d",&xa,&ya,&xb,&yb,&xc,&yc);
    dx=abs(xa-xc);  
    dy=abs(ya-yc);
    n=dx+dy-2;
    printf("%d\n",n);
    
}