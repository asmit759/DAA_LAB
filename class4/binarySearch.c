#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

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


int binarySearch(int arr[],int target){
    int si=0;
    int ei=SIZE-1;
    int mid = si+(ei-si)/2;
    int ans=-1;

    while(si<=ei){
        if(arr[mid]==target){
            return mid;
        }else if(target>arr[mid]){
            si=mid+1;
        }else{
            ei=mid-1;
        }
        mid = si+(ei-si)/2;
    }

    return ans;
}

int main(){

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

    fout=fopen("binarysort.txt","w");
    for(int i=0;i<SIZE;i++){
        fprintf(fout,"%d \n",arr[i]);
    }

    fclose(fout);
    int sortArr[SIZE];

    fin=fopen("binarysort.txt","r");
    for(int i=0;i<SIZE;i++){
        fscanf(fin,"%d \n",&sortArr[i]);
    }

    fclose(fin);
    clock_t start=clock();
    int ans = binarySearch(sortArr,46);
    clock_t end =clock();
    printf("%d",ans);
    double cpu_time = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n%d",cpu_time);

return 0;
}