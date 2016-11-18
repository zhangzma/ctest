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
    void add_record(const DailyRecord &r);
    void read_file(const char* fn);

public:
friend std::ostream& operator<<(std::ostream&, const Fund&);

private:
    std::string _name;
    std::set<DailyRecord> _records;
};


#endif /* _FUND_H_ */



