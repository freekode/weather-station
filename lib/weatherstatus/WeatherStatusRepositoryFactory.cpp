#include <WeatherStatusRepositoryFactory.h>

WeatherStatusRepository *WeatherStatusRepositoryFactory::get()
{
    WeatherStatusFactory *factory = new WeatherStatusFactory(timeAdapter, weatherAdapter);
    WeatherStatusCache *cache = WeatherStatusCache::getInstance();

    WeatherStatusRepository *repository = new WeatherStatusRepository(*cache, *factory);
    return repository;
}
