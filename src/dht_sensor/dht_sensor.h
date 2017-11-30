#include <DHT.h>
#include <DHT_U.h>
#include "../config.h"

class DHT_Sensor {
  public:
    DHT_Sensor();
    float temperature();
    float humidity();
  private:
    DHT_Unified dht = DHT_Unified(DHTPIN, DHTTYPE);
};
