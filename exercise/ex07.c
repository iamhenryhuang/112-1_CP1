#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    char str[1000];
    char destination[1000]; //存放字串取出的數值
    int start;
    
    while(scanf("%s", str)!=EOF){
        long count=0;
        for(int i=0;i<strlen(str);i++){ //strlen字串長度
            if(isdigit(str[i]) || str[i]=='-'){
                start=i; //start即是開始是數字的開頭，start不能動
                int current=i+1; //current是會繼續往下跑，直到讀到不是數字，+1是因為如果遇到負號，正號就沒差
                while(isdigit(str[current])){
                    current++;
                }
                strncpy(destination, str+start, current-start); //strncpy(新存放的陣列,舊陣列遇到數字的開端,數值總共佔多少位置[例如123是3個])
                destination[current-start] = '\0'; //很重要 要告知結尾 不然會出現亂數
                char *end;
                count += strtol(destination, &end, 10);
                i=current-1; //上面為求數字最後出現+1，所以回去要-1
            }
        }
        printf("%ld\n", count);
    }

    return 0;
}

//introduction
//每行input會是整數(含負數)和字母的混合字串，請輸出每行出現數字的總和
//測資包含多行由數字（N 為正負整數）和任意字母的組成的混合字串，請輸出混合字串中的數字總和
