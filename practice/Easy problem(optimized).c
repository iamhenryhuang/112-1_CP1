//input [0, 1, 2, 3, 4], output [1, 3, 5, 7]. add two adjancent number
#include <stdio.h>

int main(){
        scanf("[");
        int first, inputnum;
        char comma;
        int ans[10000] = {};
        int position = 0;
        
        scanf("%d%c", &first, &comma);
        while(comma == ',') {
            scanf(" %d%c", &inputnum, &comma);
            ans[position++] = first + inputnum;
            first = inputnum;
        }

        printf("[%d", ans[0]);
        for(int i = 1; i < position; i++){
                printf(", %d", ans[i]);
        }
        printf("]");
        
        return 0;
}
