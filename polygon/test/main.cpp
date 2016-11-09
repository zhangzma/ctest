/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cpp
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include "AC_Polygon.h"
#include <iostream>
using namespace std;

const uint16_t PEAK_COUNT = 4;
// 武汉测试点坐标#2、#62、#63、#64

#define _WUHAN_TEST 1

#ifdef _WUHAN_TEST
AC_Point points[PEAK_COUNT] = {
    {36.68230, 117.1338},
    {36.68219, 117.1335},
    {36.68207, 117.1336},
    {36.68221, 117.1340}
};
#else
// 济南维旺生物测试点坐标
AC_Point points[PEAK_COUNT] = {
    {36.68223987, 117.13376306},
    {36.68223987, 117.13366308},
    {36.68213989, 117.13366308},
    {36.68213989, 117.13376306}
};
#endif

int main(int argc, char *argv[])
{
    AC_Polygon polygon;
#ifdef _WUHAN_TEST
    AC_Point p1(117.1336, 36.68219);
    AC_Point p2(30.397716923893, 114.454607612644);
    AC_Point p3(30.407716923893, 114.454607612644);
#else
    AC_Point p1(36.68219987, 117.13371306);
    AC_Point p2(36.68223987, 117.13376306);
    AC_Point p3(30.68223987, 117.13376306);
#endif /* _WUHAN_TEST */

    polygon.set_nfz(false);
    for (int i = 0; i < PEAK_COUNT; i++) {
        // polygon.add_point(points[i]);
        polygon.set_point(i, points[i]);
    }


    // std::cout << "Polygon is ";
    // if (polygon.is_nfz()) {
    //     std::cout << " NFZ." << std::endl;
    // } else {
    //     std::cout << " not NFZ." << std::endl;
    // }

    // if (polygon.save_to_file(true)) {
    //     std::cout << "Save file OK." << std::endl;
    // } else {
    //     std::cout << "Save file error." << std::endl;
    // }

    if (polygon.touch_side(p1)) {
        std::cout << "P1 is out side." << std::endl;
    } else {
        std::cout << "P1 is in side." << std::endl;
    }

    // if (polygon.touch_side(p2)) {
    //     std::cout << "P2 is out side." << std::endl;
    // } else {
    //     std::cout << "P2 is in side." << std::endl;
    // }

    // if (polygon.touch_side(p3)) {
    //     std::cout << "P3 is out side." << std::endl;
    // } else {
    //     std::cout << "P3 is in side." << std::endl;
    // }

    return 0;
}

