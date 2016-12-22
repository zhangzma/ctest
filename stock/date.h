/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file date.h
 *
 * Date类定义
 *
 *
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _DATE_H_
#define _DATE_H_

#include "type.h"
#include <iostream>
#include <cstdlib>

class Date
{
public:
    Date();
    Date(uint16_t year, uint8_t month, uint8_t day);
    virtual ~Date();
    static double date2jde(int Y, int M, int D, int hour, int min, int sec);
    static bool mjd2date(int64_t mjd, int &pYear, int &pMonth, int &pDay);

public:
    bool  operator  < (const Date &) const;
    bool  operator == (const Date &) const;
    Date& operator += (int delta);
    Date  operator + (int delta);
    Date& operator  = (const Date & rhs);
    int   operator  - (const Date & rhs) const;

    friend std::ostream & operator<<(std::ostream &, const Date &);

private:
    int32_t _year;
    int32_t  _month;
    int32_t  _day;
};

#endif /* _DATE_H_ */
