#include <stdint.h>
#include "../config.h"

struct DbEntry {
  uint32_t timestamp;
  float temperature;
  float temperature1;
  float humidity;
  float pressure;
};

class DB {
  public:
    DbEntry last();
    DbEntry* all();
    void add(DbEntry newEntry);
  private:
    int nextDbIndex = 0;
    DbEntry database[IN_MEMORY_DB_SIZE];
};
