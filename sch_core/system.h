/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file system.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#ifdef _SYSTEM_C_
#   define SYS_EXTERN
#else
#   define SYS_EXTERN extern
#endif /* _SYSTEM_C_ */

SYS_EXTERN uint32_t sys_count;


void sys_init();
void sys_update_count();

#endif /* _SYSTEM_H_ */



