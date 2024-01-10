#include <stdio.h>
int main(){
    char let;
    int cse=0;
    //a=0;
    do{
        printf("Type your letter here.\n");
        //let=getchar();
        //let=getchar();
        //printf("let=%c\n",let);
        //scanf("%d",&a);
        //printf("a=%d",a);
        scanf("%c",&let);
        //printf("let=%c\n",let);
        if (let>='A'&&let<='Z')
        {
            let=let+32;
            printf("Do you wanna ");
            putchar(let);
            printf("?\n");
        }
        else{
            printf("Do you wanna %c ?\n",let-32);
        }
        printf("Do you want to close this terminal?1(yes)/0(no)\n");
        scanf("%d",&cse);
        //printf("cse=%d\n",cse);
        getchar();
    }while(cse!=1);
    return 0;
}