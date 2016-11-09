// typedef.h

#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include <stdio.h>
#include <stdlib.h>

#ifdef STUDENT_CPP
#define STU_EXT
#else
#define STU_EXT extern
#endif // STUDENT_CPP

#ifndef false
#define false 0
#define true (!false)

typedef int bool;
#endif // false

#define NAME_LEN 32

#define E_JNR 1
#define E_SCH 2
#define E_MST 3

#ifdef Z_DEBUG
#endif


#endif /* _TYPEDEF_H_ */
