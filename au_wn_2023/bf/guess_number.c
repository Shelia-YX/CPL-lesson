#include <stdio.h>//输入输出库
#include <stdlib.h>//标准库
#include <time.h>//时间

void menu(){
    printf("**************\n");
    printf("****0.exit****\n");
    printf("****1.plat****\n");
    printf("**************\n");
    
}

void playgame(){
    int magic =rand()%100+1;
    int guess;
    int counter=0;
    do{
        printf("夏彦新卡几抽出的？\n");
        scanf("%d",&guess);
        counter++;
        if(guess>magic){
            printf("祝你吃大保底（恼）\n");
        }
        else if (guess<magic){
            printf("这辈子没这么欧过（恼）\n");
        }
        
        else{
            printf("焯，你怎么知道？（狗头）\n");
        }    
    }while (guess!=magic);
        printf("你猜了%d次,祝你下次抽卡%d次出货\n",counter,counter);
}


//void menu();
//void playgame();

int main(){
    int input=0;
    srand((unsigned int)time(0));
    do{
        menu();
        scanf("%d",&input);
        switch(input){
            case 1:playgame();
            case 0:break;
            default:printf("请不要用斯沃尔特语和我说话><\n");
        }
    }while(input);
    return 0;
}