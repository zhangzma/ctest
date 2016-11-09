// ringbuffer.cpp
#include "ringbuffer.h"
#include <cstdio>

RingBuffer::RingBuffer(int num_size, int entry_size)
    : _num_size(num_size),
      _item_size(entry_size)
{
}

RingBuffer::~RingBuffer()
{
}

void RingBuffer::print_info()
{
    printf("RingBuffer: num = %d, item=%d\n",
           _num_size, _item_size);
}

