//introduction
//用DFS深度搜尋去找邊界，並計算出邊界大小

#include <stdio.h>
#include <stdlib.h>

#define maximum_n 1000
#define maximum_m 1000

int visited[maximum_n][maximum_m];
int directionsX[] = {-1, 1, 0, 0};
int directionsY[] = {0, 0, -1, 1};

int calculateBoundary(int canvas[maximum_n][maximum_m], int n, int m, int x, int y, int color) {
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || canvas[x][y] != color) {
        return 0;
    }

    visited[x][y] = 1;
    int boundary = 4;

    for (int i = 0; i < 4; i++) {
        int new_x = x + directionsX[i];
        int new_y = y + directionsY[i];

        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && canvas[new_x][new_y] == color) {
            boundary--;
        }
    }

    for (int i = 0; i < 4; i++) {
        int new_x = x + directionsX[i];
        int new_y = y + directionsY[i];

        boundary += calculateBoundary(canvas, n, m, new_x, new_y, color);
    }

    return boundary;
}

void sort(int *arrBoundary, int sizeCount) {
    for (int i = 0; i < sizeCount - 1; i++) {
        for (int j = 0; j < sizeCount - i - 1; j++) {
            if (arrBoundary[j] < arrBoundary[j + 1]) {
                int temp = arrBoundary[j];
                arrBoundary[j] = arrBoundary[j + 1];
                arrBoundary[j + 1] = temp;
            }
        }
    }
}

void printBoundaries(int *arrBoundary, int sizeCount) {
    for (int i = 0; i < sizeCount; i++) {
        printf("%d", arrBoundary[i]);
        if (i < sizeCount - 1) {
            printf(" ");
        }
    }
}

int main() {
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    int paint[maximum_n][maximum_m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &paint[i][j]);
            visited[i][j] = 0;
        }
    }

    int boundaries[maximum_n * maximum_m];
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0 && paint[i][j] != 0) {
                boundaries[count++] = calculateBoundary(paint, n, m, i, j, paint[i][j]);
            }
        }
    }

    sort(boundaries, count);
    printBoundaries(boundaries, count);

    return 0;
}
