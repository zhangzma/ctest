
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;


void delete_no_use_data(uint8_t *buf, uint16_t count, uint16_t &_length)
{
    uint16_t len = _length - count;
    memcpy(buf, buf+count, len);
    _length = len;
}

int main(int argc, char *argv[])
{
    uint16_t len = 10;
    uint8_t buffer[10];

    for (uint16_t i=0; i<len; i++) {
        buffer[i] = i + '0';
    }

    delete_no_use_data(buffer, 4, len);

    for (uint16_t i=0; i<len; i++) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
