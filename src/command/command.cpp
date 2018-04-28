#include <RTClib.h>
#include "command.h"
#include "../db/db.h"
#include "../rtc/rtc.h"

String Command::runCommand(String commandInput) {
  commandInput.trim();

  char *params[PARAMS_LENGTH] = { NULL };
  parseCommand(commandInput, params);

  String commandString = String(params[0]);

  if (commandString.equals(F("test"))) {
    return commandTest();
  } else if (commandString.equals(F("ram"))) {
    return commandFreeRam();
  } else if (commandString.equals(F("last"))) {
    return commandLast();
  } else if (commandString.equals(F("settime"))) {
     return commandSetTime(params);
  }
  // } else if (command.equals(F("history"))) {
  //   return commandHistory();
  // }

  return String(F("unknown command"));
}

String Command::commandLast() {
  DbEntry entry = Database::getInstance()->last();

  return entry.toString();
}

String Command::commandHistory() {
  DbEntry *entries = Database::getInstance()->all();

  String out = "";
  out.reserve(500);
  for (size_t i = 0; i < IN_MEMORY_DB_SIZE; i++) {
    DbEntry entry = (*(entries + i));
    entry.toString();
  }

  return "not implemented";
}

String Command::commandTest() {
  return F("passed");
}

String Command::commandFreeRam() {
  extern int __heap_start, *__brkval;
  int v;
  int value = (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);

  return String(value);
}

String Command::commandSetTime(char *params[]) {
  DateTime dateTime = DateTime(atoi(params[1]), atoi(params[2]), atoi(params[3]),
    atoi(params[4]), atoi(params[5]), atoi(params[6]));

  RTC::getInstance()->adjust(dateTime);

  return String(dateTime.year()) + "/" + String(dateTime.month()) + "/" + String(dateTime.day()) + " " +
    String(dateTime.hour()) + ":" + String(dateTime.minute()) + ":" + String(dateTime.second());
};

void Command::parseCommand(String command, char *params[]) {
  char commandChar[70];
  char delims[] = " ";

  command.toCharArray(commandChar, 70);

  int i = 0;
  params[i] = strtok(commandChar, delims);
  while (params[i] != NULL || i == PARAMS_LENGTH) {
      params[++i] = strtok( NULL, delims);
  }
}
