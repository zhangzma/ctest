/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.c
 *
 * 宏定义扩展研究
 *
 * 概述：
 *    1. APM参数定义宏研究
 *    2. XXX_EXTERN宏定义扩展
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "apm_param_marco.h"


int main(int argc, char *argv[])
{

#if 0 
    const struct GroupInfo var_info[] PROGMEM = {
    // @Param: TOTAL
    // @DisplayName: Total mission commands
    // @Description: The number of mission mission items that has been loaded by the ground station. Do not change this manually.
    // @Range: 0 32766
    // @Increment: 1
    // @User: Advanced
    AP_GROUPINFO("TOTAL",  0, AP_Mission, _cmd_total, 0),

    // @Param: RESTART
    // @DisplayName: Mission Restart when entering Auto mode
    // @Description: Controls mission starting point when entering Auto mode (either restart from beginning of mission or resume from last command run)
    // @Values: 0:Resume Mission, 1:Restart Mission
    AP_GROUPINFO("RESTART",  1, AP_Mission, _restart, AP_MISSION_RESTART_DEFAULT),
    // @Param: RAW_SENS
    // @DisplayName: Raw sensor stream rate
    // @Description: Stream rate of RAW_IMU, SCALED_IMU2, SCALED_PRESSURE, and SENSOR_OFFSETS to ground station
    // @Units: Hz
    // @Range: 0 10
    // @Increment: 1
    // @User: Advanced
    AP_GROUPINFO("RAW_SENS", 0, GCS_MAVLINK, streamRates[0],  0),

    // @Param: EXT_STAT
    // @DisplayName: Extended status stream rate to ground station
    // @Description: Stream rate of SYS_STATUS, MEMINFO, MISSION_CURRENT, GPS_RAW_INT, NAV_CONTROLLER_OUTPUT, and LIMITS_STATUS to ground station
    // @Units: Hz
    // @Range: 0 10
    // @Increment: 1
    // @User: Advanced
    AP_GROUPINFO("EXT_STAT", 1, GCS_MAVLINK, streamRates[1],  0)
    }
#endif
    
    return 0;
}

