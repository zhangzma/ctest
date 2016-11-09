/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 * parse测试主文件
 *
 * 
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#include "ptl_lidar.h"
#include <iostream>
#include <string.h>


int main(int argc, char *argv[])
{
    uint16_t len     = 13;
    uint8_t buffer[] = {0x00, 0x00, 0x59, 0x59, 0x27, 0x00, 0x8B, 0x00, 0xCC, 0x06, 0x64, 0x4A, 0xE4};

    ptl_flags _flags;
    _flags.buf = buffer;
    _flags.len = len;

    IPtl *ptl = new LidarPtl(_flags);

    for (uint8_t i=0; i<3; i++) {
        ptl->ptl_recv();    
    }
    
    return 0;
}

