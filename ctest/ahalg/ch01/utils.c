/*
 * copyright (c) www.eva-tec.cn
 * 工具集实现
 * FileName: utils.c
 */
#include "utils.h"

void print_array(int *val, int count)
{
    printf("The Array is: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", val[i]);
    }
}
