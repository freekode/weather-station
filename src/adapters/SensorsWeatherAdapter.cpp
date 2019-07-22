#include "SensorsWeatherAdapter.h"
#include <Arduino.h>

void SensorsWeatherAdapter::begin() {
    bmp.begin();
    dht.begin();
}

float SensorsWeatherAdapter::pressure()
{
    return bmp.pressure();
}

float SensorsWeatherAdapter::temperature()
{
    return (bmp.temperature() + dht.temperature()) / 2;
}

float SensorsWeatherAdapter::humidity() {
    return dht.humidity();
}
