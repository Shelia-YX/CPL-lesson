#include <stdio.h>
int main(){
    int n,m,t,flag=0,min,count=0;
    int mino;
//    int count=0,min;
    int A[106],B[106];//change!!!!
    scanf("%d %d %d",&n,&m,&t);
    for (int i = 0; i < n; i++){
        scanf("%d",&A[i]);
        A[i] = t - A[i];
    }
    for (int i = 0; i < m; i++){
        scanf("%d",&B[i]);
        if (A[0] >= B[i])
            flag = 1;
    }
    if (flag == 0){
        printf("-1");
        return 0;
    }
    int hd=0,tl=n-1;
    for (int i = 0; i < m; i++){
        hd=0,tl=n-1;
        while(tl-hd > 1){
            if (B[i] < A[(hd+tl)/2])    hd = (hd+tl)/2;
            else if (B[i] > A[(hd+tl)/2])    tl = (hd+tl)/2;
            else {
                printf("0");
                return 0;
            }    
        }
        if (A[hd]-B[i]>=0){
            mino = A[hd]-B[i];
            if(A[tl] >= B[i])   mino = A[tl] - B[i];
            if (count == 0) {
                min=mino;
                count = 1;
            }
            else if (min > mino)  min = mino;
        } 
    }
    printf("%d",min);
    return 0;
}
/*    for(int i = n-1; i >=0; i--){
        for(int j = 0; j < m; j++){
            if(A[i]-B[j] >= 0){
                if(count == 0){
                    min=A[i]-B[j];
                    count=1;
                }   
                else if(A[i]-B[j] < min)    min=A[i]-B[j];
            }
        }
        if (count == 1){
            printf("%d",min);
            return 0;
        }
    }
}*/