#include <stdio.h>

int main() {
    int a[100];
    int amount, num,count=0,i,multi; 
	while(true){
		printf("How many numbers: ");
    	scanf("%d", &amount);
    	if(amount>0)
   		break;
	}
    
    printf("Please input numbers: ");
    for (i = 0; i < amount; ++i) {
        scanf("%d", &a[i]);
    }

   printf("Check which number's multiples? ");		scanf("%d",&multi);
   for(i = 0;i<amount;i++){
   	if(a[i]%multi == 0){
	   printf("a[%d] = %d\n",i,a[i]);
	   count++;
	   }
    	
   		
   }
   printf("Found %d multiple(s).",count);
    return 0;
}
