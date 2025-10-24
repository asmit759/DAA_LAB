#include <stdio.h>

int max(int a,int b){

    if(a>b){
        return a;
    }else{
        return b;
    }
}

void dknapsack (int m,int wt[],int p[],int n){

    int k[100][100];

    for(int j=0;j<=m;j++){
        k[0][j]=0;
    }

    for(int i=0;i<=n;i++){
        k[i][0] = 0;
    }


    for(int i=1 ;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            if(wt[i-1]<=j){
                k[i][j]=max(k[i-1][j-wt[i-1]]+p[i - 1],k[i-1][j]);
            }
            else{
                k[i][j] = k[i-1][j];
            }
        }
    }

    printf("\n max profit for 01 knapsack = %d",k[n][m]);

}

int main(){

    int m,n;
    printf("enter no of items \n");
    scanf("%d",&n);

    printf("enter max weight for the bag \n");
    scanf("%d",&m);

    int wt[n],p[n];

    for(int i=0;i<n;i++){
        printf("enter wt of %d \n",i);
        scanf("%d",&wt[i]);

        printf("enter p of %d \n",i);
        scanf("%d",&p[i]);
    }

    // for(int i=0;i<n;i++){
    //     printf("enter p of %d",i);
    //     scanf("%d",&p[i]);
    // }

    dknapsack(m,wt,p,n);
    

    return 0;
}