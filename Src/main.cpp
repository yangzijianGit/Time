/*** 
 * @Author       : yangzijian
 * @Description  : main
 * @Date         : 2021-01-25 15:21:31
 */

#include "Time.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

int main()
{
    while (true)
    {
        auto time = Time::GetCurrentTimeMsec();
        auto time2 = Time::GetCurrentTimeMsec2();
        static auto lastT1 = time, lastT2 = time2;
        static auto beginT1 = time, beginT2 = time2;
        std::cout << time - beginT1 << " " << time2 - beginT2 << std::endl;
        std::cout << time - lastT1 << " " << time2 - lastT2 << std::endl;
        lastT1 = time, lastT2 = time2;
        Sleep(16);
    }

    system("pause");
    return 0;
}