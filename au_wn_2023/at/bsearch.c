#include <stdio.h>
#include <stdlib.h>
int comp(const void *a,const void *b);
int main(){
    int n,q,ord,*ele,*plz;
    ele = malloc(106 * sizeof(int));
    scanf("%d %d",&n,&q);
    for(int i = 0; i < n; i++){
        scanf("%d",ele + i);
    }
    for(int i = 0; i < q; i++){
        scanf("%d",&ord);
        comp(&ord,ele);
        plz = (int*)bsearch(&ord,ele,n,sizeof(int),comp);
        if(plz != NULL) printf("%d\n",(int)(plz-ele));
        else printf("-1\n");
    }
    free(ele);
    return 0;
}
int comp(const void *a,const void *b){
    if(*(int*)a > *(int*)b)   return 1;
    else if(*(int*)a == *(int*)b) return 0;
    else    return -1;
}