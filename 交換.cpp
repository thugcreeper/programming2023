#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void print(int a[],int size){
	printf("{");
	for(int i=0;i<size;i++){
		printf("%d",a[i]);
		if(i<size-1)
		printf(", ");
	}
	printf("}\n");
}
void strangeFunc(int a[], int size);
int main() {
    int a[13] = {65, 0, -5, -22, 9, 231, 43, -7, 11, -65, 0, -18, 65};
    int b[12] = {65, 0, -5, -22, 9, 231, 43, -7, 11, 65, 0, -18};
    int c[12] = {65, 0, 5, 22, 9, 231, 43, 7, 11, 65, 0, 18};
	printf("原先 a[] 為 ");
	print(a,13);
	printf("原先 b[] 為 ");
	print(b,12);
	printf("原先 c[] 為 ");
	print(c,12);
	
	strangeFunc(a,13);
	strangeFunc(b,12);
	strangeFunc(c,12);
	printf("\n後來 a[] 為 ");
    print(a,13);
    printf("後來 b[] 為 ");
	print(b,12);
	printf("後來 c[] 為 ");
	print(c,12);
    return 0;
}
void strangeFunc(int a[], int size){
	int *p,*q;
	p=a;
	q=a+size-1;
	while(p<q){
		if(*p<0&&*q<0){
		swap(p,q);
		p++;
		q--;
	}
		else if(*p>=0)
			p++;
		else if(*q>=0)
			q--;
	}
}
