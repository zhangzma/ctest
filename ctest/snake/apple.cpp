// apple.cpp

#include "apple.h"
#include "game_board.h"


CApple::CApple(CGameBoard *pboard, int row, int col)
{
    m_point.row = row;
    m_point.col = col;

    set_game_board(pboard);
}

CApple::CApple(CGameBoard* pboard, const CPoint &p)
    : m_point(p)
{
    set_game_board(pboard);
}

CApple::~CApple()
{
}

void CApple::set_point(const CPoint &point)
{
    m_point = point;
}

CPoint CApple::get_point() const
{
    return m_point;
}

void CApple::display()
{
    update();
    if (m_pboard) {
        m_pboard->display();        
    }
}

bool CApple::set_game_board(CGameBoard *pboard)
{
    if (pboard->is_valid(m_point)) {
        // TODO: clear the old board.
        
        m_pboard = pboard;
        update();
        return true;
    }
    return false;
}

void CApple::update()
{
    if (m_pboard && m_pboard->is_valid(m_point)) {
        m_pboard->set_apple(this);
    }
}
