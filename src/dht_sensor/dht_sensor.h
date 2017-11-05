#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT22

class DHT_Sensor {
  public:
    DHT_Sensor();
    float temperature();
    float humidity();
  private:
    DHT_Unified dht = DHT_Unified(DHTPIN, DHTTYPE);
};
