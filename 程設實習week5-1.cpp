#include<stdio.h>
#include<math.h>

int main(){
	int k=1;
	double mistake,x,sum=0;
	double term; 
	printf("請輸入 x：");				scanf("%lf",&x);
	printf("請輸入容許\誤差值：");		scanf("%lf",&mistake);
	term = x/1;
	sum += term;
	while(term >= mistake){
			term =(term*x*x) /((k+1)*(k+2));
			
			if(k%4 == 1){
				sum -= term;
			}
				
			else{
				sum += term;
			}
			k += 2;
			
	}
	printf("sin(%f) ~= %.20f\n",x,sum);
	printf("sin(%f) == %.20f\n",x,sin(x));
	
	return 0;
} 
