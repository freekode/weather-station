#ifndef BacklightOnJobExecutor_h
#define BacklightOnJobExecutor_h

#include <jobexecuter/ScheduleJobExecutor.h>
#include "../adapters/ScreenAdapter.h"
#include "../adapters/RTCTimeAdapter.h"
#include "../devices/rtc/rtc.h"

class BacklightOnJobExecutor : public ScheduleJobExecutor {
private:
    ScreenAdapter &screenAdapter;

public:
    BacklightOnJobExecutor(
            uint8_t hour, uint8_t min, uint8_t sec,
            ScreenAdapter &screenAdapter) : ScheduleJobExecutor(hour, min, sec),
                                        screenAdapter(screenAdapter) {};

protected:
    void runInternally() override;
};

#endif