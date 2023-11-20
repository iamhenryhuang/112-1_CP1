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

//https://wm5.nccu.edu.tw/base/10001/course/10027586/content/asgmt06/index.html
