#ifndef DHT_Sensor_H
#define DHT_Sensor_H

#include <DHT.h>
#include <DHT_U.h>
#include "dht_sensor_config.h"

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