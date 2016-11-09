/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file ptl.h
 *
 * 规约解析头文件
 *
 * 
 *
 * @author zhanghb zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _PTL_H_
#define _PTL_H_

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;

const uint8_t FRM_HEADER = 0x59;


typedef struct _ptl_flags
{
    uint8_t *buf;
    uint16_t len;
}ptl_flags;

class IPtl
{
public:
    void ptl_recv();
    void ptl_send();
    void print_ptl();

    IPtl(ptl_flags &flags);
    virtual ~IPtl();

    enum PTL_STATUS{
        NO_SYNC = 0x00,
        SYNC,
        RECV_LEN,
    };

protected:
    virtual void check_frame_header() = 0;
    virtual void sync_frame_length()  = 0;
    virtual void parse_frame()        = 0;
    
protected:
    void    delete_no_use_data(uint8_t *buf, uint16_t &len, uint16_t count);
    uint8_t check_sum(uint8_t *buf, uint16_t len);
    void    print_hex(uint8_t *buf, uint16_t len);

    ptl_flags &_flags;
    PTL_STATUS _status;
};

#endif /* _PTL_H_ */

