/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file gardener.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _GARDENER_C_
#include "gardener.h"
#include <iostream>
#include <sstream>

Gardener::Gardener(const std::string &str)
    : _str_orig(str),
      _str(str)
{
    
}

Gardener::~Gardener()
{

}


Date Gardener::get_date()
{
    std::istringstream iss(_str);
    uint16_t year;
    int16_t  month, day;
    
    iss >> year >> month >> day;
    month = month < 0? -month : month;
    day   = day < 0 ? -day : day;
    Date date(year, month, day);
    return date;
}

std::istream& operator>>(std::istream& s, Gardener& c)
{
    s >> c._str_orig;
    c._str = c._str_orig;
    return s;
}

std::ostream& operator<<(std::ostream& s, const Gardener& c)
{
    s << c._str;
    return s;
}

