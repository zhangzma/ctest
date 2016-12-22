/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file fund.h
 *
 * Fund基础类
 *
 * 
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _FUND_H_
#define _FUND_H_

#include "daily_record.h"
#include <string>
#include <set>

class Fund
{
public:
    Fund(const std::string &name);
    virtual ~Fund();

    void  add_record(const DailyRecord &r);
    void  read_file(const char* fn);
    float average(const Date &d1, const Date &de, DailyRecord::PRICE_TYPE type = DailyRecord::P_ENDING);
    float average(const Date &d1, uint32_t day, DailyRecord::PRICE_TYPE type = DailyRecord::P_ENDING);
    bool get(const Date &date, DailyRecord& dr);
    uint32_t size() const;

public:
friend std::ostream& operator<<(std::ostream&, const Fund&);

protected:
    void reset();

private:
    std::string _name;
    std::string _no;
    std::set<DailyRecord> _records;
};

#endif /* _FUND_H_ */

