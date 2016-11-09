/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file ex01-31.cc
 *
 * 
 *
 * 
 *
 * @author zhanghb zhanghb@foxmail.com
 *
 *************************************************************************/
#include <iostream>

template<typename T>
int max(T a[], int n)
{
    int pos = 0;
    for (int i=1; i<n; i++) {
        if (a[pos] < a[i]) {
            pos = i;
        }
    }

    return pos;
}

int main(int argc, char *argv[])
{
    const int N = 5;

    int a[N] = {1, 2, 9, 5, 7};
    int pos  = max(a, N);

    std::cout << a[pos] << std::endl;
    return 0;
}

