#include <environmentstatus/EnvironmentStatus.h>

EnvironmentStatus::EnvironmentStatus(
        uint32_t timestamp,
        float temperature,
        float humidity,
        float pressure) : timestamp(timestamp),
                          temperature(temperature),
                          humidity(humidity),
                          pressure(pressure) {}

uint32_t EnvironmentStatus::getTimestamp() const {
    return timestamp;
};

float EnvironmentStatus::getTemperature() const {
    return temperature;
};

float EnvironmentStatus::getHumidity() const {
    return humidity;
};

float EnvironmentStatus::getPressure() const {
    return pressure;
};

String EnvironmentStatus::toString() const {
    return "timestamp=" + String(timestamp) + ";" +
           "temperature=" + String(temperature) + ";" +
           "humidity=" + String(humidity) + ";" +
           "pressure=" + String(pressure);
}