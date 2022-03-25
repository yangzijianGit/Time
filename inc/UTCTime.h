/***
 * @Author       : yangzijian
 * @Description  : Time
 * @Date         : 2021-01-25 15:22:55
 */

#pragma once

#include <time.h>

class UTCTime
{
    // 函数命名是utc是因为utc实际是现代标准时区gmt是老时区表现，我这里utc代表带时区的，gmt代表不带时区的
public:
    static bool InitUTC(int UTC);

    static tm *GetLocalTime();
    static time_t GetGmtStamp(); //	自1970到现在的秒数 + 时区秒数
    static time_t GetUtcStamp();

    static tm *GmtStampToLocalTime(time_t curTime);
    static tm *UtcStampToLocalTime(time_t curTime);
    static time_t GmtStampToUtcStamp(time_t t);
    static time_t UtcStampToGmtStamp(time_t t);
    static time_t LocalTimeToGmtStamp(tm *const _Tm);

    static bool IsInTimeInterval(int timeFrom, int timeTo);

    static int GetSeason();
    static int GetSeason(tm &_Tm);
    static int localUTC; //	本地时区[-12,12]

    static void Test();
};
