#ifndef BMP_Sensor_H
#define BMP_Sensor_H

#define ALTITUDE 106

#include <Adafruit_BMP085.h>

class BMP_Sensor
{
public:
	void begin();
	float pressure();
	float temperature();
	float altitude();

private:
	boolean initialized = false;
	Adafruit_BMP085 bmp;
};

#endif