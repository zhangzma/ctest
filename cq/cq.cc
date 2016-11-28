/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file cq.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _CQ_C_
#include "cq.h"

ring_buffer_s::ring_buffer_s(size_t size)
    : _size(size),
      _read_index(0),
      _write_index(0)
{
    _data = new T(_size);
}

ring_buffer_s::~ring_buffer_s()
{
    delete _data;
}

bool ring_buffer_s::push(T val)
{
    if (_write_index+1 == _read_index) {
        return false;
    } else {
        _data[_write_index++] = val;
        return true;
    }
}

bool ring_buffer_s::pop(T &val)
{
    if (_read_index == _write_index) {
        return false;
    } else {
        val = _data[_read_index];
        _read_index = (_read_index+1) % _size;
        return true;
    }
}




