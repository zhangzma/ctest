/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include <iostream>

typedef float t_score;

typedef struct _s_state
{
    t_score chinese;
    t_score english;
    t_score math;
}s_state;

void print_stu_state(const s_state &state)
{
    std::cout << state.chinese << "\t"
              << state.english << "\t"
              << state.math << std::endl;
}

int main(int argc, char *argv[])
{
    float score[3];
    s_state &state = (*reinterpret_cast<s_state*>(score));
    
    score[0] = 89.9;
    score[1] = 79.9;
    score[2] = 99.9;
    
    print_stu_state(state);
    return 0;
}



