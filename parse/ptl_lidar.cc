/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file ptl_lidar.cc
 *
 * 激光雷达规约解析
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _PTL_LIDAR_C_
#include "ptl_lidar.h"
#include <iostream>

const uint8_t HEADER_LEN = 0x02;


LidarPtl::LidarPtl(ptl_flags &flags)
    : IPtl(flags)
{

}

LidarPtl::~LidarPtl()
{

}


void LidarPtl::check_frame_header()
{
    bool ok = false;
    if (_flags.len < HEADER_LEN) {
        // return ok;
        return ;
    }

    uint16_t i = 0;
    for (; i < (_flags.len-HEADER_LEN+1); i++) {
        if (_flags.buf[i] == FRM_HEADER && _flags.buf[i+1] == FRM_HEADER) {
            // memcpy((void*)pheader, _flags.buf+i, 2);
            ok = true;
            _status = SYNC;
            break;
        }
    }

    delete_no_use_data(_flags.buf, _flags.len, i);
    // return ok;
}

void LidarPtl::sync_frame_length()
{
    if (_flags.len >= 11) {
        _status = RECV_LEN;
    }
}

void LidarPtl::parse_frame()
{
    uint8_t *buf = _flags.buf;
    uint8_t  cs  = check_sum(buf, 10);

    if (cs == buf[10]) {
        uint16_t dist     = buf[2] + (buf[3] << 8);
        uint16_t strength = buf[4] + (buf[5] << 8);
        uint16_t angle    = buf[6] + (buf[7] << 8);

        std::cout << "distance = " << dist << "\t"
                  << "strength = " << strength << "\t"
                  << "angle = " << angle/10.0
                  << std::endl;
    }
}



