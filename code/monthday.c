#include <stdio.h>
static int daytab[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31}, {0,31,29,31,30,31,30,31,31,30,31,30,31}};

void monthday(int year, int yearday, int *pmonth, int *pday)
{
  int leap, i;
  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  for(i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}

int main()
{
  int month, day;
  monthday(2015, 60, &month, &day);
  printf("month: %d, day: %d.\n", month, day);
}
