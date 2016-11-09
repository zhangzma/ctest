/* Copyright (c) 2015 www.bjfz.com. All rights reserved. */
#include <stdio.h>

#define HEAD_BYTE1    0xA3      // Decimal 163
#define HEAD_BYTE2    0x95      // Decimal 149
#define LOG_EVENT_MSG 0x0D

typedef unsigned char uint8_t;

uint8_t head1, head2, msgid;

struct log_Event {
    uint8_t head1, head2, msgid;
    uint8_t id;
};

void print_log_event(const struct log_Event *evt, const char *name);

int main(int argc, char *argv[])
{
    uint8_t id = 0xA5;

    struct log_Event pkt = {
    head1 : HEAD_BYTE1,
    head2 : HEAD_BYTE2,
    id  : id,
    msgid : LOG_EVENT_MSG
    };

    struct log_Event pkt2 = {HEAD_BYTE1, HEAD_BYTE2, LOG_EVENT_MSG, id};

    print_log_event(&pkt, "pkt1");
    print_log_event(&pkt, "pkt2");

    return 0;
}

void print_log_event(const struct log_Event *pkt, const char *name)
{
    if (name) {
        printf("Log %s: \n", name);
    }
    printf("h1=%0X, h2=%02X, msg=%02X, id=%02X\n",
           pkt->head1, pkt->head2,
           pkt->msgid, pkt->id);
}

