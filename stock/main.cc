/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _MAIN_C_
#include "fund.h"
#include <iostream>

void test_date()
{
    std::cout << "========== Class Date' tests ==========" << std::endl;
    Date date(2016, 11, 16);
    std::cout << date << std::endl;

    Date date2(2016, 11, 17);

    std::cout << (date < date2) << std::endl;

    Date d3(date2);
    std::cout << d3 << std::endl;

    std::cout << "========== End of tests ==========" << std::endl;
}


void test_daily_record()
{
    std::cout << "========== Class Date' tests ==========" << std::endl;
    Date date(2016, 11, 16);
    DailyRecord dr(date);
    dr.set_price(15.0, 15.9, 14.5, 15.2);

    Date date2(2016, 11, 17);
    DailyRecord dr2(date2);
    dr2.set_price(13.0, 17.9, 14.5, 14.2);
    
    std::cout << dr << std::endl;
    std::cout << dr2 << std::endl;    
    std::cout << (dr < dr2) << std::endl;
}

void test_fund()
{
    std::cout << "========== Fund Date' tests ==========" << std::endl;
    Fund f("Hushen 300");

    Date date(2016, 11, 16);
    DailyRecord dr(date);
    dr.set_price(15.0, 15.9, 14.5, 15.2);
    f.add_record(dr);

    Date date2(2016, 11, 17);
    DailyRecord dr2(date2);
    dr2.set_price(13.0, 17.9, 14.5, 14.2);

    f.add_record(dr2);
    
    std::cout << f << std::endl;
}

int main(int argc, char *argv[])
{
    test_fund();
    return 0;
}


