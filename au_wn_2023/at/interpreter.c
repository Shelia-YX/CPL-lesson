#include <stdio.h>
int main(){
    unsigned int p=0,*pp=&p;
    scanf("%x",pp);
    printf("%d\n%u\n%0.6f\n%0.3e\n",*(int*)pp,p,*(float*)&p,*(float*)&p);
    return 0;
}
