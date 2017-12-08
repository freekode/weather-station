#include "command.h"
#include "../db/db.h"

String runCommand(String command) {
  command.trim();

  if (command.equals("test")) {
    return commandTest();
  } else if (command.equals("last")) {
    return commandLast();
  } else if (command.equals("history")) {
    return commandHistory();
  }

  return "unknown command";
}

String commandLast() {
  DbEntry entry = Database::getInstance()->last();

  return "lst";
}

String commandHistory() {
  DbEntry *entries = Database::getInstance()->all();

  for (size_t i = 0; i < IN_MEMORY_DB_SIZE; i++) {
    DbEntry entry = (*(entries + i));
    entry.toString();
  }

  return "hist";
}

String commandTest() {
  return "passed";
}
