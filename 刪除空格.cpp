#include<stdio.h> 
#include<string.h>
void delSpace(char str[]){
	char *p,*q;
	q=str+strlen(str)-1;//q point to the last element
	while(*q == ' '){//刪除後方空格 
		*q ='\0';
		q--;
	}
	p=str;//move p q to beginning of the input string.
	q=str;
	while(*q == ' '){	
		q++;
	}
	
	while(*q !=  '\0'){
		*p = *q;//Copy characters pointed by q to the elements pointed by p
		if(*p == ' '){//If the copied character (pointed by p) is a space mark, move q to a non-space character
			while(*q==' ')
			q++;
		}
		else{
			q++;//move only one step		
		}	
		p++;
	}
	*p ='\0';
}
int main() {
    char str1[] = "Test    string    1";
    char str2[] = "   Test string    2   ";
    char str3[] = "    ";
    printf("Before:\t[%s]\n\t[%s]\n\t[%s]\n", str1, str2, str3);

    // Call delSpace() to delete space in str1, str2, and str3 here by yourself
	delSpace(str1);
	delSpace(str2);
	delSpace(str3);
    printf("\nAfter:\t[%s]\n\t[%s]\n\t[%s]\n", str1, str2, str3);
    return 0;
}


