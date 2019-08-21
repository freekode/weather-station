#ifndef SensorsWetherAdapter_H
#define SensorsWetherAdapter_H

#include <adapters/EnvironmentAdapter.h>
#include <bmp_sensor/bmp_sensor.h>
#include <dht_sensor/dht_sensor.h>

class SensorsEnvironmentAdapter : public EnvironmentAdapter {
public:
    void begin();

    float temperature() override;

    float humidity() override;

    float pressure() override;

private:
    BMP_Sensor bmp;
    DHT_Sensor dht;
};

#endif