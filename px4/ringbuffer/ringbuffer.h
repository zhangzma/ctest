// ringbuffer.h
// 禁止拷贝和赋值构造函数

#ifndef _RINGBUFFER_H_
#define _RINGBUFFER_H_

#define DO_NOT_ALLOW_COPY_AND_SET(CNAME) \
    CNAME(const CNAME &);                \
    CNAME& operator=(const CNAME &);

class RingBuffer
{
public:
    RingBuffer(int num_size, int entry_size);
    virtual ~RingBuffer();

    void print_info();

private:
    int _num_size;
    int _item_size;

private:
    // DO_NOT_ALLOW_COPY_AND_SET(RingBuffer);
};

#endif /* _RINGBUFFER_H_ */


