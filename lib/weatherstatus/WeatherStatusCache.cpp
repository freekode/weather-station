#include <WeatherStatusCache.h>

WeatherStatusCache *WeatherStatusCache::instance = 0;

WeatherStatusCache::WeatherStatusCache()
{
    nextDbIndex = 0;
}

WeatherStatusCache *WeatherStatusCache::getInstance()
{
    {
        if (!instance)
        {
            instance = new WeatherStatusCache;
        }
        return instance;
    };
}

void WeatherStatusCache::push(WeatherStatus weatherStatus)
{
    if (nextDbIndex > IN_MEMORY_DB_SIZE)
    {
        nextDbIndex = 0;
    }

    storage[nextDbIndex] = weatherStatus;
    nextDbIndex++;
}

WeatherStatus WeatherStatusCache::getLast()
{
    return storage[nextDbIndex - 1];
}

WeatherStatus *WeatherStatusCache::getAll()
{
    return storage;
}