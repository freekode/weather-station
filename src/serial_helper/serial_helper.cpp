#include "serial_helper.h"

String SerialHelper::sendAtCommand(const char *command) {
  serial.println(command);
  delay(100);

  char reply[100];
  int i = 0;
  while (serial.available()) {
    reply[i] = serial.read();
    i += 1;
  }

  reply[i] = '\0';

  return String(reply);
}

String SerialHelper::receive() {
  if (serial.available()) {
    char inChar = serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      inputComplete = true;
    }
  }

  if (inputComplete) {
    String input = String(inputString);

    inputString = "";
    inputComplete = false;

    return input;
  }

  return "";
}

size_t SerialHelper::print(const __FlashStringHelper *ifsh) {
  return serial.print(ifsh);
}

size_t SerialHelper::print(const String &s) {
  return serial.print(s);
}

size_t SerialHelper::println(const __FlashStringHelper *ifsh) {
  return serial.println(ifsh);
}

size_t SerialHelper::println(const String &s) {
  return serial.println(s);
}
