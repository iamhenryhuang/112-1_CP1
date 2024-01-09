//introduction
//Your task is to develop a program to determine if a given matrix is testable or not.
//If the matrix is non-testable and only required to change one bit to fulfill the condition, your program should be able to point out which bit should be changed.
//Otherwise, the matrix should be classified as a corrupt one.

//input
//The input file will contain one or more test cases.
//The first line of each test case contains an integer n (n < 100), representing the size of the square matrix. On the next n lines, there will be n integers per line.
//Note. No other integers than 0 and 1 will occur in the matrix. Input will be terminated by a value of 0 for n.

//output
//For each matrix in the input file, print one line.
//If the matrix is testable, print 'OK'.
//If the testable boolean matrix can be established by changing one bit, print 'Change bit (i,j)' where i is the row and j is the column of the bit to be changed.
//Otherwise, print 'Corrupt'.

#include<stdio.h>

int main(void)
{
    int num;
    while(scanf("%d", &num) != EOF)
    {
        if(num == 0)
        {
            break;
        }
        int arr1[num][num];
        int value1=0,value2=0,value3=0,value4=0;
        int wrong1,wrong2;
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                scanf("%d", &arr1[i][j]);
            }
        }

        for(int i=0;i<num;i++)
        {
            int checksum1=0;
            for(int j=0;j<num;j++)
            {
                checksum1 += arr1[i][j];
            }
            if(checksum1 % 2 == 0)
            {
                value1++;
            }
            else
            {
                continue;
            }
        }

        for(int i=0;i<num;i++)
        {
            int checksum2=0;
            for(int j=0;j<num;j++)
            {
                checksum2 += arr1[j][i];
            }
            if(checksum2 % 2 == 0)
            {
                value2++;
            }
            else
            {
                continue;
            }
        }

        if (value1 == num && value2 == num)
        {
            printf("OK\n");
        }
        else
        {
            for(int i=0;i<num;i++)
            {
                int checksum3=0;
                for(int j=0;j<num;j++)
                {
                    checksum3 += arr1[i][j];
                }
                if(checksum3 % 2 != 0)
                {
                    value3++;
                    if(value3 == 1)
                    {
                        wrong1=i;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    continue;
                }
            }

            for(int i=0;i<num;i++)
            {
                int checksum4=0;
                for(int j=0;j<num;j++)
                {
                    checksum4 += arr1[j][i];
                }
                if(checksum4 % 2 != 0)
                {
                    value4++;
                    if(value4 == 1)
                    {
                        wrong2=i;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    continue;
                }
            }
            if(value3 == 1 && value4 == 1)
            {
                printf("Change bit (%d,%d)\n", wrong1+1, wrong2+1);
            }
            else
            {
                printf("Corrupt\n");
            }
        }
    }

    return 0;
}
