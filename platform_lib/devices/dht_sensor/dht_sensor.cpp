#include "dht_sensor.h"

void DHT_Sensor::begin()
{
	dht.begin();
}

float DHT_Sensor::temperature()
{
	sensors_event_t event;
	dht.temperature().getEvent(&event);

	return event.temperature;
}

float DHT_Sensor::humidity()
{
	sensors_event_t event;
	dht.humidity().getEvent(&event);

	return event.relative_humidity;
}
