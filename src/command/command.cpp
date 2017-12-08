#include "command.h"
#include "../db/db.h"

String commandHandler(String command) {
  command.trim();

  Serial.print("command: ");
  Serial.println(command);

  String output;
  if (command.equals("last")) {
    output = commandLast();
  } else if (command.equals("history")) {
    output = commandHistory();
  } else if (command.equals("test")) {
    output = commandTest();
  } else {
    output = "unknown command";
  }

  return output;
}

String commandLast() {
  DbEntry entry = Database::getInstance()->last();

  return entry.toString();
}

String commandHistory() {
  DbEntry *entries = Database::getInstance()->all();

  for (size_t i = 0; i < IN_MEMORY_DB_SIZE; i++) {
    DbEntry entry = (*(entries + i));
    entry.toString();
  }

  return "";
}

String commandTest() {
  return "passed";
}
