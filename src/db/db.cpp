#include "db.h"
#include <stdlib.h>

Database *Database::s_instance = 0;

char* DbEntry::toString() {
  char out[50];

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
