/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file AC_Polygon.cpp
 *
 * 多边形地理围栏
 *
 * 处理多边形地理围栏信息，增加
 *
 * @author zhanghb zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#include "AC_Polygon.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

using namespace std;

double jabs(double x)
{
    return (x > 0) ? x : -x;
}

bool is_equal(double x, double y)
{
    const double EPSON = 0.00005;
    double delta = jabs(x-y);
    return (delta < EPSON);
}


/**************************************************************************
 **                    Public Function Define
 *************************************************************************/
AC_Polygon::AC_Polygon()
    : _count(0), _nfz(false), _id(0)
{
}


AC_Polygon::AC_Polygon(const char *fence_file)
    : _count(0), _nfz(false), _id(0)
{
    read_fence_file(fence_file);
}

AC_Polygon::~AC_Polygon()
{

}

void AC_Polygon::add_point(const AC_Point &point)
{
    if (_count < POINT_MAX) {
        _points[_count++] = point;
    }
}

void AC_Polygon::set_point(uint16_t idx, const AC_Point &point)
{
    if (_count < idx) {
        _count = idx;
    }

    _points[_count++] = point;
}

/**
 * touch_side()
 *
 * 判断飞控是否碰触或越过禁飞区域。
 *
 * @param point --指定点
 * @return  -- 飞控已经越过禁飞区域。
 */
bool AC_Polygon::touch_side(const AC_Point &point)
{
    e_relative rel = ray_check(point);

    switch (rel) {
    case INSIDE:
        std::cout << "INSIDE." << std::endl;
        break;
    case ONSIDE:
        std::cout << "ONSIDE." << std::endl;
        break;
    case OUTSIDE:
        std::cout << "OUTSIDE." << std::endl;
        break;
    default:
        break;        
    }

    if (_nfz) {
        return (rel == INSIDE || rel == ONSIDE);
    } else {
        return (rel == OUTSIDE || rel == ONSIDE);
    }
}

uint16_t AC_Polygon::points_count() const
{
    return _count;
}

void AC_Polygon::clear_all()
{
    // _poinst.clear();
}

/**************************************************************************
 **                    Protected Function Define
 *************************************************************************/
bool AC_Polygon::read_fence_file(const char *fence_file)
{
    // TODO: 暂未实现从文件读取地理围栏信息
    // 地理围栏格式文件参见fence.dat，文件应该放置在sdcard/etc/目录下
    _count = 0;
    _nfz   = false;
    
    return true;
}

/**
 * save_to_file
 *
 * 将多边形围栏信息存到SD中。
 */
bool AC_Polygon::save_to_file(bool force)
{
    force = force;
    
    char *fname = get_fence_file_name();
    if (fname == NULL) {
        return false;
    }
    FILE *fd = fopen(fname, "w");
    char buf[100];
    free(fname);

    if (fd == NULL) {
        return false;
    }

    fprintf(fd, "%c:%d\n", (_nfz ? 'Y': 'N'), _count);
        
    for (int i=0; i<_count; i++) {
        fprintf(fd, "%f,%f\n", _points[i]._x, _points[i]._y);
    }

    fclose(fd);
    return true;
}

char* AC_Polygon::get_fence_file_name()
{
    char *buf = NULL;
    if (asprintf(&buf, "%d.fnc", _id) == 0) {
        return NULL;
    }
    return buf;
}

/**
 * ray_check()
 *
 * 射线法检测指定点与多边形的位置关系
 * @param p -- 指定点
 * @return 
 */
AC_Polygon::e_relative AC_Polygon::ray_check(const AC_Point &p)
{
    e_relative status = INSIDE;
    int count = 0;

    for (int i = 0; i< _count; i++) {
        AC_Point p1 = _points[i];
        AC_Point p2 = _points[(i+1)%_count];

        if ((p1._y > p._y) != (p2._y > p._y)) {
            double k  = (p._y - p1._y) / (p2._y - p1._y);
            double xt = p1._x + k*(p2._x - p1._x);
            
            // if (is_equal(p._x, xt)) {
            if (p._x == xt) {
                status = ONSIDE;
                break;
            } else if (p._x < xt) {
                count++;
            }
        }
    }

    status = (count % 2) ? INSIDE : OUTSIDE;
    
    return status;
}

