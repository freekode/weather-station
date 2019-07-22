#include <WeatherStatus.h>

WeatherStatus::WeatherStatus(
	uint32_t timestamp,
	float temperature,
	float humidity,
	float pressure) : timestamp(timestamp),
					  temperature(temperature),
					  humidity(humidity),
					  pressure(pressure) {}

uint32_t WeatherStatus::getTimestamp() const
{
	return timestamp;
};

float WeatherStatus::getTemperature() const
{
	return temperature;
};

float WeatherStatus::getHumidity() const
{
	return humidity;
};

float WeatherStatus::getPressure() const
{
	return pressure;
};