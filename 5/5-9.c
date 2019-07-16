// Упражнение 5.9. Перепишите программы day_of_year и month_day, используя вместо индексов указатели.

#include <stdio.h>

void month_day(int, int, int *, int *);
int day_of_year(int, int, int);
int is_leap(int);


int checkdate(int, int, int);
int check_yearday(int, int);

static int daytab[][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// --- main -----------------------------------------
int main() {

    int y, m, d, num;
    // printf("Input a date: year-month-day\n");
    // scanf("%d-%d-%d", &y, &m, &d);
    // if (! checkdate(y, m, d)) {
    //     printf("Incorrect date!");
    //     return 1;
    // }

    // printf("The day of the year # %d\n", day_of_year(y, m, d));

    printf("Input a year and a day's number:\n");
    scanf("%d %d", &y, &num);
    if (! check_yearday(y, num)) {
        printf("Incorrect yearday!");
        return 1;
    }    
    month_day(y, num, &m, &d);   
    printf("The date: %d-%d-%d\n", y,m,d);

    return 0;
}


int is_leap(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 1000 == 0;
}


int checkdate(int year, int month, int day) {
    if (month < 1 || month > 12)
        return 0;
    if (day < 1 || day > daytab[is_leap(year)][month]) 
        return 0;
    return 1;
}


int check_yearday(int year, int yearday) {
    if (yearday < 1 || yearday > (is_leap(year) ? 366 : 365))
        return 0 ;
    return 1;
}


int day_of_year(int year, int month, int day) {
    int leap_index = is_leap(year);
    for (int i = 1; i < month; ++i)
        day += *(*(daytab + leap_index) + i);
    return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap_index = is_leap(year);
    *pmonth = 1;
    for (; yearday > 0; *pmonth += 1)
        yearday -= *(*(daytab + leap_index) + *pmonth);
    *pmonth -= 1;
    *pday = yearday + *(*(daytab + leap_index) + *pmonth);
}                      