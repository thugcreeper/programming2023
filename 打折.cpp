#include<stdio.h> 
int main(){
	int data,i,price,age,gender;
	printf("How many sets of test data: ");			scanf("%d",&data);
	for(i = 0;i<data;i++){
		printf("\n");
		printf("Original Price: ");					scanf("%d",&price);
		printf("Age: ");							scanf("%d",&age);
		printf("Gender (0=female, 1=male): ");		scanf("%d",&gender);
		if(age<12)
			price = price*7/10;
		if(age>=65)
			price = price*8/10;
		if(gender == 0)
			price = price*9/10;
		printf("Real price is %d.\n",price);}
	return 0;}
	
/*
10% off for female people (女性九折)
20% off for aged people (age >= 65) (老人八折)
30% off for children (age < 12) (兒童七折)
One can have several discounts at a time. */
