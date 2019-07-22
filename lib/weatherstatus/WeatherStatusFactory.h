#ifndef WEATHERSTATUSFACTORY_H
#define WEATHERSTATUSFACTORY_H

#include <WeatherStatus.h>
#include <adapters/TimeAdapter.h>
#include <adapters/WeatherAdapter.h>

class WeatherStatusFactory
{
public:
    WeatherStatusFactory(
        TimeAdapter &timeAdapter,
        WeatherAdapter &weatherAdapter) : timeAdapter(timeAdapter),
                                          weatherAdapter(weatherAdapter) {}
    WeatherStatus get();

private:
    TimeAdapter &timeAdapter;
    WeatherAdapter &weatherAdapter;
};

#endif