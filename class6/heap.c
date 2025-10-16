#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (arr[left] > arr[largest] && left < n)
        largest = left;

    if (arr[right] > arr[largest] && right < n)
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[],int n ){
    buildMaxHeap(arr,n);
    for(int i=n-1;i>=1;i--){
        int temp = arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        n=n-1;
        heapify(arr,n,0);
    }
}

int main()
{
    int arr[7] = {1,2,3,4,5,6,7};
    int n = 7;

    buildMaxHeap(arr, n);
    heapSort(arr,n);

    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
