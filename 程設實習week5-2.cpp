#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int dice1,dice2,repeat=0,i;
	int occur[13]={0};
    srand((unsigned int)time(NULL));
    while(repeat<6000){
    int dice1 = rand() % 6 +1; // get a random number between 0 ~ (N-1)
    int dice2 = rand() % 6 +1;
    	for(i=2;i<13;i++){
    		if(dice1 + dice2 == i)
    		occur[i]++; 
		}
		repeat++;
		
    }
    	for(i=2;i<13;i++){
    		printf("%d出現過%d次\n",i,occur[i]);
    	}
    return 0;
}
