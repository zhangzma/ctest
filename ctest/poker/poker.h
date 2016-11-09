// copyright (c) 2015 www.eva-tec.cn
// @file poker.h
#ifndef _POKER_H_
#define _POKER_H_

#include <iostream>

// define the poker type
enum ecard_type
{
    ECT_SPADE,                  // 黑桃
    ECT_HEART,                  // 红桃
    ECT_CLUB,                   // 梅花
    ECT_DIAMOND,                // 方块
};

class CPoker
{
public:
	CPoker(ecard_type type, int value);
    CPoker(int gval);
	virtual ~CPoker();
	void info();

    friend class CPlayer;
private:
	ecard_type m_type;
	int        m_value;
    int        m_gval;
};

#endif /* _POKER_H_ */

