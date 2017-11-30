#include "db.h"

DbEntry DB::last() {
  return database[nextDbIndex - 1];
}

void DB::add(DbEntry newEntry) {
  if (nextDbIndex > IN_MEMORY_DB_SIZE) {
    nextDbIndex = 0;
  }

  database[nextDbIndex] = newEntry;
  nextDbIndex++;
}
