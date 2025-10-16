#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000
// int length(int arr[]){
//     int count=sizeof(arr) / sizeof(arr[0]);
//     return count;
// }

void merge(int arr[], int si, int mid, int ei) {
    int i=si;
    int j=mid+1;
    int temp[ei-si+1];
    int k=0;

    while(i<=mid && j<=ei){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }else{
            temp[k]=arr[j];
            k++;
            j++;
        } 
    }
    while(i<=mid){
            temp[k]=arr[i];
            k++;
            i++;
        }
    while(j<=ei){
        temp[k]=arr[j];
        k++;
        j++;
    }
        

    k=0,i=si;
    while(i<=ei){
        arr[i]=temp[k];
        k++;
        i++;
    }

    
}

void mergeSort(int arr[], int si, int ei) {
    if(si>=ei){
        return;
    }
    int mid=si+(ei-si)/2;

    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);

    merge(arr,si,mid,ei);
}

int main() {
    // int arr[SIZE]={1,2,532,32,13};
    // mergeSort(arr,0,4);

    // for(int i=0;i<5;i++){
    //     printf("%d \t",arr[i]);
    // }

    FILE *fin,*fout;
    fin = fopen("input.txt","w");
    for(int i=0;i<SIZE;i++){
        int num=rand()%100;
        fprintf(fin,"%d \n",num);

    }
    fclose(fin);

    fin = fopen("input.txt", "r");

    int arr[SIZE];
    for(int i=0;i<SIZE;i++){
        fscanf(fin,"%d",&arr[i]);
    }
    fclose(fin);

    mergeSort(arr,0,SIZE-1);

    fout=fopen("output.txt","w");
    for(int i=0;i<SIZE;i++){
        fprintf(fout,"%d \n",arr[i]);
    }

    return 0;
}
