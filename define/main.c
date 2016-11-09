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
#include <stdio.h>

#ifndef ENABLED
#define ENABLED    1
#define DISENABLED 0
#endif /* ENABLED */

#define NOS_ISR_ENABLE ENABLED

#define ISR_INT0_ENABLED   DISENABLED

#if (NOS_ISR_ENABLE==1 && ISR_INT0_ENABLED)
void isr_int0()
{
    printf("isr_init0 function.\n");
}
#else
void isr_int0()
{
}
#endif /* ISR_INT0_ENABLED */


int main(int argc, char *argv[])
{
    isr_int0();
    return 0;
}

