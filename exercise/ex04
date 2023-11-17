#include<stdio.h>

int main(void)
{
    int num1,num2;
    while(scanf("%d %d", &num1, &num2)!=EOF)
    {
        int row1=num1,column1=num2;
        int arr1[row1][column1];
        for (int i=0;i<row1;i++)
        {
            for(int j=0;j<column1;j++)
            { 
                scanf("%d", &arr1[i][j]);
            }
        }
    
        int row2,column2;
        scanf("%d %d", &row2, &column2);
        int arr2[row2][column2];
        for (int i=0;i<row2;i++)
        {
            for(int j=0;j<column2;j++)
            {
                scanf("%d", &arr2[i][j]);
            }
        }
    
        if(column1 != row2)
        {
            printf("Invalid calculation!!\n");
            continue;
        }

        int arr3[row1][column2];
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<column2;j++)
            {
                arr3[i][j]=0;
                for(int n=0;n<column1;n++)
                {
                    arr3[i][j] += arr1[i][n]*arr2[n][j];
                }
            }
        }

        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<column2;j++)
            {
                printf("%d", arr3[i][j]);
                    if(j!=column2-1)
                    {
                        printf(" ");
                    }
            }
            printf("\n");
        }
    }

    return 0;
}
