/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file point.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Author zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _POINT_H_
#define _POINT_H_

class Point
{
public:
    Point(double x, double y);
    virtual ~Point();

    void set_concave(bool concave);
    bool is_concave_point() const;

    bool operator==(const Point &rhs);

friend class Polygon;

private:
    double _x;
    double _y;
    bool _concave;
};


#endif /* _POINT_H_ */



