/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file date.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _DATE_C_
#include "date.h"

Date::Date(uint16_t year, uint8_t month, uint8_t day)
    : _year(year),
      _month(month),
      _day(day)
{
    
}

Date::~Date()
{

}

bool Date::operator<(const Date &rhs) const
{
    bool f_cmp = false;
    
    if (_year < rhs._year) {
        f_cmp = true;
    } else if (_year == rhs._year) {
        if (_month < rhs._month) {
            f_cmp = true;
        } else if (_month == rhs._month) {
            if (_day < rhs._day) {
                f_cmp = true;
            }
        }
    }

    return f_cmp;
}

Date& Date::operator = (const Date &rhs) {

    // Check for self-assignment!
    if (this == &rhs) {
        return *this;
    } else {
        _year  = rhs._year;
        _month = rhs._month;
        _day   = rhs._day;
    }
        
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date._year << "/" << (int)date._month << "/" << (int)date._day;
    return os;
}
