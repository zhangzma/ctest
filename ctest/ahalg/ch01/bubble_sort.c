/*
 * copyright (c) www.eva-tec.cn
 *
 * “轻清者上浮为天，重浊者下沉为地。”
 * 故而冒泡排序或许有两种算法，即上浮排序和下沉排序，其两者互为倒影。
 * bubble_sort.c
 */
#include <stdio.h>
#include "utils.h"


void bubble_sort_asc(int *vals, int count);
void bubble_sort_des(int *vals, int count);


int main(int argc, char *argv[])
{
    const int NUM_MAX = 100;
    int vals[NUM_MAX];
    int num = -1;
    printf("Please input the num of scores: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &vals[i]);
    }

    bubble_sort_asc(vals, num);

    for (int i = 0; i < num; i++) {
        printf("%d ", vals[i]);
    }

    return 0;
}

/*
 * bubble sort, asc
 */
void bubble_sort_asc(int *vals, int count)
{
    for (int i = 0; i < count; i++) {
        printf("\n%dth Round ====================\n", i);
        for (int j = count - 1; j > i; j--) {
            if (vals[j-1] > vals[j]) {
                int tmp   = vals[j-1];
                vals[j-1] = vals[j];
                vals[j]   = tmp;
            }
            print_array(vals, count);
        }
    }
}

void print_array(int *vals, int count)
{
    printf("The Arrays: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", vals[i]);
    }
    printf("\n");
}
