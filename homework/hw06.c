//introduction
//對一組數字進行排序，排序的規則是根據一個自定義的 value 函數的結果。在排序的過程中，如果兩個數字經過 value 函數後得到的值相同，則按照原始數字的大小進行排序。

//rule
//Even number: +20
//Odd number: +0
//each "1" or "8" contains in the number: -3
//each even number contains in the number: +1
//finally, add each digit of the number into the lucky value.
//If two numbers have the same lucky value, someone will prefer the smaller number.

#include<stdio.h>
#include<stdlib.h>

// void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int ascending (const int *a, const int *b) {
    int lucky1=value(*a);
    int lucky2=value(*b);
    if(lucky2==lucky1){
            return *a>*b;
        }
    else 
        return lucky2>lucky1;
}

int value(int inputnum);

int main(){
    int num;
    scanf("%d", &num);
    int inputnum;
    int save[num];
    for(int i=0;i<num;i++){
        scanf("%d", &inputnum);
        //printf("%d\n", value(inputnum));
        save[i]=inputnum;
    }
    qsort(save, sizeof(save) / sizeof(save[0]), sizeof(save[0]), ascending); //save=save陣列的起始位置 save[0]=int的大小
    for(int a=0;a<num;a++){
        printf("%d ", save[a]);
    }
    return 0;
}
int value(int inputnum){
    int counter=0;
    if(inputnum%2==0){
        counter+=20;
    }
    if(inputnum%2==1){
        counter+=0;
    }
    while(inputnum!=0){
        if((inputnum%10)==1||(inputnum%10)==8){
            counter-=3;
        }
        if((inputnum%10)%2==0){
            counter+=1;
        }
        counter+=(inputnum%10);
        inputnum/=10;  
    }
    return counter; 
}
