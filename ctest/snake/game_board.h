// game_board.h
// Copyright (c) 2015 www.bjfz.cn
#ifndef _GAME_BOARD_H_
#define _GAME_BOARD_H_

#include "apple.h"
#include <vector>
using std::vector;

class CGameBoard
{
public:
    CGameBoard(int width, int height);
    virtual ~CGameBoard();

    bool is_valid(const CPoint &p);

    void init_board();
    void display();

    void create_a_apple();
    void set_apple(const CApple *papp);


protected:
    void reset();
    void update_apples();

private:
    int m_width;
    int m_height;

    char **m_pBoard;

    // apples
    vector<CApple*> m_apps;    
};

#endif /* _GAME_BOARD_H_ */

