#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct//define the struct
{
    char member[25];
    int attact;
    int guard;
    int org;
}fifa;
int cmp1(const void *a,const void *b);
int cmp2(const void *a,const void *b);
int cmp3(const void *a,const void *b);
int main(){
    int n,att,grd,orga;
    char temp[25];
    fifa all[1005];
    scanf("%d",&n);
    for(int i = 0; i < n; i++){//fill all data;
        scanf("%s",all[i].member);
        all[i].attact = 0;
        all[i].guard = 0;
        all[i].org = 0;
        for(int j = 0; j < 11; j++){
            scanf("%s %d %d %d",temp,&att,&grd,&orga);
            all[i].attact += att;
            all[i].guard += grd;
            all[i].org += orga;
        }
    }
    qsort(all,n,sizeof(all[0]),cmp1);//attact
    for(int i = 0; i < n; i++)  printf("%s ",all[i].member);
    printf("\n");
    qsort(all,n,sizeof(all[0]),cmp2);//guard
    for(int i = 0; i < n; i++)  printf("%s ",all[i].member);
    printf("\n");
    qsort(all,n,sizeof(all[0]),cmp3);//org
    for(int i = 0; i < n; i++)  printf("%s ",all[i].member);
    printf("\n");
    return 0;
}
int cmp1(const void *aa,const void *bb){
    fifa *a,*b;
    a = (fifa*)aa;
    b = (fifa*)bb;
    if(a->attact > b->attact)   return -1;
    else if(a->attact == b->attact) return 0;
    else return 1;
}
int cmp2(const void *aa,const void *bb){
    fifa *a,*b;
    a = (fifa*)aa;
    b = (fifa*)bb;
    if(a->guard > b->guard)   return -1;
    else if(a->guard == b->guard) return 0;
    else return 1;
}
int cmp3(const void *aa,const void *bb){
    fifa *a,*b;
    a = (fifa*)aa;
    b = (fifa*)bb;
    if(a->org > b->org)   return -1;
    else if(a->org == b->org) return 0;
    else return 1;
}