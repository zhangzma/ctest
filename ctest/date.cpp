// tody.cpp
// Copyright (c) 2015 www.bjfz.com. All rights reserved.
#include <iostream>

/**
 * day of month.
 */
int day_of_month[13] = {0,
                        31, 28, 31, 30, 31, 30,
                        31, 31, 30, 30, 30, 31};

typedef struct _date {
    int year;
    int month;
    int day;
}date;

void print_date(const date &d);
bool is_leap_year(int year);

int main(int argc, char *argv[])
{
    date d;
    std::cout << "Please input the date: " << std::endl;
    std::cin >> d.year >> d.month >> d.day;

    int count = 0;
    for (int m=0; m<d.month; m++) {
        count += day_of_month[m];
    }

    if (d.month > 2) {
        if (is_leap_year(d.year)) {
            // std::cout << d.year << " is leap year." << std::endl;
            count++;
        }
    }

    count += d.day;
    std::cout << "Count is: " << count << std::endl;

    // print_date(d);
    return 0;
}

void print_date(const date &d)
{
    std::cout << d.year << "-"
              << d.month << "-"
              << d.day << std::endl;
}

bool is_leap_year(int year)
{
    return ((year%4 == 0 && year%100 != 0) || year % 400 == 0);
}


