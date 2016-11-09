// main.cpp
#include "ringbuffer.h"

int main(int argc, char *argv[])
{
    RingBuffer buf1(100, 50);

    buf1.print_info();

    RingBuffer buf2(buf1);
    buf2.print_info();

    return 0;
}

