// copyright (c) www.eva-tec.cn
// player.h

#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "poker.h"
#include <vector>

const int CARD_NUM_PER_PLAYER = 13;

class CPlayer
{
public:
    CPlayer(const char* name = NULL);
    virtual ~CPlayer();

    void add_poker(CPoker *ppoker);
    void del_poker(CPoker *ppoker);
    void displayer_all_poker();

private:
    std::string m_name;
    std::vector<CPoker*> m_pokers;
};


#endif /* _PLAYER_H_ */
