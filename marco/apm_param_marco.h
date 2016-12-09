/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file apm_param_marco.h
 *
 * APM飞控参数定义宏研究
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _APM_PARAM_MARCO_H_
#define _APM_PARAM_MARCO_H_

// a variant of offsetof() to work around C++ restrictions.
// this can only be used when the offset of a variable in a object
// is constant and known at compile time
#define AP_VAROFFSET(type, element) (((uintptr_t)(&((const type *)1)->element))-1)

// find the type of a variable given the class and element
#define AP_CLASSTYPE(class, element) ((uint8_t)(((const class *) 1)->element.vtype))

// declare a group var_info line
#define AP_GROUPINFO(name, idx, class, element, def) { AP_CLASSTYPE(class, element), idx, name, AP_VAROFFSET(class, element), {def_value : def} }

// the Info and GroupInfo structures are passed by the main
// program in setup() to give information on how variables are
// named and their location in memory
struct GroupInfo {
    uint8_t type; // AP_PARAM_*
    uint8_t idx;  // identifier within the group
    const char name[AP_MAX_NAME_SIZE+1];
    uintptr_t offset; // offset within the object
    union {
        const struct GroupInfo *group_info;
        const float def_value;
    };
};

#endif /* _APM_PARAM_MARCO_H_ */

