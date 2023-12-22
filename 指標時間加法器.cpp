#include<stdio.h>
void timeAdd(int * hour1, int * minute1, int * second1, int hour2, int minute2, int second2){
	*hour1+=hour2;
	* minute1+=minute2;
	* second1+=second2;
	if(* second1>=60){
	* minute1 += * second1/60;
		* second1=* second1%60;
		
	}
	if(* minute1>=60){
		*hour1 += (* minute1)/60;
		*minute1=(* minute1)%60;
		
	}
}
int main() { 
    int h1, m1, s1, h2, m2, s2;

    h1 = 3; m1 = 18; s1 = 22; h2 = 5; m2 = 22; s2 = 7;
    printf("%d 小時 %d 分鐘 %d 秒鐘 加上 %d 小時 %d 分鐘 %d 秒鐘\n", h1, m1, s1, h2, m2, s2);
    timeAdd(&h1,&m1,&s1,h2,m2,s2);
    printf("\t結果等於 %d 小時 %d 分鐘 %d 秒鐘。\n", h1, m1, s1);

    h1 = 3; m1 = 48; s1 = 32; h2 = 5; m2 = 22; s2 = 57;
    printf("%d 小時 %d 分鐘 %d 秒鐘 加上 %d 小時 %d 分鐘 %d 秒鐘\n", h1, m1, s1, h2, m2, s2);
    timeAdd(&h1,&m1,&s1,h2,m2,s2);
    printf("\t結果等於 %d 小時 %d 分鐘 %d 秒鐘。\n", h1, m1, s1);

    h1 = 3; m1 = 88; s1 = 92; h2 = 5; m2 = 122; s2 = 257;
    printf("%d 小時 %d 分鐘 %d 秒鐘 加上 %d 小時 %d 分鐘 %d 秒鐘\n", h1, m1, s1, h2, m2, s2);
    timeAdd(&h1,&m1,&s1,h2,m2,s2);
    printf("\t結果等於 %d 小時 %d 分鐘 %d 秒鐘。\n", h1, m1, s1);

    return 0;
}
