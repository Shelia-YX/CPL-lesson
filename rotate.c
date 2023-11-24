#include <stdio.h>
#include <string.h>
int main(){
    int a,b,c,len;
    char str[1005];
    scanf("%d %d %d",&a,&b,&c);
    int x1=0,x2=a,y1=0,y2=b;
    scanf("%s",str);
    len = strlen(str);
    for(int i = 0; i < len; i++){
        //w:forth s:back a:left d:right
        switch (str[i]){
        case 'W':
            x2 = x1;
            x1 -= c;
            c = a; 
            a = x2 - x1;
            break;
        case 'S':
            x1 = x2;
            x2 += c;
            c = a; 
            a = x2 - x1;
            break;
        case 'A':
            y2 = y1;
            y1 -= c;
            b = c;
            c = y2 - y1;
            break;
        case 'D':
            y1 = y2;
            y2 += c;
            b = c;
            c = y2 - y1;
            break;
        default:
            break;
        }
    }
    printf("%d %d %d %d",x1,x2,y1,y2);
    return 0;
}