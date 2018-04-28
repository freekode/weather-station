#include "db.h"
#include <stdlib.h>

Database *Database::s_instance = 0;

String DbEntry::toString() {
  String out = String(timestamp) +
    ',' +
    String(temperature, 1) +
    ',' +
    String(temperature1, 1) +
    ',' +
    String(humidity) +
    ',' +
    String(pressure);

  return out;
}

DbEntry Database::last() {
  return storage[nextDbIndex - 1];
}

DbEntry* Database::all() {
  return storage;
}

void Database::add(DbEntry newEntry) {
  if (nextDbIndex > IN_MEMORY_DB_SIZE) {
    nextDbIndex = 0;
  }

  storage[nextDbIndex] = newEntry;
  nextDbIndex++;
}
