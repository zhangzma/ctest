/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.c
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MIX(a, b) ((a) > (b) ? b : a)

// #define true  1
// #define false 0
// 
// typedef unsigned char bool;
typedef unsigned char uint8_t;

bool is_camera_cmd(const char *cmd_name, int len)
{
    char cmdArr[][9] = {
        "RC8_MIN",
        "RC9_MIN",
        "RC10_MIN",
        "RC11_MIN",
    };
    bool is_cmd = false;
    len = MIX(len, 9);

    for (int i=0; i<sizeof(cmdArr)/9; i++) {
        if (strncmp(cmdArr[i], cmd_name, len) == 0) {
            is_cmd = true;
            break;
        }
    }
    
    return is_cmd;
}

int main(int argc, char *argv[])
{
    const int CMD_LEN      = 9; // 相机控制字长度
    // 当前相机控制是通过通道最小参数设置来实现的
    char camera_cmd[][CMD_LEN] = {
        "RC8_MIN",             // 云台俯仰控制通道
        "RC9_MIN",             // 云台偏航控制通道
        "RC10_MIN",             // 相机焦距控制通道
        "RC11_MIN"              // 相机快门控制通道
    };

    char cmd_id[16] = "RC11_MIN";
    
    const int CMD_COUNT = sizeof(camera_cmd)/CMD_LEN;
    printf("cmd count: %d\n", CMD_COUNT);

    if (is_camera_cmd(cmd_id, 16)) {
        printf("%s: is cmd\n", cmd_id);
    } else {
        printf("%s: is not cmd.\n", cmd_id);
    }

    return 0;
}

