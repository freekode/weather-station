#ifndef SensorsWetherAdapter_H
#define SensorsWetherAdapter_H

#include <adapters/EnvironmentAdapter.h>
#include <bmp_sensor/bmp_sensor.h>
#include <dht_sensor/dht_sensor.h>

class SensorsEnvironmentAdapter : public EnvironmentAdapter
{
public:
    void begin();
    virtual float temperature();
    virtual float humidity();
    virtual float pressure();

private:
    BMP_Sensor bmp;
    DHT_Sensor dht;
};

#endif