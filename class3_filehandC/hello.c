#include<stdio.h>

void main(){
    FILE* fptr;
    fptr=fopen("greet.txt","r");

    if(fptr != NULL){
        printf("in good condition \n");
    }else{
        printf("error");
    }

    char arr[100];

    while(fgets(arr,100,fptr)){
        printf("%s",arr);
    }

    // FILE *ftrT;
    // fptrT=fopen("greetTwo.txt","r");
    int a;
    printf("Enter a number: ");
    scanf("%d", &a); // taking input from console

    fprintf(fptr, "%d\n", a);
    
}