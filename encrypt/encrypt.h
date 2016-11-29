/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file encrypt.h
 *
 * 对称加密算法实现
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _ENCRYPT_H_
#define _ENCRYPT_H_

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;

void encrypt_epri(uint8_t* in, uint16_t in_len, uint8_t* out, uint16_t &out_len);
void init_sn(uint8_t sr);

#endif /* _ENCRYPT_H_ */

