/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file pid.c
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _PID_C_
/* #include "pid.h" */
#include <stdio.h>
#include <stdlib.h>

typedef struct _pid_t {
    float _set_speed;
    float _actual_speed;
    float _err;
    float _err_last;
    float _Kp;
    float _Ki;
    float _Kd;
    float _voltage;
    float _integral;
}pid_s;

void dbg_print_pid(pid_s *pid)
{
    printf("kp = %f\tki=%f\tkd=%f\n",
           pid->_Kp,
           pid->_Ki,
           pid->_Kd);
}

void pid_init(pid_s *pid)
{
    pid->_set_speed    = 0.0;
    pid->_actual_speed = 0.0;
    pid->_err          = 0.0;
    pid->_err_last     = 0.0;
    pid->_voltage      = 0.0;
    pid->_integral     = 0.0;

    pid->_Kp = 0.4;
    pid->_Ki = 0.015;
    pid->_Kd = 0.2;
}

void pid_set_ks(pid_s *pid, float kp, float ki, float kd)
{
    pid->_Kp = kp;
    pid->_Ki = ki;
    pid->_Kd = kd;
}

float pid_realize(float speed, pid_s *pid)
{
    pid->_set_speed  = speed;
    pid->_err        = pid->_set_speed - pid->_actual_speed;
    pid->_integral  += pid->_err;
    pid->_voltage    = pid->_Kp * pid->_err
        + pid->_Ki * pid->_integral
        + pid->_Kd * (pid->_err - pid->_err_last);
    
    pid->_err_last = pid->_err;
    pid->_actual_speed = pid->_voltage * 1.0;
    return pid->_actual_speed;
}

int main(int argc, char *argv[])
{
    int   count = 0;
    float speed = 0.0;
    pid_s pid;

    pid_init(&pid);
    
    if (argc == 4) {
        float kp, ki, kd;
        char *pend;

        kp = strtof(argv[1], &pend);
        ki = strtof(argv[2], &pend);
        kd = strtof(argv[3], &pend);
        pid_set_ks(&pid, kp, ki, kd);
        dbg_print_pid(&pid);
    }

    while (count < 1000) {
        speed = pid_realize(200.0, &pid);
        printf("%f\n", speed);
        count++;
    }
    
    return 0;
}

