#ifndef WEATHERSTATUSCACHE_H
#define WEATHERSTATUSCACHE_H

#include <WeatherStatus.h>
#include <stdint.h>
#include <stdlib.h>

#define IN_MEMORY_DB_SIZE 10

class WeatherStatusCache
{
public:
    static WeatherStatusCache *getInstance();
    void push(WeatherStatus weatherStatus);
    WeatherStatus getLast();
    WeatherStatus *getAll();

private:
    int nextDbIndex;
    WeatherStatus storage[IN_MEMORY_DB_SIZE];
    static WeatherStatusCache *instance;
    WeatherStatusCache();
};

#endif