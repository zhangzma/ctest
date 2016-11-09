// game_board.cpp
//
#include "game_board.h"
#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdio>
#include <cstdlib>

CGameBoard::CGameBoard(int width, int height)
    : m_width(width+1), m_height(height)
{
    srand((unsigned)time(NULL));

    char *pboard = new char[m_height*m_width];
    memset(pboard, ' ', m_height*m_width);
    m_pBoard = new char*[m_height];
    
    for (int row=0; row<m_height; row++) {
        m_pBoard[row] = pboard + row*m_width;
    }

    init_board();
}

CGameBoard::~CGameBoard()
{
    vector<CApple*>::iterator beg = m_apps.begin();
    while (beg != m_apps.end()) {
        delete *beg;
        beg++;
    }
    m_apps.clear();
    
    delete m_pBoard;
    m_pBoard = NULL;
}

bool CGameBoard::is_valid(const CPoint &p)
{
    return (p.row > 0 && p.row < m_height-1 &&
            p.col > 0 && p.col < m_width-1);
}

void CGameBoard::init_board()
{    
    for (int col=0; col<m_width; col++) {
        m_pBoard[0][col] = '#';
        m_pBoard[m_height-1][col] = '#';
    }

    for (int row=0; row<m_height; row++) {
        m_pBoard[row][0] = '#';
        m_pBoard[row][m_width-1] = '#';
    }
}

void CGameBoard::display()
{
    for (int row=0; row<m_height; row++) {
        for (int col=0; col<m_width; col++) {
            printf("%c", m_pBoard[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void CGameBoard::create_a_apple()
{
    bool ok = false;
    
    do {
        CPoint p;
        p.row = rand() % (m_height-2) + 1;
        p.col = rand() % (m_width-2) + 1;
        if (is_valid(p)) {
            printf("Point:(%d,%d)\n", p.row, p.col);
            CApple *papp = new CApple(this, p);
            set_apple(papp);
            ok  = true;
        }
    } while (!ok);
}

void CGameBoard::reset()
{
    init_board();
    update_apples();
}

void CGameBoard::set_apple(const CApple *papp)
{
    const CPoint p = papp->get_point();

    m_pBoard[p.row][p.col] = CApple::M_APPLE;
}

void CGameBoard::update_apples()
{
    vector<CApple*>::iterator beg = m_apps.begin();
    while (beg != m_apps.end()) {
        set_apple(*beg);
        beg++;
    }
}
