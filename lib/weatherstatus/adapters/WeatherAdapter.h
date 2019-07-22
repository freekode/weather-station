#ifndef WeatherAdapter_H
#define WeatherAdapter_H

class WeatherAdapter
{
public:
    virtual float temperature() = 0;
    virtual float humidity() = 0;
    virtual float pressure() = 0;
};

#endif