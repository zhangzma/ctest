// eva_mutex.cpp
// Copyright (c) 2015 www.bjfz.com. All rights reserved.

#include "eva_std.hpp"
#include <pthread.h>

namespace eva {
struct sii_mutex_private
{
    pthread_mutex_t m_mutex;
};    



eva::Mutex::Mutex()
{
    pthread_mutexattr_t tMutexAttr;
    m_pmutexPrivate = new sii_mutex_private;
    pthread_mutexattr_init(&tMutexAttr);
#ifdef CONFIG_MUTEX_TYPES
    pthread_mutexattr_settype(&tMutexAttr, PTHREAD_MUTEX_RECURSIVE);
#endif
    pthread_mutex_init(&m_pmutexPrivate->m_mutex, &tMutexAttr);

    pthread_mutexattr_destroy(&tMutexAttr);
}

eva::Mutex::~Mutex()
{
    pthread_mutex_destroy(&m_pmutexPrivate->m_mutex);
    delete m_pmutexPrivate;
}

bool eva::Mutex::try_lock()
{
    return (pthread_mutex_trylock(&m_pmutexPrivate->m_mutex));
}

void eva::Mutex::lock()
{
    pthread_mutex_lock(&m_pmutexPrivate->m_mutex);
}

void eva::Mutex::unlock()
{
    pthread_mutex_unlock(&m_pmutexPrivate->m_mutex);
}

}

