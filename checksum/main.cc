#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>

/* 帧头定义 */
typedef struct _ptl_header
{
    uint8_t h1;
    uint8_t type;
    uint8_t len;
    uint8_t h2;
}ptl_header;

typedef unsigned char uint8_t;

void printf_buffer(uint8_t *buf, uint8_t len)
{
    for (int i=0; i<len; i++) {
        printf("%02X ", buf[i]);
    }

    printf("\n");
}


uint8_t check_sum(uint8_t *buf, uint8_t len)
{
    uint8_t sum;
    while (len--) {
        sum += *buf++;
    }

    return sum;
}

void send_ptl(uint16_t dist[], uint8_t len)
{
    uint8_t i;
    uint8_t *pbuf = sbuf + 4;

    memset(sbuf, SLEN, '\0');
    
    ptl_header *_header = (ptl_header*)sbuf;
    _header->h1   = 0xFA;
    _header->type = 0x10;
    _header->len  = 0x08;
    _header->h2   = 0xFA;
    
    for (i=0; i<len; i++) {
        *pbuf++ = dist[i] >> 8;
        *pbuf++ = dist[i] & 0xFF;
    }
    
    *pbuf++ = check_sum(sbuf+4, 8);
    *pbuf++ = 0x16;    
}

int main(int argc, char *argv[])
{
    uint16_t dist[4] = {800, 1100, -1, -1};
    send_ptl(dist, 4);
    printf_buffer(sbuf, 14);
    return 0;
}

