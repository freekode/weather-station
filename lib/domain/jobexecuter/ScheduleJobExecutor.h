#ifndef ScheduleJobExecutor_H
#define ScheduleJobExecutor_H

#include <stdint.h>

class ScheduleJobExecutor {
public:
    void run(uint8_t hour, uint8_t min, uint8_t sec);

    explicit ScheduleJobExecutor(uint8_t hour, uint8_t minute, uint8_t sec) :
            hour(hour), minute(minute), sec(sec) {};

protected:
    virtual void runInternally() = 0;

private:
    uint8_t hour;
    uint8_t minute;
    uint8_t sec;
};

#endif
