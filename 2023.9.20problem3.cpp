#include<stdio.h>

int main(){
	int testdata, num, limit, common, i;
	printf("How many sets of test data: ");
	scanf("%d", &testdata);
	printf("\n");
	for(i = 1; i <= testdata; i++){
		printf("The first number: ");
		scanf("%d", &num);
		printf("The upper limit: ");
		scanf("%d", &limit);
		printf("Common difference: ");
		scanf("%d", &common);

		int sum = 0; 
		while(num <= limit) {
			sum += num;
			num += common;
		}
		
		printf("The sum of this arithmetic sequence is %d.\n", sum);
		printf("\n");
	}
	
	return 0;
}

