#include<stdio.h>
#include<string.h>
typedef struct { int year, month, day; } DateData;
typedef struct { int seatNo; char name[20]; DateData birthdate; } StudentInfo;

int datecmp(DateData date1, DateData date2) { 
	if (date1.year > date2.year) return 1;
        
    else if (date1.year < date2.year) return -1;
        
    if (date1.month > date2.month)  return 1;
       
    else if (date1.month < date2.month) return -1;

    if (date1.day > date2.day) return 1;
        
    else if (date1.day < date2.day) return -1;
    
    return 0;
 }
int main(){
    int ti, repeatTimes, rpTimes,low,up;
    char *monthName[12] = {"January", "February", "March","April","May","June","July","August","September","October","November","December"};
    printf("How many students? ");
	scanf("%d",&repeatTimes);if (getchar() == '\r') getchar(); // get repeatTimes from keyboard
	StudentInfo student[repeatTimes];
    for (ti = 0; ti < repeatTimes; ti++) {
    	printf("student[%d].seatNo: ",ti);scanf("%d",&student[ti].seatNo);
    	printf("student[%d].name: ",ti);scanf("%s",&student[ti].name);
    	printf("student[%d].birthdate: ",ti);scanf("%d/%d/%d", &student[ti].birthdate.year, &student[ti].birthdate.month, &student[ti].birthdate.day);
	}
	printf("Lower range: ");scanf("%d",&low);
	printf("Upper range: ");scanf("%d",&up);
	int index = low; 

    for (ti = low ;ti <= up; ti++) {
        if (datecmp(student[ti].birthdate, student[index].birthdate) > 0) {
            index = ti; 
        }
    }
	printf("The youngest student from student[%d] to student[%d] is:\n",low,up);
	printf("%s, No. %d, whose birthday is %s %d.",student[index].name,student[index].seatNo,monthName[student[index].birthdate.month - 1],student[index].birthdate.day);
    return 0;
}
