#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int main(){
    //int a[3]={1};
    //printf("%d",a[1]);
    //int a[5]={4,3,6,2,5};
    //for (int i = 0; i < 5; i++) {
      //  for (int j = 0; j < 5 - i - 2; j++) { // not j < n - i - 1
        //    if (a[j] > a[j + 1]) {
          //  int tmp = a[j];
         //   a[j] = a[j + 1];
       //     a[j + 1] = tmp;
        //    }//    }//    }
  //  for (int i = 0; i < 5; i++){
    //    printf("%d",a[i]);//}
    char str[100][100]={0};
    for(int i=0;i<2;i++){
        scanf("%s",str[i]);
        putchar(str[i][15]);
    }
    int board[3][3] = {
      [0]:{ 0 },

    };
    
    return 0;
}

