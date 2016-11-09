/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file ptl.c
 *
 * 规约解析文件定义
 *
 * 激光雷达规约解析
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _PTL_C_
#include "ptl.h"
#include <string.h>
#include <stdio.h>


void IPtl::ptl_recv()
{
    switch (_status) {
    case NO_SYNC:
        check_frame_header();
        break;
    case SYNC:
        sync_frame_length();
        break;
    case RECV_LEN:
        parse_frame();
        break;
    default:
        _status = NO_SYNC;
        break;
    }        
}

void IPtl::ptl_send()
{
    print_ptl();
}

void IPtl::print_ptl()
{
    print_hex(_flags.buf, _flags.len);
}


IPtl::IPtl(ptl_flags &flags)
    : _flags(flags)
{

}

IPtl::~IPtl()
{

}

void IPtl::delete_no_use_data(uint8_t *buf, uint16_t &len, uint16_t count)
{
    if (count == 0 || count > len) {
        return ;
    }

    len -= count;
    if (len != 0) {
        memcpy(buf, buf+count, len);
    }    
}

uint8_t IPtl::check_sum(uint8_t *buf, uint16_t len)
{
    uint8_t cs = 0x00;
    for (uint16_t i = 0; i < len; i++) {
        cs += buf[i];
    }

    return cs;
}

void IPtl::print_hex(uint8_t *buf, uint16_t len)
{
    for (uint16_t i = 0; i<len; i++) {
        printf("%02X ", buf[i]);
    }
    printf("\n");
}

