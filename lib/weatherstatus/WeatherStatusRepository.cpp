#include <WeatherStatusRepository.h>

WeatherStatus *WeatherStatusRepository::getAll()
{
    return weatherStatusCache.getAll();
}

WeatherStatus WeatherStatusRepository::getCurrent()
{
    WeatherStatus weatherStatus = weatherStatusFactory.get();
    weatherStatusCache.push(weatherStatus);
    return weatherStatus;
}
