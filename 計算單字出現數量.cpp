#include <stdio.h>
#include <string.h>

int indexOfList_icmp(char *str, char *list[], int size) {
	for(int i=0;i<size;i++){
		if(stricmp(str,list[i])==0){
			return i;
		}
	}
	return -1;
}

int main() {
    char document[] = "National Taiwan Ocean University was originally established in 1953 as a junior college for the study of maritime science and technology.\nAfter eleven years, in 1964, we became a maritime college which offered bachelor's and master's degrees in various fields of maritime studies. During this period, funds for running the college came from the Taiwan Provincial Government of the Republic of China.\nIn 1979 the national government took over the funding and we became the National Maritime College. After another decade, in 1989, the college grew into a full-fledged university, National Taiwan Ocean University (NTOU).";
    int frequency[100]={}, wTotal = 0,k;
    char *wordlist[100];//100��pointer���Varray 
    char punc[]=",. -()\n", *p;
	p=strtok(document, punc); // first call

	while ( p != NULL ){
	    k=indexOfList_icmp(p,wordlist,wTotal);//wTotal���X�ӷs���� 
	    if(k==-1){
	    	wordlist[wTotal]=p;
			frequency[wTotal]=1;
			wTotal++;
	}
		else{//token occur in worldlist[]
			frequency[k]++;	
		}
	   p=strtok(NULL, punc); // get next token
	   
	}
	
	for(int i=0;i<wTotal;i++)
	printf("%-11s%5d\n",wordlist[i],frequency[i]);//-11��ܾa�����A�M�ᦳ11�檺���ץi�H�L�X,5��ܾa�k��� 
    return 0;
}

