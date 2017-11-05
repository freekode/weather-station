#include "dht_sensor.h"

DHT_Sensor::DHT_Sensor() {
  dht.begin();
}

float DHT_Sensor::temperature() {
  sensors_event_t event;
  dht.temperature().getEvent(&event);

  return event.temperature;
}

float DHT_Sensor::humidity() {
  sensors_event_t event;
  dht.humidity().getEvent(&event);

  return event.relative_humidity;
}
