/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file Record.h
 *
 * FundRecord
 *
 * 
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _DAILY_RECORD_H_
#define _DAILY_RECORD_H_

#include "date.h"

class DailyRecord
{
public:
    DailyRecord(const Date& date);
    virtual ~DailyRecord();

    void set_price(float op, float hp, float lp, float ep);

    float get_opening_price();
    float get_ending_price();
    float get_lowest_price();
    float get_highest_price();
    float get_average_price();

public:
    bool operator<(const DailyRecord &) const;

friend std::ostream& operator<<(std::ostream&, const DailyRecord& dr);

private:
    float _price_opening;
    float _price_ending;
    float _price_lowest;
    float _price_highest;
    Date _date;
};

#endif /* _DAILY_RECORD_H_ */

