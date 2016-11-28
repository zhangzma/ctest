/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file cq.h
 *
 * （单向）循环队列实现
 *
 *
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _CQ_H_
#define _CQ_H_

typedef unsigned short uint16_t;
typedef uint16_t       size_t;
typedef char           T;


struct ring_buffer_s
{
public:
    ring_buffer_s(size_t size);
    virtual ~ring_buffer_s();
    bool read()
    
    bool push(T val);
    bool pop(T &val);
    
    
public:
    size_t _read_index;
    size_t _write_index;
    size_t _size;
    T*     _data;
};




#endif /* _CQ_H_ */






