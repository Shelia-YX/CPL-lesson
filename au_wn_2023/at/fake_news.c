#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char str[2000]={0};
    scanf("%s",str);
    int len=strlen(str);
    if(str[0]<'a')  printf("%c",str[0]);
    else    printf("%c",str[0]-'a'+'A');
    for(int i = 1; i < len; i++){
        if(isupper(str[i]))    printf(" %c",str[i]-'A'+'a');
        else    printf("%c",str[i]);
    }
    return 0;
}