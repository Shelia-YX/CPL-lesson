#include <stdio.h>
#include<string.h>
char sr[8]={'{','}','[',']','(',')',' ','\0'};
int main(){
    int p=0,n,len,tf;
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i++){
        char str[105]={0},grp[105]={0};//change!!
        tf = 1;
        p = 0;
        fgets(str,105,stdin);//change!!
        len = strlen(str);
        for(int j = 0; j < len-1; j++){
            if(str[j] == ' '){
                if(p != 0)  tf=0;
            }
            else if((str[j] == '{' || str[j] == '[') || str[j] == '('){
                grp[p] = str[j];
                p++;
            }
            else if((str[j] == '}' || str[j] == ']') || str[j] == ')'){
                if(grp[p-1] == str[j]-2 || grp[p-1] == str[j]-1)    p--;
                else{
                    tf = 0;
                    break;
                }
            }
            else{
                tf = 0;
                break;
            }
        }
        if(p != 0)  tf=0;
        if(tf == 0)     printf("False\n");
        else    printf("True\n");
    }
    return 0;
}