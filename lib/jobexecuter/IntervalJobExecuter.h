#ifndef IntervalJobExecuter_H
#define IntervalJobExecuter_H

#include <stdint.h>

class IntervalJobExecuter
{
public:
    void run(long currentMs);
    IntervalJobExecuter(long interval_ms) : interval_ms(interval_ms){};

protected:
    virtual void runInternally() = 0;

private:
    long interval_ms;
    long nextTime;
};

#endif