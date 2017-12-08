#include <Arduino.h>
#include <SoftwareSerial.h>
#include <AltSoftSerial.h>
#include "config.h"
#include "command/command.h"
#include "dht_sensor/dht_sensor.h"
#include "bmp_sensor/bmp_sensor.h"
#include "rtc/rtc.h"
#include "db/db.h"

AltSoftSerial BTSerial;
DHT_Sensor dht;
BMP_Sensor bmp;
RTC rtc;

String btInputString = "";
boolean btInputComplete = false;

void sendCommand(const char * command) {
  Serial.print("BT send: ");
  Serial.println(command);

  BTSerial.println(command);
  delay(100);

  char reply[100];
  int i = 0;
  while (BTSerial.available()) {
    reply[i] = BTSerial.read();
    i += 1;
  }

  reply[i] = '\0';

  Serial.print("BT received: ");
  Serial.print(reply);
  Serial.println("Reply end");
}

DbEntry getDbEntry() {
  return DbEntry(
    rtc.unixtime(),
    dht.temperature(),
    bmp.temperature(),
    dht.humidity(),
    bmp.pressure()
  );
}

void printCommandOutput(String result) {
  Serial.println(result);
  // BTSerial.print(result);
}

void receiveFromSerial(Stream &serial) {
  if (serial.available()) {
    char inChar = serial.read();
    btInputString += inChar;
    if (inChar == '\n') {
      btInputComplete = true;
    }
  }
}

void setup(void) {
  Serial.begin(9600);
  BTSerial.begin(9600);

  btInputString.reserve(200);

  Serial.print("Sketch:   "); Serial.println(__FILE__);
  Serial.print("Uploaded: "); Serial.println(__DATE__);
  Serial.println("ws01 init");

  sendCommand("AT");
}

void loop(void) {
  // saving to database
  Database::getInstance()->add(getDbEntry());

  if (btInputComplete) {
    String output = commandHandler(btInputString);
    printCommandOutput(output);

    btInputString = "";
    btInputComplete = false;
  }

  receiveFromSerial(Serial);

  // if (BTSerial.available()) {
  //   char inChar = BTSerial.read();
  //   btInputString += inChar;
  //   if (inChar == '\n') {
  //     btInputComplete = true;
  //   }
  // }

  // main delay
  delay(SENSORS_READ_DELAY);
}
