#include "Solution.h"


int Year2Days(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return 366;
    }
    return 365;
}

int Month2Days(int year, int month)
{
    const int m2d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && Year2Days(year) == 366) {
        return 29;
    }
    return m2d[month];
}

void IncDay(char * date)
{
    char year[5], month[3], day[3];
    int y, m, d;
    strncpy(year, date, 4);
    year[4] = '\0';
    strncpy(month, date + 5, 2);
    month[2] = '\0';
    strncpy(day, date + 8, 2);
    day[2] = '\0';
    sscanf(year, "%d", &y);
    sscanf(month, "%d", &m);
    sscanf(day, "%d", &d);
    int thisMonth = Month2Days(y, m);
    d++;
    if (d > thisMonth) {
        d = 1;
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }
    sprintf(year, "%d", y);
    sprintf(month, "%02d", m);
    sprintf(day, "%02d", d);
    strncpy(date, year, 4);
    strncpy(date + 5, month, 2);
    strncpy(date + 8, day, 2);
}

int DaysBetweenDatesOrderly(char * date1, char *date2)
{
    int cnt = 0;
    while (strcmp(date1, date2) != 0) {
        IncDay(date1);
        // printf("%s\n", date1);
        cnt++;
    }
    return cnt;
}

int daysBetweenDates(char * date1, char * date2)
{
    if (strcmp(date1, date2) < 0) {
        return DaysBetweenDatesOrderly(date1, date2);
    }
    return DaysBetweenDatesOrderly(date2, date1);
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/number-of-days-between-two-dates/solution/1360cyu-yan-by-yewenhao-xl6j/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。