/* c10.c */

#include <stdio.h>

void print_stairs(int floors);

int main(int argc, char *argv[])
{
    print_stairs(11);
    return 0;
}

void print_stairs(int floors)
{
    char block = 219;

    printf("\1\1");

    for (int f=0; f<=floors; f++) {
        for (int c=0; c<f; c++) {
            printf("%c", block);
        }
        printf("\n");        
    }
}

