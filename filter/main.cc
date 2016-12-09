/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 * 11种滤波算法测试，滤波算法实现参见filter.h
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _MAIN_C_
#include "filter.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

float get_data();

int main(int argc, char *argv[])
{
	float data;
	srand((unsigned)time(NULL));

	pf new_data = get_data;

	for (int i=0; i<100; i++) {
		// data = filter::median(new_data, 1.0f);
        data = new_data();
		std::cout << data << "\n";
        // if ((i+1) % 10 == 0) {
        //     std::cout << std::endl;
        // }
	}

	std::cout << std::endl;

    return 0;
}

float get_data()
{
	static float data = 1000;
	float coefficient = (rand() % 100) / 100.0 - 0.5;

    std::cout << data << "\t"
              << coefficient << "\t";

	data += coefficient*data/10.0;
	return data;
}

