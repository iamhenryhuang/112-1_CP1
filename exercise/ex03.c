#include<stdio.h>

int main(void)
{
    int input;
 
    while(scanf("%d", &input)!=EOF)
    { 
        int arr1[input][input];
        for(int i=0;i<input;i++)
        {
            for(int j=0;j<input;j++)
            {
                scanf("%d", &arr1[i][j]);
            }
        }
        for(int i=0;i<input;i++)
        {
            for(int j=input-1;j>=0;j--)
            {
                printf("%d ", arr1[j][i]);
            }
            printf("\n");
        }
    }
    
    return 0;
}

//接收一個整數 input，然後根據這個整數建立一個二維陣列 arr1，接著使用巢狀迴圈，將二維陣列每一列的元素進行反向輸出
