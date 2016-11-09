/* c11.c */

#include <stdio.h>

int count_rabbit(int month);

int main(int argc, char *argv[])
{
    int m;
    for (m=1; m<20; m++) {
        printf("%d month, %d rabbits.\n", m, count_rabbit(m));
    }

    return 0;
}

int count_rabbit(int month)
{
    if (month==1 || month==2) {
        return 1;        
    }
    
    return count_rabbit(month-1) + count_rabbit(month-2);
}

