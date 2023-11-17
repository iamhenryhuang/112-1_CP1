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
