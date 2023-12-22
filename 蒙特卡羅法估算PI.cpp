#include<stdio.h>
#include <stdlib.h>
#include<time.h>
int main(){
	srand( time(NULL) );
	int count =0;
	double pi;
  		for(int j=1000;j<=100000000;j*=10){
  			for(int i=0;i<j;i++){
  				double x = (double) rand() / RAND_MAX;
    			double y = (double) rand() / RAND_MAX;
    			if(x*x+y*y<=1)
    			count++;
			  }
			  pi = (count*4/(double)j);
  			printf("After %d points, PI = %lf\n",j,pi);
  			count =0;
		  }		 	
}
