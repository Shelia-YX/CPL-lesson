#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if(num1 > num2)return -1;
    else if(num1 == num2)return 0;
    else return 1;
}
int main() {
    int n=0;
    scanf("%d",&n);
    int x1[1005][20]={0};
    int x2[1005][20]={0};
    int x3[1005][20]={0};
    char team[1005][10];
    char name[100];
    int sum[10][1000]={0};
    int sum_[10][1000]={0};
    for (int i = 0; i <n; ++i) {
        scanf("%s",team[i]);
        getchar();
        for (int j = 0; j < 11; ++j) {
            scanf("%s",name);
            getchar();
            scanf("%d %d %d",&x1[i][j],&x2[i][j],&x3[i][j]);
            sum[0][i]+=x1[i][j];
            sum[1][i]+=x2[i][j];
            sum[2][i]+=x3[i][j];
            sum_[0][i]+=x1[i][j];
            sum_[1][i]+=x2[i][j];
            sum_[2][i]+=x3[i][j];
        }
    }
    //输入,统计总和
    for (int i = 0; i < 3; ++i) {
        qsort(sum[i],n,sizeof(int),compare);
    }
    //降序排序
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) {      //在数组sum_中找到与sum一样的值，输出对应的team
                if(sum_[i][l]==sum[i][j]){
                    printf("%s",team[l]);
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
