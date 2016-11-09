/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 * 1. FillAsscending
 * 2. StandardDeviation
 *
 * @author zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>


using namespace std;

struct sq_of_dvi {
    sq_of_dvi(double avg){
        _avg = avg;
    }
        
    double operator()(double y, double x) {
        return y + (x-_avg)*(x-_avg);
    }
        
    double _avg;
};

int increment()
{
	static int i = 0;
    return i++;
}

template<typename T>
void FillAsscending(T beg, T end)
{
    generate(beg, end, increment);
}

template<typename T>
double StandardDeviation(T beg, T end)
{
    // 1. calc the avg
    double avg = accumulate(beg, end, 0.0) / distance(beg, end);

    // 2. calc the sum
    // 2.1 squares_of_deviations
    struct sq_of_dvi sod(avg);
    // 2.2 calc the sum of squares_of_deviations
    double sum = accumulate(beg, end, 0.0, sod);

    // 3. standard deviation
    return sqrt(sum);
}

int main(int argc, char *argv[])
{
    vector<int> ivec(10);
    FillAsscending(ivec.begin(), ivec.end());

    vector<int>::iterator beg = ivec.begin();
    while (beg != ivec.end()) {
        std::cout << *beg++ << "\t";
    }
    std::cout << std::endl;

    std::cout << StandardDeviation(ivec.begin(), ivec.end())
              << std::endl;
    
    return 0;
}

