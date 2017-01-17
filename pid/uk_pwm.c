/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file uk_pwm.c
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _UK_PWM_C_



void PWMProcess(void)
{
    uint16 temp   = 0;
    uint16 UKTemp = 0;

    if (Pwm.ChangeFlag_Uint8 != 0) {      //判断是否需要改变占空比
        //是否需要改变占空比和你的被控系统特性有关
        Pwm.ChangeFlag_Uint8 = 0;
        UKTemp  =  PID.Uk_Uint16  + SwIn.AddValue_Uint16;
    }

    //计算UK控制量
    //控制量和计算值以及一个开关量有关，
    //我这里的开关量是系统需要的时候叠加在控制量上的一个变量。
    //这里只所以是999封顶而不是1024是因为我的系统PWM的峰值电压是12V导致。
    if (UKTemp > 999) {
        UKTemp  =  999;
    }

    while (1) {
        //如果输出电压和期望电压相差 Delta，则继续调整占空比，直到在误差以内
        ADChPro(UPWMADCH);

        if (ADPool.Value_Uint16[UPWMADCH] == UKTemp) {
            return;
        }

        //如果当前电压大于输出电压，减小占空比
        if ( ADPool.Value_Uint16[UPWMADCH] > UKTemp) {
            if ((ADPool.Value_Uint16[UPWMADCH] - UKTemp) > UDELTA) {
                temp = ADPool.Value_Uint16[UPWMADCH] - UKTemp;  //
                temp = temp / 2;       //下降可以加速下降，所以下降参数加倍

                if (Pwm.DutyCycle_Uint8 > temp)      {
                    Pwm.DutyCycle_Uint8 = Pwm.DutyCycle_Uint8 - temp;
                } else {
                    Pwm.DutyCycle_Uint8 = 0;
                }
            } else {
                return;
            }
        } else {         //如果当前电压小于输出电压
            if ((UKTemp - ADPool.Value_Uint16[UPWMADCH]) > UDELTA) {
                temp = UKTemp - ADPool.Value_Uint16[UPWMADCH];
                temp = temp / 4;  //上升处理不要超调，所以每次只+一半

                if ((255 - Pwm.DutyCycle_Uint8) > temp) {
                    Pwm.DutyCycle_Uint8 += (temp / 2);
                } else {
                    Pwm.DutyCycle_Uint8 = 255;
                }
            } else {
                return;
            }
        }

        DisPlayVoltage();
        PWMChangeDuty(Pwm.DutyCycle_Uint8);  //改变占空比
        Delay(10, 10);
    }
}

