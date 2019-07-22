#include <WeatherStatusFactory.h>

WeatherStatus WeatherStatusFactory::get()
{
    return WeatherStatus(
        timeAdapter.timestamp(),
        weatherAdapter.temperature(),
        weatherAdapter.humidity(),
        weatherAdapter.pressure());
}
