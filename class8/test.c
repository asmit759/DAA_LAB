#include <stdio.h>

void knapsack (float profit[],float weight[],float capacity){
	
	float totalprofit =0;
float u=capacity;
int i;
	
float ans[20];
for( i=0;i<u;i++){
	ans[i]=0.0;
}

for( i=0;i<u;i++){
	if(weight[i]>u)
	break;


	totalprofit += profit[i];
	u-=weight[i];
	ans[i]=1.0;
}

if(i<u){

	ans[i]=u/weight[i];
	totalprofit+=profit[i]*ans[i];
}
	

printf("%f",totalprofit);

for(int i=0;i<u;i++){
	printf("%f",ans[i]);
}

}

int swap(int a,int b){

    float temp = a;
    a=b;
    b=temp;
}



int main(){

float profit[20],weight[20],ratio[20],temp;

float capacity;

scanf("%f",&capacity);

for(int i=0;i<capacity;i++){
	scanf("%f",&weight[i]);
scanf("%f",&profit[i]);

ratio[i] = profit[i]/ratio[i];
}



for(int i=0;i<capacity;i++){

	for(int j=i+1;j<capacity;j++){
		if(ratio[j]>ratio[i]){
		swap(ratio[j],ratio[i]);
swap(profit[j],profit[i]);
swap(weight[j],weight[i]);




	}

    
}

}

knapsack(profit,weight,capacity);


return 0;

}