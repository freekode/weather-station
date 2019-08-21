#ifndef IntervalJobExecuter_H
#define IntervalJobExecuter_H

#include <stdint.h>

class IntervalJobExecuter {
public:
    void run(unsigned long currentMs);

    explicit IntervalJobExecuter(long interval_ms) : interval_ms(interval_ms) {};

protected:
    virtual void runInternally() = 0;

private:
    unsigned long interval_ms;
    unsigned long nextTime = 0;
};

#endif