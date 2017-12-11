#include <Arduino.h>
#include <stdint.h>
#include "../config.h"

class DbEntry {
  public:
    uint32_t timestamp;
    float temperature;
    float temperature1;
    int humidity;
    int pressure;
    DbEntry() {};
    DbEntry(
      uint32_t timestamp,
      float temperature,
      float temperature1,
      int humidity,
      int pressure):
        timestamp(timestamp),
        temperature(temperature),
        temperature1(temperature1),
        humidity(humidity),
        pressure(pressure) {};
    String toString();
};

class Database {
  static Database *s_instance;
  int nextDbIndex = 0;
  DbEntry storage[IN_MEMORY_DB_SIZE];
  public:
    static Database *getInstance() {
        if (!s_instance) {
          s_instance = new Database;
        }

        return s_instance;
    };
    DbEntry last();
    DbEntry* all();
    void add(DbEntry newEntry);
};
