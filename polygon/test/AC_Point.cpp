/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file AC_Point.cpp
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include "AC_Point.h"

/**************************************************************************
 **                    Public Function Define
 *************************************************************************/
AC_Point::AC_Point()
    : _x(0), _y(0)
{

}

AC_Point::AC_Point(double x, double y)
    : _x(x), _y(y)
{

}

AC_Point::AC_Point(const Location &loc)
{
    _x = loc.lng / 10000000;
    _y = loc.lat / 10000000;
}

AC_Point::~AC_Point()
{

}

