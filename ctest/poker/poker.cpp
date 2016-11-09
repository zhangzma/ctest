// copyright (c) 2015 www.eva-tec.cn
// @file poker.cpp
#include "poker.h"
#include <string>

std::string g_tName[] = {"Spade", "Heart", "Club", "Diamond"};

// 构造函数
CPoker::CPoker(ecard_type type, int value)
    : m_type(type), m_value(value)
{
    m_gval = m_type * 13 + m_value;
}

CPoker::CPoker(int gval)
    : m_gval(gval)
{
    m_type  = (ecard_type)((m_gval-1)/13);
    m_value = (m_gval-1)%13 + 1;
}

// 析构函数
CPoker::~CPoker()
{

}

void CPoker::info()
{
    std::cout << g_tName[m_type] << m_value << std::endl;
}
