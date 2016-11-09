/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file AC_Polygon.h
 *
 * 多边形地理围栏
 *
 * 多边形地理围栏定义，扩展圆形地理围栏。用以型式试验测试。
 *
 * @author zhanghb zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _AC_POLYGON_H_
#define _AC_POLYGON_H_

#include "AC_Point.h"
#define POINT_MAX 100

class AC_Polygon
{
public:
    AC_Polygon();
    AC_Polygon(const char *fence_file);
    virtual ~AC_Polygon();
    bool is_nfz() {
        return _nfz;
    }
    void set_nfz(bool nfz) {
        _nfz = nfz;
    }
    void add_point(const AC_Point &point);
    void set_point(uint16_t idx, const AC_Point &point);
    bool touch_side(const AC_Point &point);

    bool read_fence_file(const char *fence_file);
    bool save_to_file(bool force);
    char* get_fence_file_name();

    uint16_t points_count() const;
    void clear_all();

    enum e_relative{
        INSIDE,
        ONSIDE,
        OUTSIDE
    };

protected:
    e_relative ray_check(const AC_Point &point);

private:
    uint16_t _id;
    AC_Point _points[POINT_MAX]; // 多边形围栏顶点
    uint16_t _count;             // 顶点数目
    bool     _nfz;               // 禁飞区标志
};

#endif /* _AC_POLYGON_H_ */

