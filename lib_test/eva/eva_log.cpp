// eva_log.cpp
// Copyright (c) 2015 www.bjfz.com. All rights reserved.

#include "eva_std.hpp"
#include <sys/stat.h>
#include <errno.h>
#include <cstdlib>
#include <cstring>

namespace eva
{
#define MOUNT_POINT "/fs/microsd"
static const char *inf_root = MOUNT_POINT  "/inf";

Log::Log()
{

}

Log::Log(const char *proc_name)
{
    set_proc_name(proc_name);
}

Log::~Log()
{
}

bool Log::set_proc_name(const char *proc_name)
{
    if (proc_name == NULL) {
        return false;
    }
    else {
        create_log_dir();
        eva::String inf_file(inf_root);
        inf_file      += "/";
        inf_file      += proc_name;
        m_strProcName  = inf_file.GetBuf();
        inf_file      += ".inf";
        m_file.set_file_name(inf_file.GetBuf());

        return true;
    }
}

bool Log::add(const char *text)
{
    char t_szCount[16];
    int  t_nCount;
    bool need_create = true;

    eva::String stmp;
    eva::String msg;

    // 
    eva::String tFileName = m_file.get_file_name();
    if (tFileName.IsEmpty()) {
        return false;
    }

    m_mutex.lock();
    if (m_file.open("r+")) {
        // read the record count.
        m_file.read(t_szCount, 6);
        t_szCount[6] = 0;
        t_nCount     = atoi(t_szCount);

        // the back file is exist? delete the old back, rename the .inf to .bak.
        if (t_nCount >= EVA_MAX_LOG_COUNT) {
            eva::String tStr = m_strProcName;
            tStr += ".bak";
            File tFile(tStr.GetBuf());
            if (tFile.is_exist()) {
                tFile.remove();
            }
            m_file.rename(tStr.GetBuf());
            m_file.close();
            need_create = true;
        }
        else {
            need_create = false;
            t_nCount++;
            sprintf(t_szCount, "%04d\n", t_nCount);
        }
    }

    if (need_create) {
        eva::String tStr = m_strProcName;
        tStr += ".inf";
        m_file.set_file_name(tStr.GetBuf());
        if (m_file.open("w+")) {
            t_nCount = 1;
            sprintf(t_szCount, "%04d\n", t_nCount);
        }
        else {
            m_mutex.unlock();
            return false;
        }
    }

    m_file.seek_to_begin();
    m_file.write((char*)&t_szCount, strlen(t_szCount));

    sprintf(t_szCount, "%03d", t_nCount);
    msg = t_szCount;
    msg += " ";

    std::struct tm timeinfo;
    get_log_time_utc_tt(&timeinfo, true);
    char szTime[20];
    strftime(szTime, 20, "%Y-%m-%d %H:%M:%S", &timeinfo);
    msg += "<";
    msg += szTime;
    msg += ">";
    msg += " ";

    msg += text;
    msg += "\n";
    m_file.seek_to_end();
    m_file.write(msg.GetBuf(), msg.GetLength());
    m_file.close();

    m_mutex.unlock();
    return true;
}

/**
 * Create the Log dir.
 * @return
 */
int Log::create_log_dir()
{
    // created dir on sdcard if needed.
    int mkdir_ret;
    static char log_dir[32];

    snprintf(log_dir, sizeof(log_dir), "%s", inf_root);
    mkdir_ret = mkdir(log_dir, S_IRWXU | S_IRWXG | S_IRWXO);

    if ((mkdir_ret != OK) && (errno != EEXIST)) {
        warn("Log: >>>failed creating new dir: %s", log_dir);
        return -1;
    }

    return 0;
}

/**
 * Get the utc time
 * @param tt        --
 * @param boot_time --
 * @return
 */
bool Log::get_log_time_utc_tt(struct tm *tt, bool boot_time)
{
    (void)boot_time;
    time_t rawtime;
    time(&rawtime);

    gmtime_r(&rawtime, tt);
    return (tt != NULL);
}

}

