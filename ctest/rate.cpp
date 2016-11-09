// rate.cc

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <ctime>

/** info buffer len. */
const int BUF_LEN = 100;
char buf[BUF_LEN];

void clear_buff()
{
    memset(buf, 0, BUF_LEN);
}

/**
 * Set the process's Name.
 * @param pName -- process's name.
 */
void set_process_name(const char* pName)
{
    clear_buff();
    memcpy(buf, pName, strlen(pName));
    char *phead = buf + strlen(pName);

    *phead++ = ':';
    *phead++ = '[';
    for (int i=0; i<20; i++) {
        *phead++ = ' ';
    }
    *phead++ = ']';
    *phead++ = ' ';

    char zeroStr[10];
    sprintf(zeroStr, "%3.1f%%", 0.0/100);

    memcpy(phead, zeroStr, strlen(zeroStr));
}

/**
 * Update the processing.
 *
 * @param total -- the total step.
 * @param step  -- current step.
 */
void update(int total, int step)
{
    char *phead = buf;
    while (*phead++ != '[');
    float rate = (step * 100.0) / total;
    float rateCount = rate / 5;

    for (int i = 0; i < rateCount; i++) {
        *phead++ = '=';
    }

    while (*phead++ != ']');
    phead++;
    char rateStr[10];
    sprintf(rateStr, "%3.1f%%", rate);
    memcpy(phead, rateStr, strlen(rateStr));
}

int main(int argc, char *argv[])
{
    set_process_name(argv[0]);
    std::cout << buf;

    const int total = 10;
    for (int cnt = 0; cnt <= total; cnt++) {
        update(total, cnt);
        std::cout << "\r" << buf;
        fflush(stdout);

        static time_t tm = time(NULL);
        while (tm == time(NULL));
        tm = time(NULL);

    }
    std::cout << std::endl;
    std::cout << argv[0] << " OK !" << std::endl;
    // update(total, total);

    return 0;
}
