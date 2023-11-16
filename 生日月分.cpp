#include<stdio.h>

int main() {
    int data, year, mon, date, i;

    printf("How many students: ");
    scanf("%d", &data);

    char *monthName[12] = {"January", "February", "March","April","May","June","July","August","September","October","November","December"};
    int count[12] = {0};

    printf("Please input their birthdates (year/month/day).\n");
    
    for (int repeat = 0; repeat < data; repeat++) {//declare repeat in loop
        scanf("%d/%d/%d", &year, &mon, &date);

        if (mon >= 1 && mon <= 12) {
            count[mon - 1]++;
        }
    }

    for (i = 0; i < 12; i++) {
        printf("%d people were born in %s.\n", count[i], monthName[i]);
    }

    return 0;
}

