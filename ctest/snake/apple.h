// apple.h
//
#ifndef _APPLE_H_
#define _APPLE_H_

#include "point.h"

class CGameBoard;

class CApple
{
public:
    CApple(CGameBoard *pboard, int row, int col);
    CApple(CGameBoard *pboard, const CPoint &p);
    virtual ~CApple();

    void set_point(const CPoint &point);
    CPoint get_point() const;

    void display();
    bool set_game_board(CGameBoard *pboard);

    const static char M_APPLE = '*';


protected:
    void update();

private:
    CPoint m_point;
    CGameBoard *m_pboard;
};


#endif /* _APPLE_H_ */
