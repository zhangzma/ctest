/*
 *
 */
#define DEBUG

#include "list.h"


int main(int argc, char *argv[])
{
    Sqlist list;
    init_sqlist(&list);

    insert_element(list.elem, list.length, 0, 1);
    
    return 0;
}



