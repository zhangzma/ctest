/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file scheduler.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#ifdef _SCHEDULER_C_
#   define SCH_EXTERN
#else
#   define SCH_EXTERN extern
#endif /* _SCHEDULER_C_ */

#define TASK_NUM 30

typedef void(*ptask_t)(void* pdata);
typedef uint32_t task_id_t;

typedef struct _s_tcb{
    ptask_t  _ptask;            // 任务指针
    uint32_t _period;           // 任务间隔
    uint32_t _delay;            // 执行偏移
}tcb_t;


void     sch_init();
uint32_t sch_add_task(ptask_t ptask, uint32_t period, uint32_t delay);
viod     sch_del_task(uint32_t pid);
void     sch_run();

SCH_EXTERN tcb_t task_tbl[TASK_NUM];

#endif /* _SCHEDULER_H_ */

