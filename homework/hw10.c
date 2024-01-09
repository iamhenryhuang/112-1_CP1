/*Introduction
Given an m * n 2D binary grid which represents a map of'1's (land) and'0's (water), print out the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.*/

/*Input
An m x n2 D binary grid.
m is the length of the grid
n is the length of grid[i]
1 <= m, n <= 300
grid[i][j]is '0' or '1'.*/

//Output - Print out the number of islands.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROW 600
#define COL 600

int isSafe(int row, int col, int matrix[ROW][COL]) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (matrix[row][col] == 1);
}

void DFS(int row, int col, int matrix[ROW][COL]) {
    int directionsX[] = {-1, 0, 1, 0};
    int directionsY[] = {0, 1, 0, -1};
    
    matrix[row][col]=0;

    for (int k = 0; k < 4; ++k) {
        int newRow = row + directionsX[k];
        int newCol = col + directionsY[k];

        if (isSafe(newRow, newCol, matrix)) {
            DFS(newRow, newCol, matrix);
        }
    }
}

int findIslands(int matrix[ROW][COL]) {
    int count=0;
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            if (matrix[i][j] == 1) {
                count++;
                DFS(i, j, matrix);
            }
        }
    }
    return count;
}

int main(){
    //n是長=length，m是寬=width
    int length=0, width;
    char input[600];
    int grid[ROW][COL] = {};
    int count;
    
    while(scanf("%[^\n]\n", input)!=EOF){
        int b=0;
        for(int i=0;i<strlen(input);i++){
            if(input[i]==' '){
                continue;
            }
            else{
                grid[length][b] = (input[i]-'0');
                b++;
            }
        }

        length++;
    }

    width = (strlen(input)+1)/2;

    count = findIslands(grid);

    printf("%d", count);
        
    return 0;
}
