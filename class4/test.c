#include <stdio.h>

int max(int arr[],int n,int num){
    int max=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>max && arr[i]<num){
            max=arr[i];
        }
    }
    return max;

}
int maxm(int arr[],int n){
    int max=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;

}

void min(int arr[],int n){
    int min=1000;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    printf("%d",min);

}

int main(){

    int arr[5];
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    max(arr,5,max(arr,5,maxm(arr,5)));
    min(arr,5);

    return 0 ;
}