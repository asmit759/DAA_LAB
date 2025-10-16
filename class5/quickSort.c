#include <stdio.h>

int partition(int arr[],int s, int e){
    int pivot = arr[s];
    int cnt = 0;

    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    int pivotindex= s+cnt;
    int temp = arr[pivotindex];
    arr[pivotindex]=arr[s];
    arr[s]=temp;

    int i=s ,j=e;
     while(i < pivotindex && j > pivotindex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotindex && j > pivotindex) {
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            
            i++;
            j++;
        }

    }


    return pivotindex;

}

void quickSort(int arr[] , int s, int e){
    if(s>=e){
        return;
    }

    int p=partition(arr,s,e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main(){
    int arr[6] = {2,5,7,1,9,27};

    int n=6;

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }


    return 0;
}