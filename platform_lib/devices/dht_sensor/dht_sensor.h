#ifndef DHT_Sensor_H
#define DHT_Sensor_H

#define DHTPIN 2
#define DHTTYPE DHT22

#include <DHT.h>
#include <DHT_U.h>

class DHT_Sensor
{
public:
	void begin();
	float temperature();
	float humidity();

private:
	DHT_Unified dht = DHT_Unified(DHTPIN, DHTTYPE);
};

#endif