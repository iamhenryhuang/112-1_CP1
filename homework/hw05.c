#include<stdio.h>

int main()
{
    char step1;
    int step2;
    int empty=0;
    int chess[15][15]={{}};

    while(scanf(" %c %d", &step1, &step2)!=EOF){
        empty++;
        if(step1-'A'>14 || step2>15){
            printf("Invalid move at step %d.\n", empty);
            return 0;
        }
        if(chess[step2-1][step1-'A']==1 || chess[step2-1][step1-'A']==2){
            printf("Invalid move at step %d.\n", empty);
            return 0;
        }
        if(empty%2!=0){
            chess[step2-1][step1-'A']=1; //1=black
        }
        else{
            chess[step2-1][step1-'A']=2; //2=white
        }
        
        for(int i=0;i<15;i++){
            for(int j=0;j<=10;j++){
               int flag1=0,flag2=0;
               for(int k=0;k<5;k++){
                if(chess[i][j+k]==1){
                    flag1++;
                }
                else if(chess[i][j+k]==2){
                    flag2++;
                }
               }
               if(flag1==5){
                printf("The winner is black.\n");
                return 0;
               }
               else if(flag2==5){
                printf("The winner is white.\n");
                return 0;
               }
               else{
                continue;
               }
            }
        }
        
        for(int j=0;j<15;j++){
            for(int i=0;i<=10;i++){
               int flag1=0,flag2=0;
               for(int k=0;k<5;k++){
                if(chess[i+k][j]==1){
                    flag1++;
                }
                else if(chess[i+k][j]==2){
                    flag2++;
                }
               }
               if(flag1==5){
                printf("The winner is black.\n");
                return 0;
               }
               else if(flag2==5){
                printf("The winner is white.\n");
                return 0;
               }
               else{
                continue;
               }
            }
        }

        for(int i=0;i<=10;i++){
            for(int j=0;j<=10;j++){
               int flag1=0,flag2=0;
               for(int k=0;k<5;k++){
                if(chess[i+k][j+k]==1){
                    flag1++;
                }
                else if(chess[i+k][j+k]==2){
                    flag2++;
                }
               }
               if(flag1==5){
                printf("The winner is black.\n");
                return 0;
               }
               else if(flag2==5){
                printf("The winner is white.\n");
                return 0;
               }
               else{
                continue;
               }
            }
        }

        for(int i=0;i<=10;i++){
            for(int j=14;j>=4;j--){
               int flag1=0,flag2=0;
               for(int k=0;k<5;k++){
                if(chess[i+k][j-k]==1){
                    flag1++;
                }
                else if(chess[i+k][j-k]==2){
                    flag2++;
                }
               }
               if(flag1==5){
                printf("The winner is black.\n");
                return 0;
               }
               else if(flag2==5){
                printf("The winner is white.\n");
                return 0;
               }
               else{
                continue;
               }
            }
        }
    }
    printf("The game is tie.\n");

    return 0;
}

//https://wm5.nccu.edu.tw/base/10001/course/10027586/content/asgmt05/index.html
