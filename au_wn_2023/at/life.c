#include <stdio.h>
#include <string.h>
void life(int dim,char *s);
int main(){
    int ver;
    char str[103]={0};
    scanf("%d%s",&ver,str);
    life(ver,str);
    printf("%s",str);
    return 0;
}
void life(int dim,char *s){
    int len=strlen(s);
    for(int i = 0; i < dim; i++){
        for(int j = 1; j < len-1; j++){
            if(s[j] == 'A'){
                if(s[j-1] == 'I' && s[j+1] == 'I')  s[j] = '#';
                else{
                    if(s[j-1] != 'I')   s[j-1] = 'A';
                    if(s[j+1] != 'I' && s[j+1] != 'A')   s[j+1] = 'a';
                }
            }
            if(s[j] == 'a') s[j] = 'A';
        }
        if(s[0] == 'A' && s[1] != 'I')  s[1] = 'A';
        if(s[len-1] == 'A' && s[len-2] != 'I') s[len-2] = 'A';
        if(s[len-1] == 'a') s[len-1] = 'A';
    }
}