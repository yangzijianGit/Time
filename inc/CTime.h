/***
 * @Author       : yangzijian
 * @Description  : Time
 * @Date         : 2021-01-25 15:22:55
 */
#pragma once

#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#include <winbase.h>
#endif

class CTime
{
public:
    static unsigned long long GetCurrentTimeMsec_TimeOfDay()
    {
#ifdef _WIN32
        struct timeval tv;
        time_t clock;
        struct tm tm;
        SYSTEMTIME wtm;
        GetLocalTime(&wtm);
        tm.tm_year = wtm.wYear - 1900;
        tm.tm_mon = wtm.wMonth - 1;
        tm.tm_mday = wtm.wDay;
        tm.tm_hour = wtm.wHour;
        tm.tm_min = wtm.wMinute;
        tm.tm_sec = wtm.wSecond;
        tm.tm_isdst = -1;
        clock = mktime(&tm);
        tv.tv_sec = (long)clock;
        tv.tv_usec = wtm.wMilliseconds * 1000;
        return ((unsigned long long)tv.tv_sec * 1000 + (unsigned long long)tv.tv_usec / 1000);
#else
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return ((unsigned long long)tv.tv_sec * 1000 + (unsigned long long)tv.tv_usec / 1000);
#endif
    }

    static unsigned long long GetCurrentTimeMsec_Clock()
    {
        return (unsigned long long)clock();
    }

    void TestTimeOffset()
    {
        while (true)
        {
            auto time = GetCurrentTimeMsec_TimeOfDay();
            auto time2 = GetCurrentTimeMsec_Clock();
            static auto lastT1 = time, lastT2 = time2;
            static auto beginT1 = time, beginT2 = time2;
            std::cout << time - beginT1 << " " << time2 - beginT2 << std::endl;
            std::cout << time - lastT1 << " " << time2 - lastT2 << std::endl;
            lastT1 = time, lastT2 = time2;
            Sleep(16);
        }
    }
};