#include<stdio.h>

int main(void)
{
    int num;

    while(scanf("%d", &num)!=EOF)
    {
        int arr[num][num];
        int value1=0,value2=0,value3=1;
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        
        for(int i=0;i<num;i++)
        {
            int checksum1=0;
            for(int j=0;j<num;j++)
            {
                checksum1 += arr[i][j];
            }
            if(checksum1 != ((1+num)*num)/2)
                {
                    continue;
                }
            
            else
                {
                    value1++;
                }
        }
        
        for(int j=0;j<num;j++)
        {
            int checksum2=0;
            for(int i=0;i<num;i++)
            {
                checksum2 += arr[i][j];
            }
            
            if(checksum2 != ((1+num)*num)/2)
                {
                    continue;
                }
            else
                {
                    value2++;
                }
        }

        for(int a=0;a<num-1;a++)
        {
            int correct=0;
            for(int n=0;n<num-1;n++)
            {
                int correct=0;
                for(int m=n+1;m<num;m++)
                {
                    if(arr[a][n]==arr[a][m])
                    {
                        correct=1;
                        break;
                    }
                }
                if(correct==1)
                {
                    value3=0;
                    break;
                }
            }
            if(correct==1)
                {
                    value3=0;
                    break;
                }
        }
        
        if((value1==num && value2==num) && value3==1)
            printf("Correct\n");
        else
            printf("Wrong\n");
    }
    
    return 0;
}
