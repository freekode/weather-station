#ifndef BacklightOffJobExecutor_h
#define BacklightOffJobExecutor_h

#include <jobexecuter/ScheduleJobExecutor.h>
#include "../adapters/ScreenAdapter.h"
#include "../adapters/RTCTimeAdapter.h"
#include "../devices/rtc/rtc.h"

class BacklightOffJobExecutor : public ScheduleJobExecutor {
private:
    ScreenAdapter &screenAdapter;

public:
    BacklightOffJobExecutor(
            uint8_t hour, uint8_t min, uint8_t sec,
            ScreenAdapter &screenAdapter) : ScheduleJobExecutor(hour, min, sec),
                                        screenAdapter(screenAdapter) {};

protected:
    void runInternally() override;
};

#endif