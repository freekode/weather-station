#include "bmp_sensor.h"

void BMP_Sensor::begin()
{
	bmp.begin();
}

float BMP_Sensor::pressure()
{
	return bmp.readPressure();
}

float BMP_Sensor::temperature()
{
	return bmp.readTemperature();
}

float BMP_Sensor::altitude()
{
	return bmp.readAltitude();
}
