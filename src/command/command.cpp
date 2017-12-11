#include "command.h"
#include "../db/db.h"

String runCommand(String command) {
  command.trim();

  if (command.equals(F("test"))) {
    return commandTest();
  } else if (command.equals(F("ram"))) {
    return commandFreeRam();
  } else if (command.equals(F("last"))) {
    return commandLast();
  // } else if (command.equals(F("history"))) {
  //   return commandHistory();
  }

  return String(F("unknown command"));
}

String commandLast() {
  DbEntry entry = Database::getInstance()->last();

  return entry.toString();
}

String commandHistory() {
  DbEntry *entries = Database::getInstance()->all();

  String out = "";
  out.reserve(500);
  for (size_t i = 0; i < IN_MEMORY_DB_SIZE; i++) {
    DbEntry entry = (*(entries + i));
    entry.toString();
  }

  return "not implemented";
}

String commandTest() {
  return F("passed");
}

String commandFreeRam() {
  extern int __heap_start, *__brkval;
  int v;
  int value = (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);

  return String(value);
}
