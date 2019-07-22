#include "WeatherJobExecuter.h"

void WeatherJobExecuter::runInternally()
{
    WeatherStatus weatherStatus = weatherStatusRepository.getCurrent();
    screenAdapter.printSatus(weatherStatus);
}