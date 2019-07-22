#ifndef WEATHERSTATUS_H
#define WEATHERSTATUS_H

#include <stdint.h>

class WeatherStatus
{
public:
	WeatherStatus(){};
	WeatherStatus(
		uint32_t timestamp,
		float temperature,
		float humidity,
		float pressure);
	uint32_t getTimestamp() const;
	float getTemperature() const;
	float getHumidity() const;
	float getPressure() const;

private:
	uint32_t timestamp;
	float temperature;
	float humidity;
	float pressure;
};

#endif