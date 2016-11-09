/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file Game.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Author zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _GAME_H_
#define _GAME_H_

#include "Person.h"

class Game
{
public:
    Game();
    virtual ~Game();

    float calc_score();

private:
    Person _person;
};


#endif /* _GAME_H_ */



