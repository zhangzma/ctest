// Copyright (c) 2015 www.bjfz.com. All rights reserved.
// my_math.h

#ifndef _MY_MATH_H_
#define _MY_MATH_H_

#include <stdbool.h>


#define TO_LOWER(x) ((x) | 0x20)


bool lib_isxdigit(char ch);
int  lib_guess_base(const char* cp);


#endif /* _MY_MATH_H_ */

