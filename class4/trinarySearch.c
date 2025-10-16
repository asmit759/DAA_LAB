#include <stdio.h>
#include <time.h>
int trinarySearch(int arr[],int l,int h, int key){
  if (l > h) {
        return -1;
    }

    int mid1 = l + (h - l) / 3;
    int mid2 = h - (h - l) / 3;

    if (arr[mid1] == key) {
        return mid1;
    }
    if (arr[mid2] == key) {
        return mid2;
    }

    if (key < arr[mid1]) {

        return trinarySearch(arr, l, mid1 - 1, key);

    } else if (key > arr[mid2]) {

        return trinarySearch(arr, mid2 + 1, h, key);

    } else {

        return trinarySearch(arr, mid1 + 1, mid2 - 1, key);

    }
}

int main(){

    int arr[9] = {18,22,31,45,56,63,72,81,90};
    int si=0;
    int ei=8;
    int key=56;

    clock_t start=clock();
    int ans=trinarySearch(arr,si,ei,key);
    clock_t end=clock();

    printf("%d",ans);


    double cpu_time = ((double)(end-start))/CLOCKS_PER_SEC ;
    printf("\n%lf",cpu_time);
    return 0;
}