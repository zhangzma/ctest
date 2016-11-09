// eva_std.h
// Copyright (c) 2015 www.bjfz.com. All rights reserved.

#ifndef _EVA_STD_H_
#define _EVA_STD_H_

#define __EXPORT

#ifndef EVA_EXTERN
#define EVA_EXTERN 
#endif  /* EVA_EXTERN */


#ifndef EVA_API
#define EVA_API __EXPORT
#endif /* EVA_API */

// #include <string>
#include <stdio.h>
namespace eva
{

extern "C" void* ii_memmove(void *io_pDst, const void *i_pSrc, int i_nLen);
extern "C" char* ii_strncpy(char *io_pDst, const char *i_pSrc, int i_nLen);



// =============================================================================
// 互斥信号量
// -----------------------------------------------------------------------------
struct sii_mutex_private;

EVA_EXTERN class EVA_API Mutex
{
public:
    Mutex();
    virtual ~Mutex();

    bool try_lock();
    void lock();
    void unlock();
private:
    sii_mutex_private *m_pmutexPrivate;
};

// =============================================================================
// 字符串处理类
// -----------------------------------------------------------------------------
EVA_EXTERN class EVA_API String
{
    // 重载操作符"+"号
	friend EVA_API String operator + (const String& i_ysStr1, const String& i_ysStr2);
	friend EVA_API String operator + (const String& i_ysStr, const char* i_pStr);
	friend EVA_API String operator + (const char *i_pStr, const String& i_ysStr);
	friend EVA_API String operator + (const String& i_ysStr, char i_mChar);
	friend EVA_API String operator + (char i_mChar, const String& i_ysStr);

protected:
	bool AddNum(int i_nNumAdd);

public:
	//构造函数及析构函数
	String();
	String(int i_nInitSize);
	String(char i_mChar, int i_nCount);
	String(const char* i_pStr);
	String(const String& i_ysStr);	//复制构造函数
	~String();

	bool AddSize(int i_nSizeAdd);		//增加缓冲区大小
	bool SetSize(int i_nSize);			//设置缓冲区大小

	const char* GetBuf() const;	//获取字符串指针
	int GetLength() const;	//获取字符串长度
	bool IsEmpty() const;	//是否为空

	void ToUpper();		//全部转换为大写形式
	void ToLower();		//全部转换为小写形式
	void ToReverse();	//全部转换为相反形式

	String Left(int i_len) const;	//从字符串左开始向右取len长度的字符串
	String Right(int i_len) const;	//从字符串右开始向左取len长度的字符串
	String Mid(int i_index, int i_len=-1) const; //从字符串中index处开始向右取len长度的字符串
	void TrimLeft();
	void TrimRight();
	void TrimAll();

	char GetChar(int i_nIndex) const;
	char& GetChar(int i_nIndex);

	char operator[](int i_nIndex) const;
	char& operator[](int i_nIndex);

	int ToInt();		//将字符串转换为整型数
	double ToReal();	//将字符串转换为浮点数

	//在index处插入字符串s
	bool AddAt(int i_nIndex, const char *i_pStr);
	//从index处开始删除长度为len的字符串
	bool RemoveAt(int i_nIndex, int i_nLen);
	//在index处用字符串s代替长度为len的字符串
	bool ReplaceAt(int i_nIndex, int i_nLen, const char *i_pStr);

	void Empty();	//清空
	void FreeExtra();				//清掉多余内存

	//从Index处开始搜索第num次出现字符串s的位置
	int Find(const char *i_pStr, int i_nNum=1, int i_nIndex=0) const;
	//从Index处开始不区分大小写搜索第num次出现字符串s的位置
	int FindNoCase(const char *i_pStr, int i_nNum=1, int i_nIndex=0) const;
	//从index处开始总共有出现字符串s的个数
	int GetStrCount(const char *i_pStr, int i_nIndex=0) const;
	//从index处开始不区分大小写总共有出现字符串s的个数
	int GetStrCountNoCase(const char *i_pStr, int i_nIndex=0) const;

	int ReplaceFind(const char *i_pSrc, const char *i_pDst, int i_nIndex=0);

	String& Format(const char *i_pFormat, ...);		//格式化字符串

	//重载操作符"="号
	String& operator = (const String& i_ysStr);
	String& operator = (const char* i_pStr);
	String& operator = (char i_mChar);

	//重载操作符"+="号
	String& operator += (const String& i_ysStr);
	String& operator += (const char* i_pStr);
	String& operator += (char i_mChar);

	//重载判断操作符号
	bool operator == (const char* i_pStr);
	bool operator == (const String& i_ysStr);
	bool operator != (const char* i_pStr);
	bool operator != (const String& i_ysStr);
	bool operator >= (const char* i_pStr);
	bool operator >= (const String& i_ysStr);
	bool operator <= (const char* i_pStr);
	bool operator <= (const String& i_ysStr);
	bool operator >  (const char* i_pStr);
	bool operator >  (const String& i_ysStr);
	bool operator <  (const char* i_pStr);
	bool operator <  (const String& i_ysStr);

private:
	char  *m_pBuf;	//字符串指针
	int   m_nLen;
	int   m_nSize;		//缓冲区长度
};
    

// =============================================================================
// 文件处理类
// -----------------------------------------------------------------------------
#define EVA_IO_BINARY           0x01
#define EVA_IO_CREATE           0x02
#define EVA_IO_APPEND           0x00
#define EVA_IO_TRUNCATE         0x04
#define EVA_IO_READONLY         0x08
#define EVA_IO_WRITEONLY        0x10
#define EVA_IO_READWRITE        0x18

#define EVA_IO_BEGIN            0x01
#define EVA_IO_END              0x02
#define EVA_IO_CURRENT          0x03

EVA_EXTERN class EVA_API File
{
public:
    File();
    File(const char *file_name);
    virtual ~File();

    bool set_file_name(const char *file_name);   //
    eva::String get_file_name() const;           //

    bool open(const char *pmode); // 打开文件，字符串标识
    bool open(int nmode);       // 打开文件，比特标识
    void close();               // 关闭文件

    bool is_exist();            //
    int  get_length();          //
    int  read(char *pbuf, int count);
    int  write(const char *pbuf, int count);

    bool read_line(char *pbuf, int max_count);
    void write_line(const char *pbuf);

    bool seek(int off_set, int from);
    void seek_to_begin();
    void seek_to_end();

    bool rename(const char *new_name);
    bool remove();

private:
    FILE *m_pFile;
    String m_strFileName;
};


// =============================================================================
// 日志类
// -----------------------------------------------------------------------------
#define EVA_MAX_LOG_COUNT       2000

#define EVA_LOG_ERROR           1
#define EVA_LOG_WARNING         2
#define EVA_LOG_NORMAL          3

EVA_EXTERN class EVA_API Log
{
public:
    Log();
    Log(const char *proc_name);
    virtual ~Log();

    bool set_proc_name(const char *proc_name);
    bool add(const char *text);

protected:
    int  create_log_dir();
    bool get_log_time_utc_tt(struct tm *tt, bool boot_time);

private:
    Mutex       m_mutex;
    File        m_file;
    eva::String m_strProcName;
};

}


#endif /* _EVA_STD_H_ */
