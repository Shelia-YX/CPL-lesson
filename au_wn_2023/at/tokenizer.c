#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *rsvd[17]={"const","int","float","double","long","static","void","char","extern","return","break","enum","struct","typedef","union","goto"};
const char *oprt[12]={"+","-","*","/","=","==","!=",">=","<=",">","<"};
char *res[4100]={0};
int flag=1;
void judge(char *s,int count);
int main(){
    char str[4100]={0},*pst,*lstr;
    int cnt=0,len1;//cnt is the next place
    while(scanf("%s",str) != EOF){
        int len=strlen(str);
        pst = strchr(str,';');
        lstr = strtok(str, ";");
        if(pst == NULL){//order have no ';'
            judge(str,cnt);//jugde the whole order and no need to n;
            if(flag == 0)   return 0;
            cnt++;
        }
        else if(lstr == NULL){//only ;
            while(pst != NULL){
                *(res + cnt) = "\n";
                cnt++;
                pst = strchr(pst+1,';');
            }
        }
        else{//order with ;
            while((lstr != NULL) || (lstr == NULL && pst != NULL)){//still have order or only ;
                while((lstr > pst && pst != NULL) || (lstr == NULL && pst != NULL)){
                    *(res + cnt) = "\n";
                    cnt++;
                    pst = strchr(pst+1,';');
                }
                if(lstr != NULL){
                    judge(lstr,cnt);
                    len1 = strlen(lstr);
                    if(lstr+len1 != str+len) *(lstr + len1) = ';';
                    cnt++;
                }
                if(pst == NULL && lstr != NULL) pst = strchr(lstr,';');
                if(flag == 0)   return 0;
                if(pst != NULL) {
                    *(res + cnt) = "\n";
                    cnt++;
                    pst = strchr(pst+1,';');
                }    
                if(lstr != NULL) lstr = strtok(NULL,";");
            }
        }
    }
    for(int i = 0; i < cnt; i++){
        printf("%s",*(res + i));
    }
    return 0;
}
void judge(char *s,int cnt){
    int len;
    len = strlen(s);
    if(isalpha(*s)){
        for(int i = 0; i < len; i++){
            if((isalpha(*(s+i)) == 0 && isdigit(*(s+i))==0) && *(s+i) != '_'){//wrong variable
                printf("Compile Error\n");
                flag = 0;
                return;
            }
        }
        for(int i = 0; i < 16; i++){//reserved
            if(strcmp(s, *(rsvd + i)) == 0){
                res[cnt] = "reserved ";
                return;
            }
        }
        res[cnt] = "variable ";//variable
        return;
    }
    else if(isdigit(*s)){
        int ww=0;
        for(int i = 0; i < len; i++){
            if(*(s+i) == '.' && ww == 0){//maybe float
                ww = 1;
                continue;
            }
            else if(isdigit(*(s+i)) == 0){//wrong float or wrong variable
                printf("Compile Error\n");
                flag = 0;
                return;
            }
        }
        if(ww == 1){
            res[cnt] = "float ";
            return;
        }
        else{
            res[cnt] = "integer ";
            return;
        }
    }
    else{
        if(*s == '_'){
            if(len == 1){
                printf("Compile Error\n");
                flag = 0;
                return;
            }
            for(int i = 1; i < len; i++){
                if(isalnum(*(s+i)) == 0){
                    printf("Compile Error\n");
                    flag = 0;
                    return;
                }
            }
            res[cnt] = "variable ";
            return;
        }
        else{
            for(int i = 0; i < 11; i++){
                if(strcmp(*(oprt + i), s) == 0){
                    res[cnt] = "operator ";
                    return;
                }
            }
            printf("Compile Error\n");
            flag = 0;
            return;
        }
    }
}
/*
possible scanf:
abd; acd;
abc bcd ;
abc ;;
abc;abc;bcd;
*/
/*
first one is digit:
    -i.wrong variable
    -ii.int
    -iii.float
    -iiii.wrong float
first one is alpha:
    -i.variable
    - ii.reserve
    - iii.wrong variable
first one is char:
    i.if it is '_'
    -    a.variable
    -    b.wrong oprt
    -ii.oprt
    -iii.wrong oprt
*/