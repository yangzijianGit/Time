/***
 * @Author       : yangzijian
 * @Description  : Time
 * @Date         : 2021-01-25 15:22:55
 */
#include "UTCTime.h"
#include <assert.h>
#include <iostream>

int UTCTime::localUTC = 0;

bool UTCTime::InitUTC(int UTC)
{
    assert(UTC >= -12 && UTC <= 12);
    localUTC = UTC;
    return true;
}

time_t UTCTime::GetGmtStamp()
{
    return time(0);
}

time_t UTCTime::GetUtcStamp()
{
    return GmtStampToUtcStamp(GetGmtStamp());
}

tm *UTCTime::GetLocalTime()
{
    time_t utcTime = GetUtcStamp();
    return gmtime(&utcTime);
}

tm *UTCTime::GmtStampToLocalTime(time_t curTime)
{
    time_t cvtTime = GmtStampToUtcStamp(curTime);
    return gmtime(&cvtTime);
}

tm *UTCTime::UtcStampToLocalTime(time_t curTime)
{
    return gmtime(&curTime);
}

time_t UTCTime::LocalTimeToGmtStamp(tm *const _Tm)
{
    time_t targetTime = _mkgmtime(_Tm); // 转换成 gmt 时间 mktime 会根据系统时区做转换
    return UtcStampToGmtStamp(targetTime);
}

time_t UTCTime::GmtStampToUtcStamp(time_t t)
{
    return t + ((time_t)localUTC) * 3600;
}
time_t UTCTime::UtcStampToGmtStamp(time_t t)
{
    return t - ((time_t)localUTC) * 3600;
}

/// <summary>
/// 是否在指定区间内
/// </summary>
/// <param name="timeFrom">900 表示 9:00</param>
/// <param name="timeTo">1861 表示 18:01</param>
/// <returns></returns>
bool UTCTime::IsInTimeInterval(int fromTime, int toTime)
{
    int fromHour = fromTime / 100;
    int fromMin = fromTime % 100 % 60;
    int toHour = toTime / 100;
    int toMin = toTime % 100 % 60;

    tm *curTM = GetLocalTime();
    if (curTM->tm_hour >= fromHour && toTime <= fromTime)
    {
        return curTM->tm_hour != fromHour || curTM->tm_min >= fromMin;
    }
    if (curTM->tm_hour >= fromHour && curTM->tm_hour <= toHour)
    {
        if (fromHour == toHour)
        {
            return (curTM->tm_min >= fromMin && curTM->tm_min <= toMin);
        }
        if (curTM->tm_hour == fromHour)
        {
            return curTM->tm_min >= fromMin;
        }
        if (curTM->tm_hour == toHour)
        {
            return curTM->tm_min <= toMin;
        }
        return true;
    }
    return false;
}

int UTCTime::GetSeason()
{
    tm *_Tm = GetLocalTime();
    return GetSeason(*_Tm);
}

int UTCTime::GetSeason(tm &_Tm)
{
    if (_Tm.tm_mon >= 2 && _Tm.tm_mon <= 4)
        return 1;
    else if (_Tm.tm_mon >= 5 && _Tm.tm_mon <= 7)
        return 2;
    else if (_Tm.tm_mon >= 8 && _Tm.tm_mon <= 10)
        return 3;
    else
        return 4;
}

int UTCTime::Test()
{
    
    UTCTime::InitUTC(8);
    std::cout << UTCTime::GetGmtStamp() << std::endl;
    std::cout << UTCTime::GetUtcStamp() << std::endl;
    tm *_Tm = UTCTime::GetLocalTime();
    std::cout << _Tm->tm_year << std::endl;
    std::cout << _Tm->tm_mon << std::endl;
    std::cout << _Tm->tm_mday << std::endl;
    std::cout << _Tm->tm_hour << std::endl;
    std::cout << _Tm->tm_min << std::endl;
    std::cout << _Tm->tm_sec << std::endl;
    std::cout << _Tm->tm_wday << std::endl;
    std::cout << _Tm->tm_yday << std::endl;
    std::cout << _Tm->tm_isdst << std::endl;
    std::cout << UTCTime::GmtStampToLocalTime(UTCTime::GetGmtStamp())->tm_year << std::endl;
    std::cout << UTCTime::GmtStampToLocalTime(UTCTime::GetGmtStamp())->tm_mon << std::endl;
    std::cout << UTCTime::GmtStampToLocalTime(UTCTime::GetGmtStamp())->tm_mday << std::endl;
    std::cout << UTCTime::GmtStampToLocalTime(UTCTime::GetGmtStamp())->tm_hour << std::endl;
    std::cout << UTCTime::GmtStampToLocalTime(UTCTime::GetGmtStamp())->tm_min << std::endl;
    std::cout << UTCTime::GmtStampToLocalTime(UTCTime::GetGmtStamp())->tm_sec << std::endl;
    std::cout << UTCTime::GmtStampToLocalTime(UTCTime::GetGmtStamp())->tm_wday << std::endl;
    std::cout << UTCTime::GmtStampToLocalTime(UTCTime::GetGmtStamp())->tm_yday << std::endl;
    std::cout << UTCTime::GmtStampToLocalTime(UTCTime::GetGmtStamp())->tm_isdst << std::endl;
    std::cout << UTCTime::LocalTimeToGmtStamp(_Tm) << std::endl;
    std::cout << UTCTime::GmtStampToUtcStamp(UTCTime::GetGmtStamp()) << std::endl;
    std::cout << UTCTime::UtcStampToGmtStamp(UTCTime::GetUtcStamp()) << std::endl;
    std::cout << UTCTime::UtcStampToLocalTime(UTCTime::GetUtcStamp())->tm_year << std::endl;
    std::cout << UTCTime::UtcStampToLocalTime(UTCTime::GetUtcStamp())->tm_mon << std::endl;
    std::cout << UTCTime::UtcStampToLocalTime(UTCTime::GetUtcStamp())->tm_mday << std::endl;
    std::cout << UTCTime::UtcStampToLocalTime(UTCTime::GetUtcStamp())->tm_hour << std::endl;
    std::cout << UTCTime::UtcStampToLocalTime(UTCTime::GetUtcStamp())->tm_min << std::endl;
    std::cout << UTCTime::UtcStampToLocalTime(UTCTime::GetUtcStamp())->tm_sec << std::endl;
    std::cout << UTCTime::UtcStampToLocalTime(UTCTime::GetUtcStamp())->tm_wday << std::endl;
    std::cout << UTCTime::UtcStampToLocalTime(UTCTime::GetUtcStamp())->tm_yday << std::endl;
    std::cout << UTCTime::UtcStampToLocalTime(UTCTime::GetUtcStamp())->tm_isdst << std::endl;
}
