#ifndef TimeJobExecuter_H
#define TimeJobExecuter_H

#include <jobexecuter/IntervalJobExecuter.h>
#include "../adapters/ScreenAdapter.h"
#include "../adapters/RTCTimeAdapter.h"
#include "../devices/rtc/rtc.h"

class TimeJobExecuter : public IntervalJobExecuter
{
private:
    ScreenAdapter &screenAdapter;
    TimeAdapter &timeAdapter;

public:
    TimeJobExecuter(
        long interval_ms,
        ScreenAdapter &screenAdapter,
        TimeAdapter &timeAdapter) : IntervalJobExecuter(interval_ms),
                    screenAdapter(screenAdapter),
                    timeAdapter(timeAdapter){};

protected:
    virtual void runInternally();
};

#endif