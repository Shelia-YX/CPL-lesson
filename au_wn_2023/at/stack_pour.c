#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int num;
    struct stk *next;
    struct stk *befo;
}stk;
typedef struct{
    struct stk *a;
    struct stklist *next;
}stklist;
stklist *head = NULL;
void crtstk(stklist **ls, int num);
void schstk(int first, int second, stklist **f, stklist **s);
void pourstk(stklist **f, stklist **s);
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    // 1.create the stack list
    stklist *temp = head;
    for (int i = 1; i <= n; i++){
        crtstk(&temp, i);
        if (i == 1)
            head = temp;
    }
    // 2.do the task
    for (int i = 0; i < m; i++){
        int fst, snd;
        stklist *f, *s;
        scanf("%d %d", &fst, &snd);
        schstk(fst, snd, &f, &s);
        pourstk(&f, &s);
    }
    // 3.print the stacklist
    temp = head;
    for (int i = 0; i < n; i++){
        stk *tmp = (stk *)(temp->a);
        if (tmp == NULL)    printf("0");
        while (tmp != NULL){
            printf("%d ", tmp->num);
            tmp = (stk *)(tmp->next);
        }
        printf("\n");
        temp = (stklist *)(temp->next);
    }
    return 0;
}
void crtstk(stklist **ls, int numb){
    stk *astk = malloc(sizeof(astk));
    stklist *alis = malloc(sizeof(alis));
    if (numb == 1)    *ls = alis;
    else{
        (*ls)->next = (struct stklist *)(alis);
        (*ls) = alis;
    }
    alis->a = (struct stk *)astk;
    astk->num = numb;
    alis->next = NULL;
    astk->next = NULL;
    astk->befo = NULL;
}
void schstk(int first, int second, stklist **f, stklist **s){
    stklist *temp = head;
    int flag = 0, i = 1;
    while (temp != NULL && flag != 2){
        if (i == first){
            *f = temp;
            flag++;
        }
        else if (i == second){
            *s = temp;
            flag++;
        }
        temp = (stklist *)(temp->next);
        i++;
    }
}
void pourstk(stklist **f, stklist **s){
    if ((*f)->a == NULL)    return;
    else{
        stk *temp = (stk *)((*f)->a);
        stk *tails = (stk *)((*s)->a);
        if(tails != NULL){
            while (tails->next != NULL)    tails = (stk *)(tails->next);
        }
        while(temp->next != NULL){//ftail
            temp = (stk *)(temp->next);
        }
        do{
            stk *tmp = malloc(sizeof(tmp));
            tmp->num = temp->num;
            tmp->next = NULL;
            if (tails == NULL){
                (*s)->a = (struct stk *)(tmp);
                tails = (stk *)((*s)->a);
                tmp->befo = NULL;
            }
            else{
                tails->next = (struct stk *)(tmp);
                tmp->befo = (struct stk *)(tails);
                tails = (stk *)(tails->next);
            }
            temp = (stk*)(temp->befo);
        }while (temp != NULL);
        (*f)->a = NULL;
    }
}