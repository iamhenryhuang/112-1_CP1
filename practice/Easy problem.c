//input [0, 1, 2, 3, 4], output [1, 3, 5, 7]. add two adjancent number
#include <stdio.h>

int main(){
        int first, inputnum;
        char comma; // for catch ','
        int ans[1000000] = {}, save[1000000] = {};
        int position = 0;
        
        scanf("[%d%c", &first, &comma);
        save[position++] = first;

        while(comma == ',') {
            scanf(" %d%c", &inputnum, &comma);
            save[position++] = inputnum;
        }

        ans[0] = save[0] + save[1];
        printf("[%d", ans[0]);

        for(int i = 1; i < position - 1; i++){
                ans[i] = save[i] + save[i+1];
                printf(", %d", ans[i]);
        }
        printf("]");
        
        return 0;
}
