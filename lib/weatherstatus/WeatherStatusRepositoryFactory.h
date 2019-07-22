#ifndef WEATHERSTATUSREPOSITORYFACTORY_H
#define WEATHERSTATUSREPOSITORYFACTORY_H

#include <WeatherStatus.h>
#include <adapters/TimeAdapter.h>
#include <adapters/WeatherAdapter.h>
#include <WeatherStatusRepository.h>

class WeatherStatusRepositoryFactory
{
public:
    WeatherStatusRepositoryFactory(
        TimeAdapter &timeAdapter,
        WeatherAdapter &weatherAdapter) : timeAdapter(timeAdapter),
                                          weatherAdapter(weatherAdapter) {}
    WeatherStatusRepository *get();

private:
    TimeAdapter &timeAdapter;
    WeatherAdapter &weatherAdapter;
};

#endif