#include "serial_helper.h"

void SerialHelper::sendAtCommand(const char *command) {
  softwareSerial.print("BT send: ");
  softwareSerial.println(command);

  btSerial.println(command);
  delay(100);

  char reply[100];
  int i = 0;
  while (btSerial.available()) {
    reply[i] = btSerial.read();
    i += 1;
  }

  reply[i] = '\0';

  softwareSerial.print("BT received: ");
  softwareSerial.print(reply);
  softwareSerial.println("Reply end");
}


String SerialHelper::receiveFromBt() {
  if (btSerial.available()) {
    char inChar = btSerial.read();
    btInputString += inChar;
    if (inChar == '\n') {
      btInputComplete = true;
    }
  }

  if (btInputComplete) {
    String input = String(btInputString);

    btInputString = "";
    btInputComplete = false;

    return input;
  }

  return "";
}

String SerialHelper::receiveFromSoftware() {
  if (softwareSerial.available()) {
    char inChar = softwareSerial.read();
    softwareInputString += inChar;
    if (inChar == '\n') {
      softwareInputComplete = true;
    }
  }

  if (softwareInputComplete) {
    String input = String(softwareInputString);

    softwareInputString = "";
    softwareInputComplete = false;

    return input;
  }

  return "";
}
