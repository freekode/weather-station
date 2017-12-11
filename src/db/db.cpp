#include "db.h"
#include <stdlib.h>

Database *Database::s_instance = 0;

String DbEntry::toString() {
  char tempString[6];
  char temp1String[6];

  dtostrf(temperature, 4, 2, tempString);
  dtostrf(temperature1, 4, 2, temp1String);

  char out[50];
  sprintf(out, "%lu,%s,%s,%i,%i", timestamp, tempString, temp1String, humidity, pressure);

  return String(out);
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
