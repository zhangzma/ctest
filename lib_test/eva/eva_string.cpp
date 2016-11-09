// eva_string.cpp

#include "eva_std.hpp"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

namespace eva {

#define isupper(c) \
    ((c) >= 'A' && (c) <= 'Z')

/****************************************************************************
 * Name: toupper
 *
 * Description:
 *   toupper() converts the letter c to upper case, if possible.
 *
 ****************************************************************************/

#define toupper(c) \
  (((c) >= 'a' && (c) <= 'z') ? ((c) - 'a' + 'A') : (c))

/****************************************************************************
 * Name: tolower
 *
 * Description:
 *   tolower() converts the letter c to lower case, if possible.
 *
 ****************************************************************************/

#define tolower(c) \
  (((c) >= 'A' && (c) <= 'Z') ? ((c) - 'A' + 'a') : (c))

// 安全内存移动函数
void* ii_memmove(void *io_pDst, const void *i_pSrc, int i_nLen)
{
    register char *d;
    register char *s;

    if (io_pDst > i_pSrc)
	{
		d = (char*)io_pDst + i_nLen - 1;
		s = (char*)i_pSrc + i_nLen - 1;
		while (i_nLen--) *d-- = *s--;
    }
	else if (io_pDst < i_pSrc)
	{
		d = (char*)io_pDst;
		s = (char*)i_pSrc;
		while (i_nLen--) *d++ = *s++;
    }
    return io_pDst;
}

// 字符串拷贝函数，解决len小于src字符串长度的情况
char* ii_strncpy(char *io_pDst, const char *i_pSrc, int i_nLen)
{
    if (!i_pSrc) return 0;

    strncpy(io_pDst, i_pSrc, i_nLen);
    if (i_nLen > 0)
		io_pDst[i_nLen] = '\0';

    return io_pDst;
}

String::String()
{
	m_pBuf  = new char[1];
	*m_pBuf = '\0';
	m_nLen  = 0;
	m_nSize = 1;
}

String::String(char i_mChar, int i_nCount)
{
	int t_nCount = 0;

	if (i_nCount <= 1)
		t_nCount = 1;
	else
		t_nCount = i_nCount;

	m_pBuf = new char[t_nCount+1];

	for (int i= 0; i< t_nCount; ++i)
		*(m_pBuf+i) = i_mChar;

	*(m_pBuf + t_nCount) = '\0';
	m_nLen = t_nCount;
	m_nSize = t_nCount+1;
}

String::String(const char* i_pStr)
{
	if (i_pStr == NULL)
	{
		m_pBuf = new char[1];
		*m_pBuf = '\0';
		m_nLen = 0;
		m_nSize = 1;
		return;
	}
	m_pBuf = new char[strlen(i_pStr) + 1];
	assert(m_pBuf != NULL);

	strcpy(m_pBuf, i_pStr);
	m_nLen = strlen(i_pStr);
	m_nSize = m_nLen + 1;
}

String::String(const String& i_ysStr)
{
	int n = i_ysStr.GetLength();

	m_pBuf = new char[n+1];
	assert(m_pBuf != NULL);

	strcpy(m_pBuf, i_ysStr.m_pBuf);
	m_nLen = n;
	m_nSize = n+1;
}

String::String(int i_nInitSize)
{
	int tLen = i_nInitSize;

	if (i_nInitSize < 1)
		tLen = 1;
	
	m_pBuf = new char[tLen];
	assert(m_pBuf != NULL);

	*m_pBuf = '\0';
	m_nLen = 0;
	m_nSize = tLen;
}

String::~String()
{
	if (m_pBuf != NULL)
		delete []m_pBuf;
}

const char* String::GetBuf() const	// 获取字符串指针
{
	return m_pBuf;
}

int String::GetLength() const	// 获取字符串长度
{
	return m_nLen;
}

bool String::IsEmpty() const	// 是否为空
{
	return m_nLen<=0;
}

bool String::AddNum(int i_nNumAdd)
{
	char *temp = NULL;
	int t_nNum = 0;

	if (i_nNumAdd == 0)
		return true;

	t_nNum = m_nLen + i_nNumAdd;		// 改变后的个数

	if (t_nNum >= m_nSize)	// 需重新分配内存
	{
		temp = new char[t_nNum + 1];
		if (temp == NULL)
			return false;

		memset(temp, 0, t_nNum+1);
		memcpy(temp, m_pBuf, m_nLen);

		if (t_nNum > m_nLen)
			m_nLen = t_nNum;

		m_nSize = t_nNum + 1;

		delete []m_pBuf;
		m_pBuf = temp;
	}
	else	// 内存够用
	{
		m_nLen = t_nNum;
		*(m_pBuf + m_nLen) = 0;
	}

	return true;
}

bool String::AddSize(int i_nSizeAdd)
{
	char *temp = NULL;
	int t_nSize = 0;

	t_nSize = m_nSize + i_nSizeAdd;
	
	if (t_nSize < 0)
		t_nSize = 0;

	temp = new char[t_nSize + 1];
	if(temp == NULL)
		return false;

	memset(temp, 0, t_nSize + 1);

	if (i_nSizeAdd > 0)
		memcpy(temp, m_pBuf, m_nLen);
	else
		memcpy(temp, m_pBuf, t_nSize);

	delete []m_pBuf;
	m_pBuf = temp;

	if (m_nLen > t_nSize)
	{
		m_nLen = t_nSize;
		m_pBuf[t_nSize - 1] = '\0';
	}
	m_nSize = t_nSize;

	return true;
}

// 设置缓冲区大小
bool String::SetSize(int i_nSize)
{
	if (i_nSize < 1)
		i_nSize = 1;

	return AddSize(i_nSize - m_nSize);
}

void String::Empty()	// 清空
{
	if (m_pBuf != NULL)
	{
		m_nLen = 0;
		*m_pBuf = '\0';
	}
	else
	{
		m_pBuf = new char[1];
		*m_pBuf = '\0';
		m_nLen = 0;
		m_nSize = 1;
	}
}

void String::FreeExtra()				// 清掉多余内存
{
	AddSize(m_nLen-m_nSize+1);
}

String operator+ (const String& i_ysStr1, const String& i_ysStr2)
{
	String mTempStr(i_ysStr1);
	mTempStr += i_ysStr2;

	return mTempStr;
}

String operator+ (const String& i_ysStr, const char *i_pStr)
{
	if (i_pStr == NULL)
		return i_ysStr;
		
	String mTempStr(i_ysStr);
	mTempStr += i_pStr;

	return mTempStr;
}

String operator+ (const char *i_pStr, const String& i_ysStr)
{
	if (i_pStr == NULL)
		return i_ysStr;

	String mTempStr(i_pStr);
	mTempStr += i_ysStr;

	return mTempStr;
}

String operator+ (const String& i_ysStr, char i_mChar)
{
	String mTempStr(i_ysStr);
	mTempStr += i_mChar;

	return mTempStr;
}

String operator+ (char i_mChar, const String& i_ysStr)
{
	String mTempStr(i_mChar);
	mTempStr += i_ysStr;

	return mTempStr;
}

String& String::operator= (const String& i_ysStr)
{
	Empty();					// 先清空
	AddNum(i_ysStr.m_nLen);
	strcpy(m_pBuf, i_ysStr.m_pBuf);

	return *this;
}

String& String::operator= (const char* i_pStr)
{
	if (i_pStr != NULL)
	{
		Empty();					// 先清空
		AddNum(strlen(i_pStr));
		strcpy(m_pBuf, i_pStr);
	}
	return *this;
}

String& String::operator= (char i_mChar)
{
	char tmp[2];

	tmp[0] = i_mChar;
	tmp[1] = 0;

	Empty();					// 先清空
	AddNum(1);
	strcpy(m_pBuf, tmp);

	return *this;
}

String& String::operator+= (const String& i_ysStr)
{
	AddNum(i_ysStr.m_nLen);
	strcat(m_pBuf, i_ysStr.GetBuf());

	return *this;
}

String& String::operator+= (const char* i_pStr)
{
	if (i_pStr != NULL)
	{
		AddNum(strlen(i_pStr));
		strcat(m_pBuf, i_pStr);
	}
	return *this;
}

String& String::operator+= (char i_mChar)
{
	char tmp[2];

	tmp[0] = i_mChar;
	tmp[1] = 0;

	AddNum(1);
	strcat(m_pBuf, tmp);

	return *this;
}

void String::ToUpper()
{
	for (int i = 0; i < m_nLen; ++i)
	{
		if (*(m_pBuf+i) > 0)
			*(m_pBuf+i) = toupper(*(m_pBuf+i));
	}
}

void String::ToLower()
{
	for (int i= 0; i< m_nLen; ++i)
	{
		if (*(m_pBuf + i) > 0)
		*(m_pBuf + i) = tolower(*(m_pBuf+i));
	}
}

void String::ToReverse()
{
	for (int i= 0; i< m_nLen; ++i)
	{
		if (*(m_pBuf+i) > 0)
		{
			if (!isupper(*(m_pBuf+i)))
				*(m_pBuf+i) = toupper(*(m_pBuf+i));
			else
				*(m_pBuf+i) = tolower(*(m_pBuf+i));
		}
	}
}

bool String::AddAt(int i_nIndex, const char *i_pStr)
{
	if (i_pStr == NULL)
		return false;

	int len = strlen(i_pStr);
	int oldLen = m_nLen;

	if (i_nIndex > m_nLen || i_nIndex < 0)
		return false;

	AddNum(len);

	ii_memmove(m_pBuf + i_nIndex + len, m_pBuf + i_nIndex, oldLen - i_nIndex + 1);
	memcpy(m_pBuf + i_nIndex, i_pStr, len);

	return true;
}

bool String::RemoveAt(int i_nIndex, int i_nLen)
{
	if (i_nLen <= 0)
		return true;

	if (i_nIndex > m_nLen-1 || i_nIndex < 0 || i_nLen > m_nLen-i_nIndex)
		return false;

	ii_memmove(m_pBuf + i_nIndex, m_pBuf + i_nIndex + i_nLen, m_nLen - i_nIndex - i_nLen);
	AddNum(-i_nLen);

	return true;
}

bool String::ReplaceAt(int i_nIndex, int i_nLen, const char *i_pStr)
{
	if (i_pStr == NULL)
		return false;

	if (!RemoveAt(i_nIndex, i_nLen) || !AddAt(i_nIndex, i_pStr))
		return false;

	return true;
}

int	String::Find(const char *i_pStr, int i_nNum, int i_nIndex) const
{
	if (i_pStr == NULL)
		return -1;

	char *pos = NULL, *oldPos = NULL;

	if (i_nIndex > m_nLen -1 || i_nIndex < 0)
		return -1;

	oldPos = m_pBuf + i_nIndex;

	for (int i= 0; i< i_nNum; ++i)
	{
		pos = strstr(oldPos, i_pStr);

		if (pos == NULL)
			return -2;

		oldPos = pos + strlen(i_pStr);
	}

	return (int)(pos -m_pBuf);
}

int	String::FindNoCase(const char *i_pStr, int i_nNum, int i_nIndex) const
{
	if (i_pStr == NULL)
		return -1;

	String tSourceStr, tFindStr;

	tSourceStr = *this;
	tSourceStr.ToUpper();

	tFindStr = i_pStr;
	tFindStr.ToUpper();

	return tSourceStr.Find(tFindStr.GetBuf(), i_nNum, i_nIndex);
}

int String::GetStrCount(const char *i_pStr, int i_nIndex) const
{
	if (i_pStr == NULL)
		return 0;

	int   count = 0;
	char  *pos = NULL, *oldPos = NULL;

	oldPos = m_pBuf + i_nIndex;

	for (;;)
	{
		pos = strstr(oldPos, i_pStr);

		if (pos == NULL)
			break;

		count++;
		oldPos = pos + strlen(i_pStr);
	}
	return count;
}

int String::GetStrCountNoCase(const char *i_pStr, int i_nIndex) const
{
	if (i_pStr == NULL)
		return 0;

	String tSourceStr, tCountStr;

	tSourceStr = *this;
	tSourceStr.ToUpper();

	tCountStr = i_pStr;
	tCountStr.ToUpper();

	return tSourceStr.GetStrCount(tCountStr.GetBuf(), i_nIndex);
}

int String::ReplaceFind(const char *i_pSrc, const char *i_pDst, int i_nIndex)
{
	if (i_pSrc == NULL || i_pDst == NULL)
		return false;

	int   count = 0;
	int	tOldPos = 0;
	char  *pos = NULL;//, *oldPos = NULL;
	// oldPos = m_pBuf + i_nIndex;
	int tSrcLen = strlen(i_pSrc);
	int tDstLen = strlen(i_pDst);

	for (;;)
	{
		pos = strstr(m_pBuf + tOldPos, i_pSrc);

		if (pos == NULL)
			break;

		count++;
		tOldPos = pos + tDstLen - m_pBuf;
		ReplaceAt(pos-m_pBuf, tSrcLen, i_pDst);
	}
	return count;
}

String& String::Format(const char *i_pFormat, ...)
{
	if (i_pFormat == NULL)
		return *this;

	va_list ap;
	va_start(ap, i_pFormat);

	SetSize(256);
	vsprintf(m_pBuf, i_pFormat, ap);
	SetSize(strlen(m_pBuf)+1);

	m_nLen = strlen(m_pBuf);		// 设置长度

	va_end(ap);

	return *this;
}

int String::ToInt()
{
	return atoi(m_pBuf);
}

double String::ToReal()
{
	return atof(m_pBuf);
}

String String::Left(int i_nLen) const
{
	int t_nLen = 0;
	String str;
	char *buf;

	if (i_nLen <= 0)
		return str;
	else if (i_nLen > m_nLen)
		t_nLen = m_nLen;
	else
		t_nLen = i_nLen;

	buf = new char[t_nLen + 1];
	ii_strncpy(buf, m_pBuf, t_nLen);
	str = buf;

	delete []buf;
	return str;
}

String String::Right(int i_nLen) const
{
	int t_nLen = 0;
	String str;
	char *buf;

	if (i_nLen <= 0)
		return str;
	else if (i_nLen > m_nLen)
		t_nLen = m_nLen;
	else
		t_nLen = i_nLen;

	buf = new char[t_nLen + 1];
	ii_strncpy(buf, m_pBuf + m_nLen - t_nLen, t_nLen);
	str = buf;

	delete []buf;
	return str;
}

String String::Mid(int i_nIndex, int i_nLen) const
{
	int t_nLen = 0;
	String str;
	char *buf;

	if (i_nIndex < 0 || i_nIndex >= m_nLen || i_nLen == 0)
		return str;

	if (i_nLen == -1 || i_nLen > m_nLen - i_nIndex + 1)
		t_nLen = m_nLen - i_nIndex + 1;
	else
		t_nLen = i_nLen;

	buf = new char[t_nLen + 1];
	ii_strncpy(buf, m_pBuf + i_nIndex, t_nLen);
	str = buf;

	delete []buf;
	return str;
}

void String::TrimLeft()
{
	int tCount = 0;
	// 去除开始的空格
	for (int i= 0; i< m_nLen; ++i)
	{
		if (*(m_pBuf+i) == ' ' || *(m_pBuf+i) == '\n' || *(m_pBuf+i) == '\t' || *(m_pBuf+i) == '\r')
			++tCount;
		else
			break;
	}
	if (tCount > 0)
		RemoveAt(0, tCount);
}

void String::TrimRight()
{
	// 去除结尾的空格
	for (int j= m_nLen-1; j> 0; j--)
	{
		if (*(m_pBuf+j) == ' ' || *(m_pBuf+j) == '\n' || *(m_pBuf+j) == '\t' || *(m_pBuf+j) == '\r')
		{
			*(m_pBuf + j) = 0;
			m_nLen --;
		}
		else
			break;
	}
}

void String::TrimAll()
{
	int tCount = 0;
	// 去除开始的空格
	for (int i= 0; i< m_nLen; ++i)
	{
		if (*(m_pBuf+i) == ' ' || *(m_pBuf+i) == '\n' || *(m_pBuf+i) == '\t' || *(m_pBuf+i) == '\r')
			++tCount;
		else
			break;
	}
	if (tCount > 0)
		RemoveAt(0, tCount);

	// 去除结尾的空格
	for (int j= m_nLen-1; j> 0; --j)
	{
		if (*(m_pBuf+j) == ' ' || *(m_pBuf+j) == '\n' || *(m_pBuf+j) == '\t' || *(m_pBuf+j) == '\r')
		{
			*(m_pBuf + j) = 0;
			m_nLen --;
		}
		else
			break;
	}
}

char String::GetChar(int i_nIndex) const
{
	char tChar;

//	if (i_nIndex < 0)	// EMS-Mend< baizy 2008.1.28
	if (i_nIndex <= 0)
		i_nIndex = 0;
	else if (i_nIndex >= m_nLen-1)
		i_nIndex = m_nLen -1;

	tChar = *(m_pBuf + i_nIndex);

	return tChar;
}

char& String::GetChar(int i_nIndex)
{
//	if (i_nIndex < 0)	// EMS-Mend< baizy 2008.1.28
	if (i_nIndex <= 0)
		i_nIndex = 0;
	else if (i_nIndex >= m_nLen-1)
		i_nIndex = m_nLen -1;

	return *(m_pBuf + i_nIndex);
}

char String::operator[](int i_nIndex) const
{
	return GetChar(i_nIndex);
}

char& String::operator[](int i_nIndex)
{
	return GetChar(i_nIndex);
}

// 重载判断操作符号
bool String::operator == (const char* i_pStr)
{
	if (i_pStr == NULL)
		return false;
	return (strcmp(m_pBuf, i_pStr) == 0);
}

bool String::operator == (const String& i_ysStr)
{
	return (strcmp(m_pBuf, i_ysStr.GetBuf()) == 0);
}

bool String::operator != (const char* i_pStr)
{
	if (i_pStr == NULL)
		return true;
	return (strcmp(m_pBuf, i_pStr) != 0);
}

bool String::operator != (const String& i_ysStr)
{
	return (strcmp(m_pBuf, i_ysStr.GetBuf()) != 0);
}

bool String::operator >= (const char* i_pStr)
{
	if (i_pStr == NULL)
		return true;
	return (strcmp(m_pBuf, i_pStr) >= 0);
}

bool String::operator >= (const String& i_ysStr)
{
	return (strcmp(m_pBuf, i_ysStr.GetBuf()) >= 0);
}

bool String::operator <= (const char* i_pStr)
{
	if (i_pStr == NULL)
		return false;
	return (strcmp(m_pBuf, i_pStr) <= 0);
}

bool String::operator <= (const String& i_ysStr)
{
	return (strcmp(m_pBuf, i_ysStr.GetBuf()) <= 0);
}

bool String::operator >  (const char* i_pStr)
{
	if (i_pStr == NULL)
		return true;
	return (strcmp(m_pBuf, i_pStr) > 0);
}

bool String::operator >  (const String& i_ysStr)
{
	return (strcmp(m_pBuf, i_ysStr.GetBuf()) > 0);
}

bool String::operator <  (const char* i_pStr)
{
	if (i_pStr == NULL)
		return false;
	return (strcmp(m_pBuf, i_pStr) < 0);
}

bool String::operator <  (const String& i_ysStr)
{
	return (strcmp(m_pBuf, i_ysStr.GetBuf()) < 0);
}

}

