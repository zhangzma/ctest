/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file scheduler.c
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _SCHEDULER_C_
#include "scheduler.h"

void sch_init()
{
    for (task_id_t i = 0; i < TASK_NUM; i++) {
        sch_del_task(i);
    }

}

uint32_t sch_add_task(ptask_t ptask, uint32_t period, uint32_t delay)
{
    tcb_t *ptcb = NULL;

    for (task_id_t i = 0; i < TASK_NUM; i++) {
        ptcb = task_tbl[i];
        if (ptcb == NULL) {
            ptcb->_ptask  = ptask;
            ptcb->_period = period;
            ptcb->_delay  = delay;
        }
    }

    return -1;
}

viod sch_del_task(uint32_t pid)
{
    if (pid < TASK_NUM) {
        ptcb->_ptask  = NULL;
        ptcb->_period = 0;
        ptcb->_delay  = 0;
    }    
}

void sch_run()
{
    
}


