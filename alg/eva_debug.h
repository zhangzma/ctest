// eva_debug.h
#ifndef _EVA_DEBUG_H_
#define _EVA_DEBUG_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


#ifdef DEBUG

void warnx(const char *fmt, ...)
{
    va_list args;
    
    va_start(args, fmt);
    fprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}

#else

void warnx(const char* fmt, ...) {}


#endif /* DEBUG */


#endif /* _EVA_DEBUG_H_ */
