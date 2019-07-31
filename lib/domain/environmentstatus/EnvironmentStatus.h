#ifndef WEATHERSTATUS_H
#define WEATHERSTATUS_H

#include <stdint.h>
#include <Arduino.h>

class EnvironmentStatus {
public:
    EnvironmentStatus() {};

    EnvironmentStatus(
            uint32_t timestamp,
            float temperature,
            float humidity,
            float pressure);

    uint32_t getTimestamp() const;

    float getTemperature() const;

    float getHumidity() const;

    float getPressure() const;

    String toString() const;

private:
    uint32_t timestamp = 0;
    float temperature = 0;
    float humidity = 0;
    float pressure = 0;
};

#endif