/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file fund.cc
 *
 * Fund
 *
 * 
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _FUND_C_
#include "fund.h"
#include "gardener.h"
#include <fstream>
#include <cstdio>
#include <cstdlib>

#include <string.h>
using std::set;
using std::string;


Fund::Fund(const std::string& name)
    : _name(name)
{
    
}

Fund::~Fund()
{
    
}

void Fund::add_record(const DailyRecord &r)
{
    _records.insert(r);
}

void Fund::read_file(const char* fn)
{
    std::ifstream infile;
    Gardener sdate;
    Gardener sop, shp, slp, sep;
    
    infile.open(fn);
    if (infile) {
        char sink[1024];
        infile.getline(sink, 1024);
        reset();

        while (!infile.eof()) {
            infile >> sdate >> sop >> shp >> slp >> sep;
            DailyRecord dr(sdate.get_date());
            dr.set_price(sop.get_value<float>(), shp.get_value<float>(), 
                         slp.get_value<float>(), sep.get_value<float>());

            this->add_record(dr);
        }
        infile.close();

        // std::cout << *this << std::endl;
    }
}

float Fund::average(const Date &d1, const Date &d2, DailyRecord::PRICE_TYPE type)
{
    Date     date = d1 < d2 ? d1 : d2;
    uint32_t day  = abs(d2 - d1);
    
    return average(date, day, type);
}


float Fund::average(const Date &d1, uint32_t day, DailyRecord::PRICE_TYPE type)
{
    float       total(0.0);
    uint32_t    count(0);
    Date        date;
    DailyRecord dr(date);

    for (uint32_t i = 0; i < day; i++) {
        if (get(date, dr)) {
            total += dr.get_price(type);
            count += 1;
        }
        date += 1;
    }

    return (total / count);
}

bool Fund::get(const Date &date, DailyRecord& dr)
{
    std::set<DailyRecord>::iterator beg = _records.begin();
    while (beg != _records.end()) {
        if ((*beg)._date == date) {
            dr = *beg;
            return true;
        }
    }
    
    return false;
}


uint32_t Fund::size() const
{
    return _records.size();
}


std::ostream& operator<<(std::ostream& os, const Fund& f)
{
    os << "########## " << f._name << " ##########" << std::endl;
    std::set<DailyRecord>::iterator beg = f._records.begin();
    while (beg != f._records.end()) {
        os << *beg++ << std::endl;
    }
    
    return os;
}

/**************************************************************************
 **                    Protected Functions
 *************************************************************************/
void Fund::reset()
{
    _records.clear();
}
