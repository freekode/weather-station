#ifndef EnvironmentJobExecuter_H
#define EnvironmentJobExecuter_H

#include <jobexecuter/IntervalJobExecuter.h>
#include <environmentstatus/EnvironmentStatusRepository.h>
#include <rtc/rtc.h>
#include "../adapters/ScreenAdapter.h"

class EnvironmentJobExecuter : public IntervalJobExecuter
{
private:
    ScreenAdapter &screenAdapter;
    EnvironmentStatusRepository &environmentStatusRepository;

public:
    EnvironmentJobExecuter(
        long interval_ms,
        ScreenAdapter &screenAdapter,
        EnvironmentStatusRepository &environmentStatusRepository) : IntervalJobExecuter(interval_ms),
                                                            screenAdapter(screenAdapter),
                                                            environmentStatusRepository(environmentStatusRepository){};

protected:
    virtual void runInternally();
};

#endif