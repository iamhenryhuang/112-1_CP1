//print spiral matrix
#include <stdio.h>

void generateSpiral(int rows, int cols, int matrix[rows][cols]) {
    int num = 1;
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Fill top row from left to right
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        // Fill rightmost column from top to bottom
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // Fill bottom row from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        // Fill leftmost column from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%-8d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    while(scanf("%d", &rows)!=EOF){
        cols = rows;

        int matrix[rows][cols];

        generateSpiral(rows, cols, matrix);

        printMatrix(rows, cols, matrix);
    }
    
    return 0;
}
