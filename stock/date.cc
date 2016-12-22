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
#include <cmath>
#include <cstdio>

Date::Date()
    : _year(0),
      _month(0),
      _day(0)
{

}

Date::Date(uint16_t year, uint8_t month, uint8_t day)
    : _year(year),
      _month(month),
      _day(day)
{

}

Date::~Date()
{

}

bool Date::operator<(const Date & rhs) const
{
    bool f_cmp = false;

    if (_year < rhs._year) {
        f_cmp = true;
    } else
        if (_year == rhs._year) {
            if (_month < rhs._month) {
                f_cmp = true;
            } else
                if (_month == rhs._month) {
                    if (_day < rhs._day) {
                        f_cmp = true;
                    }
                }
        }

    return f_cmp;
}

bool Date::operator==(const Date & rhs) const
{
    return ((this == &rhs) || (_year  == rhs._year  &&
                               _month == rhs._month &&
                               _day   == rhs._day));
}
Date Date::operator+(int delta)
{
    Date date(*this);
    date += delta;
    
    return date;
}

Date & Date::operator+=(int delta)
{
    double d1 = date2jde(_year, _month, _day, 12, 0, 0);
    d1 += delta;
    mjd2date((int64_t)d1, _year, _month, _day);
    return *this;
}

Date & Date::operator=(const Date & rhs)
{
    if (this == &rhs) {
        return *this;
    } else {
        _year  = rhs._year;
        _month = rhs._month;
        _day   = rhs._day;
    }

    return *this;
}

int Date::operator-(const Date & rhs) const
{
    double d1 = date2jde(_year, _month, _day, 12, 0, 0);
    double d2 = date2jde(rhs._year, rhs._month, rhs._day, 12, 0, 0);

    return int(d1 - d2);
}

std::ostream & operator<<(std::ostream & os, const Date & date)
{
    os << date._year << "/" << (int)date._month << "/" << (int)date._day;
    return os;
}

double Date::date2jde(int Y, int M, int D, int hour, int min, int sec)
{
    int64_t f, g, mid1, mid2;
    double J, A;
    double JDE;

    if (M >= 3) {
        f = Y;
        g = M;
    }

    if (M == 1 || M == 2) {
        f = Y - 1;
        g = M = 12;
    };

    mid1 = floor(365.25 * f);
    mid2 = floor(30.6001 * (g + 1));
    A    = 2 - floor(f / 100) + floor(f / 400);
    J    = mid1 + mid2 + D + A + 1720994.5;
    JDE  = J + hour / 24 + min / 1440 + sec / 86400;

    return JDE;
};

bool Date::mjd2date(int64_t mjd, int & pYear, int & pMonth, int & pDay)
{
    typedef enum {
        January = 0,
        February,
        Match,
        Apirl,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    } MONTH;

    int monlen[12];
    monlen[January]   = 31;
    monlen[February]  = 28;
    monlen[Match]     = 31;
    monlen[Apirl]     = 30;
    monlen[May]       = 31;
    monlen[June]      = 30;
    monlen[July]      = 31;
    monlen[August]    = 31;
    monlen[September] = 30;
    monlen[October]   = 31;
    monlen[November]  = 30;
    monlen[December]  = 31;

    const int AD = 678576;
    int32_t   icen4, icen, iyr4;
    int32_t   iyr, imon, iday;

    if (mjd > 2973483) {
        return false;
    }

    if ((mjd += AD - 1) < 0) {
        return false;
    }

    icen4 = mjd / 146097;
    mjd -= (icen4 * 146097);

    if ((icen = mjd / 36524) == 4) {
        icen = 3;
    }

    mjd -= (icen * 36524);
    iyr4 = mjd / 1461;
    mjd -= (iyr4 * 1461);

    if ((iyr = mjd / 365) == 4) {
        iyr = 3;
    }

    iday = mjd - iyr * 365;
    // printf("[dbg] iday = %d \n", iday);

    for (imon = 0; iday >= 0; imon++) {
        iday = iday - monlen[imon] - ((iyr == 3 && imon == 1) ? 1 : 0);
        // printf("[dbg] iday = %d \n", iday);
        // printf("[dbg] imon = %d \n", imon);
    }

    imon--;
    iday = iday + monlen[imon] + ((iyr == 3 && imon == 1) ? 1 : 0);

    pYear  = icen4 * 400 + icen * 100 + iyr4 * 4 + iyr + 1;
    pMonth = imon + 1;
    pDay   = iday + 1;

    return true;
}
