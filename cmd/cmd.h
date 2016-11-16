/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file cmd.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _CMD_H_
#define _CMD_H_

enum cmd_t{
    CMD_I = 0,
    CMD_C,
    CMD_D,
    CMD_V,
    CMD_Q
};

void exec_cmd(cmd_t cmd);


#endif /* _CMD_H_ */



