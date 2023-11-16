#include <stdio.h>

int main() {
    int a[100];
    int amount, num; 
	while(true){
		printf("How many numbers: ");
    	scanf("%d", &amount);
    	if(amount>0)
   		break;
	}
    
    printf("Please input numbers: ");
    for (int i = 0; i < amount; ++i) {
        scanf("%d", &a[i]);
    }
    printf("\n");

    while (true) {  
        printf("Which index do you want to see (-1 to exit): ");
        scanf("%d", &num);

        if (num == -1) {
        	printf("Over!");
            break;  
        }

        else{
            printf("a[%d] is %d\n", num, a[num]);
            printf("\n");
        } 
		
    }

    return 0;
}

