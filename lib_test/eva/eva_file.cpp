// eva_file.cpp

#include "eva_std.hpp"
#include <string>
#include <unistd.h>
#include <cstdio>
#include <cstring>
using namespace std;

namespace eva
{

File::File()
{
    m_pFile = NULL;
}

File::File(const char *file_name)
{
    m_pFile = NULL;
    m_strFileName = file_name;
}

File::~File()
{
    if (m_pFile != NULL) {
        fclose(m_pFile);
        m_pFile = NULL;
    }
}

bool File::set_file_name(const char *file_name)
{
    if (file_name) {
        m_strFileName = file_name;
        return true;
    }

    return false;
}

eva::String File::get_file_name() const
{
    return m_strFileName;
}

/**
 * 打开文件
 * @param nMode -- 二进制格式
 * @return
 */
bool File::open(int nMode)
{
    bool bBinary = false;
    bool bRead   = false;
    bool bWrite  = false;
    bool bCreate = false;
    bool bEmpty  = false;

    std::string mode;
    if (nMode & EVA_IO_BINARY) {
        bBinary = true;
    }
    if (nMode & EVA_IO_CREATE) {
        bCreate = true;
    }
    if (nMode & EVA_IO_TRUNCATE) {
        bEmpty = true;
    }
    if (nMode & EVA_IO_READONLY) {
        bRead = true;
    }
    if (nMode & EVA_IO_WRITEONLY) {
        bWrite = true;
    }

    if (!bWrite && bRead) {
        mode = "r";
    }
    else if (!bRead && bWrite) {
        mode = "w";
    }
    else {
        if (!bCreate) {
            mode = "r+";
        }
        else {
            if (bEmpty) {
                mode = "w+";
            }
            else {
                mode = "a+";
            }
        }
    }
    if (bBinary) {
        mode += "b";
    }

    return this->open(mode.c_str());
}

bool File::open(const char *mode)
{
    m_pFile = fopen(m_strFileName.GetBuf(), mode);

    if (m_pFile == NULL) {
        return false;
    }

    return true;
}

void File::close()
{
    if (m_pFile != NULL) {
        fclose(m_pFile);
        m_pFile = NULL;
    }
}

bool File::is_exist()
{
    FILE * pfile = fopen(m_strFileName.GetBuf(), "r+");
    if (pfile != NULL) {
        fclose(pfile);
        return true;
    }
    else {
        return false;
    }
    // return (access(m_strFileName.c_str(), 0) != -1);
}

int File::get_length()
{
    int len    = 0;
    int oldPos = 0;
    if (m_pFile != NULL) {
        oldPos = ftell(m_pFile);
        if (fseek(m_pFile, 0, SEEK_END) != 0) {
            return -1;
        }
        len = ftell(m_pFile);
        fseek(m_pFile, oldPos, SEEK_SET);
    }
    else {
        // try {
            open("r");
            if (m_pFile == NULL) {
                return -1;
            }

            if (fseek(m_pFile, 0, SEEK_END) != NULL) {
                close();
                return -1;
            }
            len = ftell(m_pFile);
        // } catch (...) {
            // XXX: Deal the exception.
        // }
        m_pFile = NULL;
    }

    return len;
}

int File::read(char *pbuf, int count)
{
    if (m_pFile == NULL) {
        return -1;
    }

    size_t ret = fread(pbuf, 1, count, m_pFile);
    return (int)ret;
}

int File::write(const char *pbuf, int count)
{
    if (m_pFile == NULL) {
        return -1;
    }

    size_t ret = fwrite(pbuf, 1, count, m_pFile);
    return (int)ret;
}

bool File::read_line(char *pbuf, int count)
{
    if (m_pFile) {
        char *ret = fgets(pbuf, count, m_pFile);
        return (ret != NULL);
    }

    return false;
}

void File::write_line(const char *pbuf)
{
    if (m_pFile != NULL) {
        fputs(pbuf, m_pFile);
        fputs("\n", m_pFile);
    }
}

bool File::seek(int offset, int from)
{
    int mode;
    bool from_ok = true;
    switch (from) {
    case EVA_IO_BEGIN:
        mode = SEEK_SET;
        break;
    case EVA_IO_END:
        mode = SEEK_END;
        break;
    case EVA_IO_CURRENT:
        mode = SEEK_CUR;
        break;
    default:
        from_ok = false;
        break;
    }

    if (from_ok && !fseek(m_pFile, offset, mode)) {
        return true;
    }
    else {
        return false;
    }
}

void File::seek_to_begin()
{
    rewind(m_pFile);
}

void File::seek_to_end()
{
    seek(0, EVA_IO_END);
}

bool File::rename(const char *new_name)
{
    this->close();
    if (::rename(m_strFileName.GetBuf(), new_name) == 0) {
        m_strFileName = new_name;
        return true;
    }
    return false;
}

bool File::remove()
{
    this->close();
    if (::unlink(m_strFileName.GetBuf()) == 0) {
        m_strFileName.Empty();
        return true;
    }

    return false;
}

}
