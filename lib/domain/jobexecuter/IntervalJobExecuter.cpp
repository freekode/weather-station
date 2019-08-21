#include <jobexecuter/IntervalJobExecuter.h>

void IntervalJobExecuter::run(unsigned long currentMs) {
    if (currentMs >= nextTime) {
        runInternally();
        nextTime = currentMs + interval_ms;
    }
}
