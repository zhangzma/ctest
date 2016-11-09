// Copyright (c) 2015 www.bjfz.com. All rights reserved.
// guess_base.c

#include "my_math.h"


bool lib_isxdigit(char ch)
{
    if ((ch >= '0' && ch <= '9') ||
        (ch >= 'a' && ch <= 'f') ||
        (ch >= 'A' && ch <= 'F')) {
        return true;
    }

    return false;
}

int lib_guess_base(const char* cp)
{
    if (sizeof(cp) < 1) {
        return -1;
    }

    if (cp[0] == '0') {
        if (TO_LOWER(cp[1]) == 'x' && lib_isxdigit(cp[2])) {
            return 16;
        }
        else {
            return 8;
        }
    }

    printf("[Debug] sizeof(cp) = %d\n", sizeof(cp));

    if (cp[sizeof(cp)-1] == 'b') {
        return 2;
    }

    return 10;
}


