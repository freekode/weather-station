#include <jobexecuter/ScheduleJobExecutor.h>

void ScheduleJobExecutor::run(uint8_t hourInput, uint8_t minInput, uint8_t secInput) {
    if (hour == hourInput && minute == minInput && sec == secInput) {
        runInternally();
    }
}
