/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file mode_report.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _MODE_REPORT_H_
#define _MODE_REPORT_H_

#include "serial_manager.h"
#include <stdio.h>

typedef unsigned char uint8_t;
// typedef unsigned long uint32_t;


// Auto Pilot Modes enumeration
enum control_mode_t {
    STABILIZE =     0,  // manual airframe angle with manual throttle
    ACRO =          1,  // manual body-frame angular rate with manual throttle
    ALT_HOLD =      2,  // manual airframe angle with automatic throttle
    AUTO =          3,  // fully automatic waypoint control using mission commands
    GUIDED =        4,  // fully automatic fly to coordinate or fly at velocity/direction using GCS immediate commands
    LOITER =        5,  // automatic horizontal acceleration with automatic throttle
    RTL =           6,  // automatic return to launching point
    CIRCLE =        7,  // automatic circular flight with automatic throttle
    LAND =          9,  // automatic landing with horizontal position control
    OF_LOITER =    10,  // deprecated
    DRIFT =        11,  // semi-automous position, yaw and throttle control
    SPORT =        13,  // manual earth-frame angular rate control with manual throttle
    FLIP =         14,  // automatically flip the vehicle on the roll axis
    AUTOTUNE =     15,  // automatically tune the vehicle's roll and pitch gains
    POSHOLD =      16,  // automatic position hold with manual override, with automatic throttle
    BRAKE =        17,   // full-brake using inertial/GPS system, no pilot input
    MODE_MAX
};


enum mode_reason_t {
    MODE_REASON_UNKNOWN = 0,
    MODE_REASON_TX_COMMAND,
    MODE_REASON_GCS_COMMAND,
    MODE_REASON_RADIO_FAILSAFE,
    MODE_REASON_BATTERY_FAILSAFE,
    MODE_REASON_GCS_FAILSAFE,
    MODE_REASON_EKF_FAILSAFE,
    MODE_REASON_GPS_GLITCH,
    MODE_REASON_MISSION_END,
    MODE_REASON_THROTTLE_LAND_ESCAPE,
    MODE_REASON_FENCE_BREACH,
    MODE_REASON_TERRAIN_FAILSAFE,
    MODE_REASON_BRAKE_TIMEOUT,
    REASON_MAX
};



class AC_ModeReport
{
public:
    AC_ModeReport();
    virtual ~AC_ModeReport();

    // void init(const AP_SerialManager& serial_manager);
    bool report(uint8_t old, uint8_t curr, uint8_t reason = -1);

private:
    // AP_HAL::UARTDriver *_port;        
    bool               _initialised; // 串口初始化成功标志
    bool               _report_enabled;

    static const char* modes[MODE_MAX];
    static const char* reasons[REASON_MAX];
};

#endif /* _MODE_REPORT_H_ */

