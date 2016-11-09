/***************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file 02_median.h
 *
 * 中值滤波
 *
 * 2、中位值滤波法
 * A、方法：
 *   连续采样N次（N取奇数）
 *   把N次采样值按大小排列
 *   取中间值为本次有效值
 *B、优点：
 *   能有效克服因偶然因素引起的波动干扰
 *   对温度、液位的变化缓慢的被测参数有良好的滤波效果
 *C、缺点：
 *   对流量、速度等快速变化的参数不宜
 *
 * @author Author zhanghaibo@bjfz.cc
 *
 **************************************************************************/
#ifndef _02_MEDIAN_H_
#define _02_MEDIAN_H_
#include <algorithm>
#include <vector>

typedef float (*pf)();


namespace filter {

#ifndef MEDIAN_MAX
#define MEDIAN_MAX	9
#endif /* MEDIAN_MAX */

template<typename T>
T median(pf get_data, T type)
{
	type = type;
	std::vector<T> vals;

	for (size_t i=0; i<MEDIAN_MAX; i++) {
		vals.push_back(get_data());
	}

	sort(vals.begin(), vals.end());

	return vals[MEDIAN_MAX%2];
}
	
}

#endif /* _02_MEDIAN_H_ */



