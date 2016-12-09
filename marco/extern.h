/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file extern.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _EXTERN_H_
#define _EXTERN_H_

#define EXTERN_DECLARE(XXX)      \
    #ifndef _#XXX#_C_              \
    #   define XXX#_EXTERN extern \
    #else                        \
    #   define XXX#_EXTERN        \
    #endif /* _#XXX#_C_ */         \

#endif /* _EXTERN_H_ */



