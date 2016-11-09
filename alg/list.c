// list.c
#include "list.h"

void init_sqlist(Sqlist *l)
{
    l->elem = (int*)malloc(sizeof(ElemType)*MaxSize);
    if (l->elem) {
        warnx("Memory error: malloc fail.");
        exit(-1);
    }

    l->length = 0;
    l->listSize = MaxSize;
}

/**
 * Insert ele to the list.
 * @param list -- the list
 * @param n -- the list length
 * @param i -- pos
 * @param ele -- element
 */
void insert_element(ElemType list[], int &n, int i, ElemType ele)
{
    if (n > MaxSize || i < 1 || i > n+1) {
        warnx("Insert error: illegal position.");
        exit(-1);
    }
    
    for (int t=n; t>=i; t--) {
        list[t] = list[t-1];
    }
    list[i] = ele;
    n++;
}



