/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file log_define.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _LOG_DEFINE_H_
#define _LOG_DEFINE_H_
#include <time.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


#define _LOG_WRITE_STATE_ 1

#define LOG_SUCCESS    (0)  
#define LOG_FAILED     (-1)  
#define LOG_BOOL_TRUE  (1)  
#define LOG_BOOL_FALSE (0)  
  
  
#define MAX_LOGTEXT_LEN       (2048) /* 每行日志的最大长度*/  
#define MAX_FILE_PATH         (255) /* 日志文件路径的最大长度*/  
#define MAX_LOG_FILE_SIZE     (512 * 1024) /* 日志文件内容的最大长度*/  
#define MAX_LOG_FILE_NAME_LEN (256) /* 日志文件名的最大长度*/  
  
#define TEST_CASE_MAX_FILE_LEN (1024)   /* 测试函数中文件内容最大长度*/  

typedef enum LOG_TYPE {
    LOG_TYPE_DEBUG = 0,
    LOG_TYPE_SYSTEM,
    LOG_TYPE_OPRATE,
} log_type_t;

typedef enum LOG_LEVEL {
    I_LVL_INFO = 0,
    I_LVL_DEBUG,
    I_LVL_WARNING,
    I_LVL_ERROR,
} log_level_t;

typedef struct tagLOG_DATA {    /* 日志内容结构体*/
    char       strDate[11];     /* 日期:格式为如:2009-10-11*/
    char       strTime[9];      /* 时间:格式为如:16:10:57*/
    log_type_t iType;           /* 日志类型:3种:INFO(0)/ERROR(1)/SYSTEM(2)*/
    char       strText[MAX_LOGTEXT_LEN]; /*日志内容*/
}LOG_DATA, *PLOG_DATA;

/*********************************************************************
* 函数名称:int Write_Log_Text(LPLOG_DATA lpLogData)
* 说明:写日志内容
* 调用者：Write_Log
* 输入参数:
* LPLOG_DATA lpLogData --日志内容结构体量
* 输出参数：
* 无
* 返回值:
* int -- LOG_FAILED: 失败
*      -- LOG_SUCCESS: 成功
*********************************************************************/
int Write_Log_Text(const LOG_DATA &data)
{
#if 1
    printf("<%s %s> %s\n", data.strDate, data.strTime, data.strText);

#else
    char  szFilePath[MAX_FILE_PATH];
    char  szFileName[MAX_LOG_FILE_NAME_LEN];
    FILE * pFile = NULL;
    char  szLogText[MAX_LOGTEXT_LEN];

    memset(szFilePath, 0, MAX_FILE_PATH);
    memset(szFileName, 0, MAX_LOG_FILE_NAME_LEN);
    memset(szLogText, 0, MAX_LOGTEXT_LEN);

    GetLogPath(szFilePath);
    GetLogFileName(lpLogData->iType, szFilePath, szFileName);
    pFile = fopen(szFileName, "a+");

    if (NULL == pFile) {
        return LOG_FAILED;
    }

    sprintf(szLogText, "%s %s %s\n", lpLogData->strDate, lpLogData->strTime, lpLogData->strText);
    fwrite(szLogText, 1, strlen(szLogText), pFile);
    fclose(pFile);
#endif

    return LOG_SUCCESS;
}


/*********************************************************************
* 函数名称:void Write_Log(unsigned int uiLogType, char *pstrFmt, ...)
* 说明:日志写函数，支持变长参数
* 调用者：任何需要写日志的地方
* 输入参数:
* unsigned iType -- 日志类别
* char *pstrFmt -- 日志内容
* ...            -- 变长参数
* 输出参数：
* 无
* 返回值:
* void --
*********************************************************************/
void Write_Log(log_type_t uiLogType, const char * pstrFmt, ...)
{
#if _LOG_WRITE_STATE_   /* 写日志与否的编译开关*/
    LOG_DATA    data;
    time_t      curTime;
    struct tm * mt;
    va_list     v1;

    memset(&data, 0, sizeof(LOG_DATA));
    va_start(v1, pstrFmt);

    vsnprintf(data.strText, MAX_LOGTEXT_LEN, pstrFmt, v1);
    va_end(v1);

    data.iType = uiLogType;
    curTime = time(NULL);
    mt = localtime(&curTime);
    strftime(data.strDate, sizeof(data.strDate), "%Y-%m-%d", mt);
    strftime(data.strTime, sizeof(data.strTime), "%H:%M:%S", mt);
    Write_Log_Text(data);
#endif  // _LOG_WRITE_STATE_
}

#endif /* _LOG_DEFINE_H_ */
