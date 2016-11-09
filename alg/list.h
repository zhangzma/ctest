//
#ifndef _LIST_H_
#define _LIST_H_

#include "eva_debug.h"


typedef int ElemType;
typedef int status;
const int MaxSize = 100;

/**
 * 动态顺序表
 */
typedef struct {
    ElemType *elem;
    int length;
    int listSize;
} Sqlist;

void init_sqlist(Sqlist *L);
void insert_element(ElemType list[], int &n, int i, ElemType ele);
status print_sqlist_info(Sqlist *L);





#endif /* _LIST_H_ */
