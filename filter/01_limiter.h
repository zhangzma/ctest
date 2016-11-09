/***************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file limiter.cc
 *
 * 限幅滤波器实现
 *
 * ## 限幅滤波法（又称程序判断滤波法）
 * ### 方法：
 *	- 根据经验判断，确定两次采样允许的最大偏差值（设为A）
 *	- 每次检测到新值时判断：
 *	  1. 如果本次值与上次值之差<=A,则本次值有效
 *	  2. 如果本次值与上次值之差>A,则本次值无效,放弃本次值,用上次值代替本次值
 * ### 优点：
 *	- 能有效克服因偶然因素引起的脉冲干扰
 * ### 缺点
 *	- 无法抑制那种周期性的干扰
 *	- 平滑度差
 *
 * @author Author email
 *
 **************************************************************************/
/* #include "limiter.h" */
#include <cstdlib>

namespace filter
{

#ifndef LIMITER_MAX
#define LIMITER_MAX 0.003
#endif /* LIMITER_MAX */


template<typename T>
T limiter(const T &newVal)
{
	static T validVal = newVal;
	if (abs(validVal - newVal) <= LIMITER_MAX*validVal) {
		validVal = newVal;
	}

	return validVal;
}

}

