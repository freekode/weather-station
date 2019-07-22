#include <Arduino.h>

class WeatherStatus {
	public:
		uint32_t timestamp;
		float temperature;
		float temperature1;
		int humidity;
		float pressure;
		WeatherStatus() {};
		WeatherStatus(
			uint32_t timestamp,
			float temperature,
			float temperature1,
			int humidity,
			float pressure):
				timestamp(timestamp),
				temperature(temperature),
				temperature1(temperature1),
				humidity(humidity),
				pressure(pressure) {};
		String toString();
}; 