/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _MAIN_C_
#include <stdio.h>
#include <stdlib.h>

/* typedef unsigned long  uint64_t; */
typedef unsigned int   uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;


typedef union {
    /* double   dval; */
    float    fval;
    uint32_t ival;
    uint8_t  cval[4];
} type_def;

typedef struct _gps_raw_int_t
{
    uint64_t time_us;
    uint32_t lat;
    uint32_t lon;
    /* .... */
}gps_raw_int_t;

void print_hex(uint8_t *buffer, uint32_t size);


int main(int argc, char *argv[])
{
    type_def tval;
    uint32_t lat_int;
    double lat = 12345.1234567;
    double lat_tmp;
    printf("lat = %f\n", lat);
    
    lat_tmp = lat * 1e4;
    printf("lat_tmp = %f\n", lat_tmp);
    lat_int = (uint32_t)(lat_tmp);
    printf("lat_int = %d\n", lat_int);

    printf("sizeof(type_def) = %d\n", sizeof(type_def));

    uint8_t buffer[130] = {0x00};
    gps_raw_int_t *pgps_raw = (gps_raw_int_t*)(buffer+3);
    pgps_raw->lat = lat_int;
    pgps_raw->lon = lat_int;
    
    /*  */
    tval.ival = lat_int;
    print_hex(tval.cval, 4);

    double lat_tmp2 = lat_int * 1e-4;
    printf("lat_tmp2 = %f\n", lat_tmp2);
    
    /* print_hex(buffer, 50); */


    return 0;
}

void print_hex(uint8_t *buffer, uint32_t size)
{
    for (uint32_t i = 0; i < size; i++) {
        printf("%02X ", buffer[i]);
    }

}

