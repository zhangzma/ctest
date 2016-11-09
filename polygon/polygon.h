/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file polygon.h
 *
 * 多边形
 *
 * Detail
 *
 * @author Author zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _POLYGON_H_
#define _POLYGON_H_

#include "point.h"
#include <vector>

class Polygon
{
public:
    Polygon();
    virtual ~Polygon();
    void add_point(const Point &point);
    void delete_point(const Point &point);
    bool in_polygon(const Point &point);

    void decompose_convex();
    void analyze_concave();
    void check_concave();
    bool is_concave();
    bool is_convex();

    enum e_point_status{
        E_INSIDE,
        E_ONSIDE,
        E_OUTSIDE,
    };

private:
    vector<Point>   _origin_points;
    vector<Point>   _points;
    size_t          _nums;
    bool            _concave;   // 凹多边形？？
    vector<Polygon> _ploygons;
};


#endif /* _POLYGON_H_ */



