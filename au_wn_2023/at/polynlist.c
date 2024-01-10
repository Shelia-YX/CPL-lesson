#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
void print(int *coe,char *vari,int len);
int main() {
    //prepare
    char vari[15]={0};
    int fst,snd,*f,*s,*mul,*mns,*pls,max;
    scanf("%d %d",&fst,&snd);
    max = (fst>=snd?fst:snd);
    f = malloc(sizeof(int)*(fst+1));
    memset(f,0,sizeof(int)*(fst+1));
    s = malloc(sizeof(int)*(snd+1));
    memset(s,0,sizeof(int)*(snd+1));
    pls = malloc(sizeof(int)*(max+1));//plus
    memset(pls,0,sizeof(int)*(max+1));
    mns = malloc(sizeof(int)*(max+1));//minus
    memset(mns,0,sizeof(int)*(max+1));
    mul = malloc(sizeof(int)*(fst+snd+1));//multiply
    memset(mul,0,sizeof(int)*(fst+snd+1));
    getchar();
    scanf("%s",vari);
    //get str f and 'mns,pls'
    for(int i = fst; i >= 0; i--){
        scanf("%d",&f[i]);
        pls[i] = f[i];
        mns[i] = f[i];
    }
    //get str s ,mns, pls and mul
    for(int i = snd; i >= 0; i--){
        scanf("%d",&s[i]);
        pls[i] += s[i];
        mns[i] -= s[i];
        for(int j = fst; j >= 0; j--){
            mul[i + j] += f[j]*s[i];
        }   
    }
    //print
    print(pls,vari,max);
    print(mns,vari,max);
    print(mul,vari,fst+snd);
    //end
    free(f);free(s);free(mul);free(mns);free(pls);
    return 0;
}

void print(int *coe,char *vari,int len){
    int flag = 0;
    for(int i = len; i >= 2; i--){
        if(flag == 0 && coe[i]){//first number
            flag = 1;
            switch (coe[i]){
            case 1:
                printf("%s^%d",vari,i);
                break;
            case -1:
                printf("-%s^%d",vari,i);
                break;
            default:
                printf("%d%s^%d",coe[i],vari,i);
                break;
            }
        }
        else if(coe[i]){
            switch (coe[i]){
                case 1:
                    printf("+%s^%d",vari,i);
                    break;
                case -1:
                    printf("-%s^%d",vari,i);
                    break;
                default:
                    if(coe[i] > 0)  printf("+%d%s^%d",coe[i],vari,i);
                    else printf("%d%s^%d",coe[i],vari,i);
                    break;
            }
        }
    }
    if(flag == 0 && coe[1]){//coe[1] is first number
        flag = 1;
        switch (coe[1]){
        case 1:
            printf("%s",vari);
            break;
        case -1:
            printf("-%s",vari);
            break;
        default:
            printf("%d%s",coe[1],vari);
            break;
        }
        if(coe[0] > 0)  printf("+%d",coe[0]);
        else if(coe[0] < 0) printf("%d",coe[0]);
    }
    else if(flag == 1){//coe[1] is not the first number
        switch (coe[1]){
        case 1:
            printf("+%s",vari);
            break;
        case -1:
            printf("-%s",vari);
            break;
        default:
            if(coe[1] > 0) printf("+%d%s",coe[1],vari);
            else if(coe[1] < 0) printf("%d%s",coe[1],vari);
            break;
        }
        if(coe[0] > 0)  printf("+%d",coe[0]);
        else if(coe[0] < 0) printf("%d",coe[0]);
    }
    else printf("%d",coe[0]);
    printf("\n");
}