/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file AC_Point.h
 *
 * 多边形顶点
 *
 * 端点相关操作，详见AC_Point.h
 *
 * @author zhanghb zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _AC_POINT_H_
#define _AC_POINT_H_

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
/* typedef signed int    int32_t; */
/* typedef signed int    int32_t; */
typedef signed int    int32_t;

struct Location_Option_Flags {
    uint8_t relative_alt : 1;           // 1 if altitude is relateive to home
    uint8_t unused1      : 1;           // unused flag (defined so that loiter_ccw uses the correct bit)
    uint8_t loiter_ccw   : 1;           // 0 if clockwise, 1 if counter clockwise
    uint8_t terrain_alt  : 1;           // this altitude is above terrain
};

struct Location {
    union {
        Location_Option_Flags flags;                    ///< options bitmask (1<<0 = relative altitude)
        uint8_t options;                                /// allows writing all flags to eeprom as one byte
    };
    int32_t alt:24;                                     ///< param 2 - Altitude in centimeters (meters * 100)
    int32_t lat;                                        ///< param 3 - Latitude * 10**7
    int32_t lng;                                        ///< param 4 - Longitude * 10**7
};


class AC_Point
{
public:
    AC_Point();
    AC_Point(double x, double y);
    AC_Point(const Location &loc);
    virtual ~AC_Point();

friend class AC_Polygon;

private:
    double _x;
    double _y;
};

#endif /* _AC_POINT_H_ */

