#include <stdio.h>
#include <stdlib.h>

int main(){
    int size,i,j,sets,times=0;
    printf("How many sets of test data: ");			scanf("%d",&sets);
    printf("\n");
    while(times < sets){
    	printf("Size: ");							scanf("%d", &size);
	    if(size%2==1){ 
	      for(i=1; i<=size; i++){  // 筂菌┮Τ︽
	        if(i<(size+1)/2+1){  // 场だ珹い丁︽
	            for(j=1; j<=size; j++){  // 筂菌场だ┮Τ
	                if( (size+1)/2-(i-1)<=j && j<=(size+1)/2+(i-1) ){
	                    printf("$");
	                }else{
	                    printf("+");
	                }
	            }
	        }else{  // 场だ
	            for(j=1; j<=size; j++){  // 筂菌场だ┮Τ
	                if( (size+1)/2-(size-i)<=j && j<=(size+1)/2+(size-i) ){
	                    printf("$");
	                }else{
	                    printf("+");
	                }
	            }
	        }
	        printf("\n");
	    }  
	    }
    printf("\n");

    
    times ++;
}
    return 0;
}
