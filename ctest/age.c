/**
 * Get the age.
 * age.c
 */

#include <stdio.h>
#include <stdbool.h>

#define NUM 10

bool g_bNum[NUM] = {false};

int  get_age();
void init_array();
void parse(int num);
int  my_power(int b, int p);
bool is_right_age(int age);

int main(int argc, char *argv[])
{
    printf("The Age is %d.\n", get_age());
    return 0;
}

int get_age()
{
    int age = 0;
    for (int i = 1; i<100; i++) {
        init_array();
        parse(my_power(i, 3));
        parse(my_power(i, 4));
        if (is_right_age(i)) {
            age = i;
            break;
        }
        // printf("x3=%d, x4=%d\n", my_power(i,3), my_power(i, 4));
    }

    return age;
}

void init_array()
{
    for (int i = 0; i < NUM; i++) {
        g_bNum[i] = false;
    }
}

void parse(int num)
{
    int i;
    while (num) {
        i = num % 10;
        num /= 10;
        g_bNum[i] = true;
    }
}

int my_power(int b, int p)
{
    if (p == 0) {
        return 1;
    }
    else if (p == 1) {
        return b;
    }
    else {
        return b * my_power(b, p-1);
    }
}

bool is_right_age(int age)
{
    bool b_right = true;

    for (int i = 0; i < NUM; i++) {
        if (!g_bNum[i]) {
            b_right = false;
            break;
        }
    }

    return b_right;
}

