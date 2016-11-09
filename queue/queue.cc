/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file queue.cc
 *
 * 
 *
 * 
 *
 * @author zhanghb zhanghaibo@foxmail.com
 *
 *************************************************************************/
#include "queue.h"

void create_queue(pqueue pq, int maxsize)
{
    if (pq) {
        return ;
    }

    pq = new queue;
    pq->maxsize = maxsize;
}
void traverse_queue(PQUEUE Q);
bool full_queue(PQUEUE Q);
bool empty_queue(PQUEUE Q);
bool enqueue(PQUEUE Q, int val);
bool dequeue(PQUEUE Q, int *val);
