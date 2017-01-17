/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.c
 *
 * 调度器内核测试程序
 *
 * 概述：
 *    1.简单调度器内核测试
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _MAIN_C_
#include "task.h"
#include <stdio.h>
#define TASK_NUM 5

typedef unsigned int uint32_t;
typedef void(*ptask_t)(void* pdata);

typedef struct _s_tcb{
    ptask_t  _ptask;            // 任务指针
    uint32_t _period;           // 任务间隔=1000/f，其中f为任务频率。
    uint32_t _off;              // 执行偏移
}tcb_t;

bool     run_flag = true;
uint32_t count    = 0;
void update_counter();

int main(int argc, char *argv[])
{
    /* task init. */
    tcb_t task_tbl[TASK_NUM] = {
        {NULL,  1,  0},         /* 1000Hz */
        {NULL,  2,  1},         /* 500Hz */
        {NULL,  4,  3},         /* 250Hz */
        {NULL, 10,  9},         /* 100Hz */
        {task5, 1, 0}           /* 50Hz */
    };
    
    /* while (1) */
    while (run_flag) {
        for (uint32_t i = 0; i < TASK_NUM; i++) {
            tcb_t pcurr = task_tbl[i];
            if (pcurr._ptask != NULL &&
                ((count-pcurr._off) % pcurr._period) == 0) {
                pcurr._ptask(NULL);
            }
        }

        /* system tick update. */
        update_counter();
    }

    return 0;
}

/** 
 * 模拟系统时钟
 */
void update_counter()
{
    static int sys = 0;
    /* printf("system tick update, current is: %d\n", count); */
    /* print system tick. */
    /* printf("."); */
    count++;
    if (count >= 1000) {
        count = 0;
        sys++;
        if (sys == 10) {
            run_flag = false;
        }
    }
}

