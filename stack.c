#include <stdio.h>
int main(){
    char string[10];
    int n,p=0,lab;
    char str[104]={0};//change!!
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s",string);
        if(string[1] == 'u')    lab = 1;
        else if(string[0] == 'p' && string[1] == 'o')    lab = 2;
        else if(string[0] == 't' && string[1] == 'o')    lab = 3;
        else if(string[1] == 'r')  lab = 4;
        else break;
        switch (lab){
            case 1:
                getchar();
                scanf("%c",&str[p]);
                p++;
                break;
            case 2:
                if(p == 0)     printf("Empty\n");
                else    p--;
                break;
            case 3:
                if(p == 0)     printf("Empty\n");
                else    printf("%c\n",str[p-1]);
                break;
            case 4:
                if(p == 0)     printf("Empty\n");
                else{
                    for(int j = p-1; j >= 0; j--){
                        printf("| %c |\n",str[j]);
                    }
                    printf("|===|\n");
                }
                break;
            default:
                break;
        }
        getchar();
    }
    return 0;
}