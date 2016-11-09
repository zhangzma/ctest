/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file ptl_lidar.h
 *
 * 激光雷达规约解析
 *
 * 
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _PTL_LIDAR_H_
#define _PTL_LIDAR_H_

#include "ptl.h"

typedef struct _frame_header_s
{
    uint8_t _leader1;
    uint8_t _leader2;
}frame_header_s, *phdr;

class LidarPtl : public IPtl
{
public:
    LidarPtl(ptl_flags &flags);
    virtual ~LidarPtl();

protected:
    virtual void check_frame_header();
    virtual void sync_frame_length();
    virtual void parse_frame();
};

#endif /* _PTL_LIDAR_H_ */




