/* weak.c */
#include <stdio.h>

extern void foo() __attribute__((weak));
/* extern void foo(); /\* __attribute__((weak)); *\/ */

int main(int argc, char *argv[])
{
    if (foo) {
        foo();
    }

    return 0;
}
