#include<stdio.h>

int main(){
    int input_number;
    printf("Input a number: ");
    scanf("%d",&input_number);
    if(input_number % 5 == 0){
        printf("%d is a multiple of 5.\n",input_number);
    }
    if(input_number % 7 == 0){
        printf("%d is a multiple of 7.\n",input_number);
    }
    return 0;
}