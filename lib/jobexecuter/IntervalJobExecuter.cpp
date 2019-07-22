#include <IntervalJobExecuter.h>

void IntervalJobExecuter::run(long currentMs)
{
    if (currentMs >= nextTime)
    {
        runInternally();
        nextTime = currentMs + interval_ms;
    }
}
