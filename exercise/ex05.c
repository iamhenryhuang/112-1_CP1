//introduction
//有兩個由小排到大的數列(分別存在兩個陣列中)，我們需要把兩個由小排到大的陣列進行一次合併，並且同樣為由小排到大

#include<stdio.h>

int main(){
    long long num1,num2;

    scanf("%lld", &num1);
    int arr1[num1];
    for(int i=0;i<num1;i++){
        scanf("%d", &arr1[i]);
    }
   
    scanf("%lld", &num2);
    int arr2[num2];
    for(int j=0;j<num2;j++){
        scanf("%d", &arr2[j]);
    }

    long long num3=num1+num2;
    int arr3[num3], a=0, b=0, c=0;

    while(a<num1 && b<num2){
        if(arr1[a]<arr2[b]){
            arr3[c]=arr1[a];
            a++;
        }
        else{
            arr3[c]=arr2[b];
            b++;
        }
        c++;
    }

    while(a<num1){
        arr3[c]=arr1[a];
        a++;
        c++;
    }

    while(b<num2){
        arr3[c]=arr2[b];
        b++;
        c++;
    }

    for(int x=0;x<num3;x++){
        printf("%d ", arr3[x]);
    }

    return 0;
}
