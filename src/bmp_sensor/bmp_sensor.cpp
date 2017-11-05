#include "bmp_sensor.h"

void BMP_Sensor::begin() {
  if (!initialized) {
    initialized = bmp.begin(BMP085_MODE_ULTRALOWPOWER);
  }
}

float BMP_Sensor::pressure() {
  begin();

  float pressure;
  bmp.getPressure(&pressure);

  return pressure;
}

float BMP_Sensor::temperature() {
  begin();

  float temperature;
  bmp.getTemperature(&temperature);

  return temperature;
}

float BMP_Sensor::altitude() {
  begin();

  float pressureValue = pressure();
  return bmp.pressureToAltitude(SENSORS_PRESSURE_SEALEVELHPA, pressureValue);
}
