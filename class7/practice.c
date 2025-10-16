#include <stdio.h>

int knapsack(int n , float weight[],  float profit[],float capacity){

    float totalProfit=0;
    float u=capacity;
    int i;
    float ans[20];

    for (int i=0;i<n;i++){
        ans[i]= 0.0;
    }

    for( i=0;i<n;i++){

        if(weight[i]>u){
            break;
        }

        totalProfit+=profit[i];

        u-=weight[i];

        ans[i]=1;

    }

    if(i<n){
        ans[i] = u/weight[i];
        totalProfit += ans[i]*profit[i];
    }

    //print ans and can also retiurn the profit
    

    return totalProfit;
}




int main(){

        float weight[20],profit[20],ratio[20],temp,capacity;
        int n;

        scanf("%d",&n);

        scanf("%f",&capacity);

        for(int i=0;i<n;i++){
            scanf("%f %f",&weight[i],&profit[i]);
        }

        for(int i=0;i<n;i++){
            ratio[i] = profit[i] / weight[i];
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                if(ratio[i] < ratio[j]){

                    temp=ratio[j];
                    ratio[j] =ratio[i];
                    ratio[i] = temp;

                    temp=weight[j];
                    weight[j] =weight[i];
                    weight[i] = temp;

                    temp=profit[j];
                    profit[j] =profit[i];
                    profit[i] = temp;

                }
            }
        }

        float maxProfit = knapsack(n,weight,profit,capacity);

        printf("%f",maxProfit);

    return 0;
}