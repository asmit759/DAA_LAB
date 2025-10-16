#include <iostream>
using namespace std;
int partition(int arr[],int s,int e){

    int cnt = 0;
    for(int i=s+1;i<e;i++){
        if(arr[i]<arr[s]){
            cnt++;
        }
    }

    int pivotindex = s+cnt;

    swap(arr[s],arr[pivotindex]);

    int i=s;
    int j=e;

    while(i<pivotindex && j>pivotindex){
        while(arr[i]<=arr[pivotindex]){
            i++;
        }

        while(arr[j]>arr[pivotindex]){
            j--;
        }

        if(i<=pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotindex;
}

void quickSort(int arr[],int s,int e){

    if(s>=e){
        return;
    }

    int p = partition(arr,s,e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);

}

int main(){
    int arr[5] = {2,4,1,6,9};
    int n=5;

    quickSort(arr,0,n-1);

    cout<<"take an array find the pivot \n place the pivot in right position so that the left to pivot contain the smaller ele and to its right it shud have larger ele"<<endl;
    cout<<"swap the larger from left to the smaller from right so that the above condition is satisfied"<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "<<endl;
    }

    return 0;
}