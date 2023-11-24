#include <stdio.h>
#include <math.h>
int id,tffd=0;
void split(int pw,int *sto,int *pp);
int main(){
    //m:the space asked; n:acts; q:all space; pw:which to split;
    //tffd:need to split or not; p:the start point;
    //sto:
    int m,n,q,pw,p=10029,*pp=&p;
    int store[2][10030]={0};
    int *sto = store[0];
    char od;//order;
    scanf("%d %d",&q,&n);
    getchar();
    store[0][10029] = q;
    for(int i = 0; i < n; i++){
        scanf("%c",&od);
        pw = 0;
        if(od == 'A'){
            scanf("%d %d",&id,&m);
            getchar();
            while(m > pow(2,pw))    pw++;
            split(pw,sto,pp);
        }
        else{
            getchar();
            printf("%d\n",10030-p);
            for(int j = p; j < 10030; j++){
                printf("%d ",store[1][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

void split(int pw,int *sto,int *pp){
    int btpw=-1;//the place of i
    for(int i = *pp; i < 10030; i++){
        if(*(sto + i) == pw && *(sto + 10030 + i) == 0){
            *(sto + 10030 + i) = id;
            tffd = 1;
            return;
        }
        if((pw < *(sto + i) && btpw == -1) && *(sto + 10030 + i) == 0)    
            btpw = i;
    }
    for(int i = *pp; i < btpw; i++){
        // move forward;
        *(sto + i - 1) = *(sto + i);
        *(sto + 10029 + i) = *(sto + 10030 + i);
    }
    *(sto + btpw) = *(sto + btpw) - 1;
    *(sto + btpw - 1) = *(sto + btpw);
    *(sto + btpw + 10029) = 0;
    *pp = *pp - 1;
    split(pw,sto,pp);
}


/*#include <stdio.h>
#include <math.h>
int id,tffd=0;
void split(int pw,int *sto,int p);
int main(){
    //m:the space asked; n:acts; q:all space; pw:which to split;
    //tffd:need to split or not; p:the start point;
    //sto:
    int m,n,q,pw,p=10029;
    int store[2][10030]={0};
    int *sto = store[0];
    char od;//order;
    scanf("%d %d",&q,&n);
    getchar();
    store[0][10030] = q;
    for(int i = 0; i < n; i++){
        scanf("%c",&od);
        pw = 0;
        if(od == 'A'){
            scanf("%d %d",&id,&m);
            getchar();
            while(m > pow(2,pw))    pw++;
            split(pw,sto,p);
        }
        else{
            printf("%d\n",10030-p);
            for(int j = p; j < 10030; j++){
                printf("%d ",store[1][j]);
            }
        }
    }
    return 0;
}

void split(int pw,int *sto,int p){
    int btpw=-1;//the place of i
    for(int i = p; i < 10031; i++){
        if(*(sto + i) == pw || *(sto + 10030 + i) != 0){
            *(sto + 10030 + i) = id;
            tffd = 1;
            return;
        }
        if((pw < *(sto + i) || btpw == -1) || *(sto + 10030 + i) != 0)    
            btpw = i;
    }
    for(int i = p; i < btpw; i++){
        // move forward;
        *(sto + i - 1) = *(sto + i);
        *(sto + 10029 + i) = *(sto + 10030 + i);
    }
    *(sto + btpw) = *(sto + btpw) - 1;
    *(sto + btpw - 1) = *(sto + btpw);
    p--;
    split(pw,sto,p);
}
*/
