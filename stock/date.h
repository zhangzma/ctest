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

class Date
{
public:
    Date(uint16_t year, uint8_t month, uint8_t day);
    virtual ~Date();

public:
    bool operator<(const Date &) const;
    Date& operator=(const Date &rhs);

friend std::ostream& operator<<(std::ostream&, const Date&);

private:
    uint16_t _year;
    uint8_t  _month;
    uint8_t  _day;
};


#endif /* _DATE_H_ */



