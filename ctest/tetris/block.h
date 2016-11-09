// block.h
// Copyright (c) 2015 www.bjfz.com. All rights reserved.

#ifndef _BLOCK_H_
#define _BLOCK_H_

const int BG_SQUARE_LEN = 4;

enum EB_TYPE {
    EB_O,                       // O
    EB_I,                       // I
    EB_L,                       // L
    EB_R,                       // R
    EB_T                        // T
};

class CBlock
{
public:
    CBlock();
    virtual ~CBlock();

    void print();
    bool rotate() = 0;
    bool crash() = 0;

private:
    EB_TYPE m_type;
    int     m_statue;

    char m_bg[BG_SQUARE_LEN][BG_SQUARE_LEN];
};



#endif /* _BLOCK_H_ */
