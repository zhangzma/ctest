/*
 * strftime test.
 */

#include <stdio.h>
#include <time.h>


int main(int argc, char *argv[])
{
    char str_time[16];
    struct tm tt;

    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    int ret = strftime(str_time, 16, "%Y-%m-%d %H:%M:%S", timeinfo);
    if (ret == 0) {
        puts(str_time);
    }
    else {
        
    }

    printf("ret is %d\n", ret);

    return 0;
}

