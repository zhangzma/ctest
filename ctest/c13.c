/**
 * c13.c
 * Copyright (c) 2015 www.bjfz.com. All rights reserved.
 */

#include <stdio.h>
#include <stdbool.h>


bool is_narcissistic_number(int n);
int  x3(int x);

int main(int argc, char *argv[])
{
    for (int i=100; i<2000; i++) {
        if (is_narcissistic_number(i)) {
            printf("%d ", i);
        }
    }

    /* bool f = is_narcissistic_number(153); */
    /* printf("%s", f ? "Yes": "No"); */

    return 0;
}

bool is_narcissistic_number(int old)
{
    int n = old;

    int tmp, sum = 0;

    while (n != 0) {
        tmp = n % 10;
        n /= 10;
        sum += x3(tmp);
    }
    
    #if 0
    if (n<100 && n>999) {
        return false;
    }

    int a[3];
    int sum = 0;
    for (int i=0; i<3; i++) {
        a[i] = n % 10;
        n = n / 10;
        sum += x3(a[i]);
        /* printf("%d ", a[i]); */
    }
    /* printf("sum = %d", sum); */
    #endif

    return (old == sum);
}

int x3(int x)
{
    return x*x*x;
}

    
