//introduction
//切字串變成字母，判斷有沒有在字典裡面，輸出是依照字母的大小排(由小排到大)，並附上出現幾次

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int ascending(const void *a, const void *b){
    return strcmp(*(const char **)a, *(const char **)b); //由小排到大  解引用指標 a 和 b 後得到的字符串指標。
}

int main(){
    char str[10000];
    const char delete[]=","; //要切字串的判斷
    char *save[10000];
    int position=0;

    scanf("%s", str);
    
    char *token = strtok(str, delete); //strtok返回的值是一個指向字串的指針

    while(token!=NULL && position<10000){
        save[position] = token;        //先存第一個strtok下來的字串      
        token=strtok(NULL, delete);
        position++; //存放切下來字串的陣列位置
    }
    
    qsort(save, position, sizeof(save[0]), ascending); // save=指向想要排序的元素集合 position=save的裡面數值的量 
                                                       //sizeof(save[])=每個元素的大小 以byte為單位 ascending=比較函式

    char str1[10000]; //input存放處

    while(scanf("%s", str1)!=EOF){
        int position2=0; //輸入後拿來跑位置在那的值
        int flag=0;
        for(int i=0;i<position;i++){
            if(str1[0]==save[i][0]){ //輸入字串的開頭字母是否跟字典內字串的開頭相同
                if(strcmp(str1, save[i])!=0){ //輸入跟字典內的字串不相同 所以position2往後移
                    position2++;
                }
                else{
                    printf("%c %d\n", toupper(str1[0]), position2+1);
                    flag++;
                }
            }
        }
        if(flag==0){
            printf("NOT FOUND\n");
        }
    }

    return 0;
}
