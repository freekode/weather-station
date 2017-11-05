#include <Adafruit_BMP085_U.h>

class BMP_Sensor {
  public:
    boolean initialized = false;
    float pressure();
    float temperature();
    float altitude();
  private:
    Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
    void begin();
};
