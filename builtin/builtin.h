/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file builtin.h
 *
 * 内建命令定义
 *
 * 
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _BUILTIN_H_
#define _BUILTIN_H_

#define NULL ((char*)0)

typedef int (*main_t)(int argc, char *argv[]);

struct builtin_s
{
  const char *name;         /* Invocation name and as seen under /sbin/ */
  int         priority;     /* Use: SCHED_PRIORITY_DEFAULT */
  int         stacksize;    /* Desired stack size */
  main_t      main;         /* Entry point: main(int argc, char *argv[]) */
};


const struct builtin_s g_builtins[] =
{
/* # include "builtin_list.h" */
    { NULL, 0, 0, 0 },
    { NULL, 0, 0, 0 }
};

const int g_builtin_count = sizeof(g_builtins) / sizeof(g_builtins[0]);


#endif /* _BUILTIN_H_ */



