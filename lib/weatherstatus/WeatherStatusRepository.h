#ifndef WEATHERSTATUSREPOSITORY_H
#define WEATHERSTATUSREPOSITORY_H

#include <WeatherStatus.h>
#include <WeatherStatusCache.h>
#include <WeatherStatusFactory.h>

class WeatherStatusRepository
{
public:
    WeatherStatusRepository(
        WeatherStatusCache &weatherStatusCache,
        WeatherStatusFactory &weatherStatusFactory) : weatherStatusCache(weatherStatusCache),
                                                      weatherStatusFactory(weatherStatusFactory){};
    WeatherStatus *getAll();
    WeatherStatus getCurrent();

private:
    WeatherStatusCache &weatherStatusCache;
    WeatherStatusFactory &weatherStatusFactory;
};

#endif