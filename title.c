#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char *str;
    int len;
    str = malloc(sizeof(char) * 4097);
    fgets(str,4096,stdin);
    len = strlen(str);
    if(*str >= 'a')    printf("%c",*str-'a'+'A');
    else    printf("%c",*str);
    for(int i = 1; i < len-1; i++){
        if(*(str + i) == ' ')    printf("%c",*(str + i));
        else if(*(str + i - 1) == ' '){
            if(*(str + i) >= 'a')   printf("%c",*(str + i)-'a'+'A');
            else    printf("%c",*(str + i));
        }
        else{
            if(*(str + i) >= 'a')   printf("%c",*(str + i));
            else    printf("%c",*(str + i)-'A'+'a');
        }
    }
    free(str);
    return 0;
}