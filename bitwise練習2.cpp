#include<stdio.h>
int main() {
    int rptime,inputnum,pos,count,bit;
    printf("How many sets of test data: ");
    scanf("%d", &rptime);
    for (int i = 0; i < rptime; i++) {
        printf("\nNumber: ");
        scanf("%d", &inputnum);
        printf("Position: ");
        scanf("%d",&pos);
        if ((inputnum & (1 << pos)) !=0)//把1向左移動pos格 
            printf("It is a 1 bit.");
        else
            printf("It is a 0 bit.");
        printf("\n");
    }
    return 0;
}

