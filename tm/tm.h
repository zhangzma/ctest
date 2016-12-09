/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file tm.h
 *
 * 
 *
 * Detail
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _TM_H_
#define _TM_H_
#include <iostream>

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;
typedef signed char    int8_t;
typedef signed short   int16_t;
typedef signed int     int32_t;

typedef struct _tm_t
{
    uint16_t year;
    uint8_t  month;
    uint8_t  day;
    uint8_t  hour;
    uint8_t  min;
    uint8_t  sec;
}tm_t, *ptm_t;

void print();
extern void print_info();
std::ostream& operator<<(std::ostream& s, const tm_t& tm);

#endif /* _TM_H_ */



