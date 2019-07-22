#ifndef WeatherJobExecuter_H
#define WeatherJobExecuter_H

#include <IntervalJobExecuter.h>
#include <WeatherStatusRepository.h>
#include <rtc/rtc.h>
#include "../adapters/ScreenAdapter.h"

class WeatherJobExecuter : public IntervalJobExecuter
{
private:
    ScreenAdapter &screenAdapter;
    WeatherStatusRepository &weatherStatusRepository;

public:
    WeatherJobExecuter(
        long interval_ms,
        ScreenAdapter &screenAdapter,
        WeatherStatusRepository &weatherStatusRepository) : IntervalJobExecuter(interval_ms),
                                                            screenAdapter(screenAdapter),
                                                            weatherStatusRepository(weatherStatusRepository){};

protected:
    virtual void runInternally();
};

#endif