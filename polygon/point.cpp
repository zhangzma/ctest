/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file point.cpp
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include "point.h"

Point::Point(double x, double y)
    : _x(x), _y(y), _concave(false)
{
    
}

Point::~Point()
{
    
}

void Point::set_concave(bool cave)
{
    _concave = cave;
}

bool Point::is_concave_point() const
{
    return _concave;
}

static bool eq_float(double x, double y)
{
    const double EPSON = 0.00000001;
    return abs(x - y) < EPSON;
}

bool Point::operator==(const Point &rhs)
{
    return (eq_float(_x, rhs._x) && eq_float(_y, rhs._y));
}

