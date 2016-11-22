/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file daily_record.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _DAILY_RECORD_C_
#include "daily_record.h"
#include <cstdio>

DailyRecord::DailyRecord(const Date& date)
    : _date(date),
      _price_opening(0.0),
      _price_highest(0.0),
      _price_lowest(0.0),
      _price_ending(0.0)
{

}


DailyRecord::~DailyRecord()
{

}

void DailyRecord::set_price(float op, float hp, float lp, float ep)
{
    _price_opening = op;
    _price_highest = hp;
    _price_lowest  = lp;
    _price_ending  = ep;
}

float DailyRecord::get_opening_price()
{
    return _price_opening;
}

float DailyRecord::get_ending_price()
{
    return _price_ending;
}

float DailyRecord::get_lowest_price()
{
    return _price_lowest;
}

float DailyRecord::get_highest_price()
{
    return _price_highest;
}

float DailyRecord::get_average_price()
{
    return (_price_lowest + _price_highest) / 2;
}

/**************************************************************************
 **                    Overload Operator Function
 *************************************************************************/
bool DailyRecord::operator<(const DailyRecord &rhs) const
{
    return (_date < rhs._date);
}

std::ostream& operator<<(std::ostream& os, const DailyRecord& dr)
{
    os << dr._date << "\t";
    char buff[64];
    sprintf(buff, "%7.2f\t%7.2f\t%7.2f\t%7.2f",
            dr._price_opening,
            dr._price_highest,
            dr._price_lowest,
            dr._price_ending);
    os << buff;

    return os;
}

