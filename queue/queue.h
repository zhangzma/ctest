/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file queue.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Author zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct _queue
{
    int *pBase;
    int  front;                 //指向队列第一个元素
    int  rear;                  //指向队列最后一个元素的下一个元素
    int  maxsize;               //循环队列的最大存储空间
}queue, *pqueue;

void create_queue(PQUEUE Q,int maxsize);
void traverse_queue(PQUEUE Q);
bool full_queue(PQUEUE Q);
bool empty_queue(PQUEUE Q);
bool enqueue(PQUEUE Q, int val);
bool dequeue(PQUEUE Q, int *val);

#endif /* _QUEUE_H_ */



