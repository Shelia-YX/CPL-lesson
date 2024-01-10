#include <stdio.h>
#include <stdlib.h>
typedef struct//define the chain table
{
    int a;
    struct node *next;
}node;
node *head = NULL;

void CreateList(int a);
void Createtail(int a);
void Outputlist(node *a);
void Deletelist(node *a);
void Interrupt(int a,int pst);
void Deletepoint(int pst);
void Searchlist(int num);

int main(){
    int num,pstion;
    while(1){
        scanf("%d",&num);
        if(num != -1)    CreateList(num);  
        else break;
    }
    scanf("%d",&num);
    while(num != -1){
        Createtail(num);
        scanf("%d",&num);
    }
    Outputlist(head);
    printf("\n");
    scanf("%d %d",&num,&pstion);
    Interrupt(num,pstion);
    Outputlist(head);
    printf("\n");
    scanf("%d",&pstion);
    Deletepoint(pstion);
    Outputlist(head);
    scanf("%d",&num);
    Searchlist(num);
    Deletelist(head);
    return 0;
}

void Outputlist(node *a){//print the chain table
    for(node *p = a; p != NULL; p=(node*)(p->next)){
        printf("%d ",p->a);
    }
}

void Deletelist(node *a){//delete the chain table
    while(a){
        node *b = a;
        a=(node*)(b->next);
        free(b);
    }
}

void CreateList(int num){//fill the table from the top
    node *p = (node*)malloc(sizeof(node));
    p->a = num;
    if(head == NULL){
        head = p;
        p -> next = NULL;
    }
    else{
        p -> next = (struct node*)head;
        head = p;
    }
}

void Createtail(int num){//fill the table from the tail
    node *p = (node*)malloc(sizeof(node));
    p -> a = num;
    p -> next = NULL;
    if(head == NULL){
        head = p;
    }
    else{
        node *q = head;
        while(q -> next != NULL)    q = (node*)(q -> next);
        q -> next = (struct node*)p;
    }
}

void Interrupt(int num,int pst){//put a new point in the exist list
    node *p = (node*)malloc(sizeof(node));
    p -> a = num;
    node *q = head;
    int j = 1;
    while(j < pst && q -> next != NULL){
        q = (node*)(q -> next);
        j++;
    }
    if(j == pst){
        node *temp;
        temp = (node*)(q -> next);
        q -> next = (struct node*)p;
        p -> next = (struct node*)(temp);
    }
    else printf("Failed to get to the position\n");
}

void Deletepoint(int pst){//delete the point in given position
    node *q = head;
    if(pst == 1){
        head = (node*)(head -> next);
        free(q);
    }    
    else{
        node *p = NULL;
        int i = 1;
        while(i < pst && q->next != NULL){
            p = q;
            q = (node*)(q -> next);
            i++;
        }
        if(i == pst){
            p -> next = q -> next;
            free(q);
        }
    }
}

void Searchlist(int num){//search the given number
    node *q = head;
    int pst=1,tf=0;
    while(q != NULL){
        if(q -> a == num){
            tf = 1;
            printf("Success get:The position is %d\n",pst);
            break;
        }
        q = (node*)(q->next);
        pst++;
    }
    if(tf == 0) printf("Failed to get the same number\n");
}