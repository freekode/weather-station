#include "SensorsEnvironmentAdapter.h"
#include <Arduino.h>

void SensorsEnvironmentAdapter::begin() {
    bmp.begin();
    dht.begin();
}

float SensorsEnvironmentAdapter::pressure() {
    return bmp.pressure();
}

float SensorsEnvironmentAdapter::temperature() {
    return (bmp.temperature() + dht.temperature()) / 2;
}

float SensorsEnvironmentAdapter::humidity() {
    return dht.humidity();
}
