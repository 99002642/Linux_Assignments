/* Write a program to print current time periodically (Hint:- alarm, time, ctime) */

/*         
    tm_mday   The day of the month, in the range 1 to 31.

    tm_mon    The number of months since January, in the range 0 to 11.(jan-0 feb-1)

    tm_year   The number of years after 1900.

*/

#include <stdio.h>
#include <time.h>

int main()
{
    time_t t,value=1;
    struct tm* sys_time;

    t=time(NULL);
    sys_time=localtime(&t);
    
    printf(" %02d hr:%02d min:%02d sec\n ",sys_time->tm_hour,sys_time->tm_min,sys_time->tm_sec);

    printf("The %02dth day of %02dth month of the year:%02d\n",sys_time->tm_mday,sys_time->tm_mon,(sys_time->tm_year)+1900);
    
    return 0;
}

