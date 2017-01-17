/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file mode_report.cpp
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _MODE_REPORT_C_
#include "mode_report.h"
#include <stdio.h>

const char *AC_ModeReport::modes[MODE_MAX] = {
    "STABILIZE",
    "ACRO",
    "ALT_HOLD",
    "AUTO",
    "GUIDED",
    "LOITER",
    "RTL",
    "CIRCLE",
    "LAND",
    "OF_LOITER",
    "DRIFT",
    "SPORT",
    "FLIP",
    "AUTOTUNE",
    "POSHOLD",
    "BRAKE"
};


const char *AC_ModeReport::reasons[REASON_MAX] = {
    "MODE_REASON_UNKNOWN",
    "MODE_REASON_TX_COMMAND",
    "MODE_REASON_GCS_COMMAND",
    "MODE_REASON_RADIO_FAILSAFE",
    "MODE_REASON_BATTERY_FAILSAFE",
    "MODE_REASON_GCS_FAILSAFE",
    "MODE_REASON_EKF_FAILSAFE",
    "MODE_REASON_GPS_GLITCH",
    "MODE_REASON_MISSION_END",
    "MODE_REASON_THROTTLE_LAND_ESCAPE",
    "MODE_REASON_FENCE_BREACH",
    "MODE_REASON_TERRAIN_FAILSAFE",
    "MODE_REASON_BRAKE_TIMEOUT"
};

AC_ModeReport::AC_ModeReport()
    : _initialised(true),
      _report_enabled(true)
{

}

AC_ModeReport::~AC_ModeReport()
{
    _initialised    = false;
    _report_enabled = false;
}

/**
 * report()
 *
 * control_mode_t old   -- 切换前模式
 * control_mode_t curr  -- 切换后模式
 * mode_reason_t reason -- 切换原因
 */
bool AC_ModeReport::report(uint8_t old,
                           uint8_t curr,
                           uint8_t reason)
{
    char str[80];
    int len;
    if (_initialised) {
        len = sprintf(str,
                      "Fly mode changed: old mode = %s, current mode = %s.\n",
                      modes[old], modes[curr]);
        printf(str);
        
        if (reason != -1) {
            len = sprintf(str, "Changed reason: %s\n",
                          reasons[reason]);
            printf(str);
        }
    }
}

