// eva_random.cpp

#include "eva_random.h"
#include <math.h>
#include <stdlib.h>



eva::Random::Random()
{
    m_rand = rand();
}

eva::Random::~Random()
{
}

int eva::Random::data()
{
    return m_rand;
}


