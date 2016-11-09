// copyright (c) www.eva-tec.cn
// player.cpp
#include "player.h"

CPlayer::CPlayer(const char* name)
{
    if (name != NULL)
    {
        m_name = name;
    }
}

CPlayer::~CPlayer()
{
    for (int i=0; i<m_pokers.size(); i++) {
        delete m_pokers[i];
        m_pokers[i] = NULL;
    }
}

void CPlayer::add_poker(CPoker *ppoker)
{
    m_pokers.push_back(ppoker);
}

void CPlayer::del_poker(CPoker *ppoker)
{
    std::vector<CPoker*>::iterator it = m_pokers.begin();
    while (it != m_pokers.end()) {
        if ((*it)->m_gval == ppoker->m_gval) {
            m_pokers.erase(it);
            break;
        }
        it++;
    }
}

void CPlayer::displayer_all_poker()
{
    std::cout << m_name << "'s cards is: " << std::endl;
    std::vector<CPoker*>::iterator it = m_pokers.begin();
    while (it != m_pokers.end()) {
        (*it)->info();
        it++;
    }
}

