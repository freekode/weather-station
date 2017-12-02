#include <Arduino.h>
#include <SoftwareSerial.h>
#include "config.h"
#include "dht_sensor/dht_sensor.h"
#include "bmp_sensor/bmp_sensor.h"
#include "rtc/rtc.h"
#include "db/db.h"

DHT_Sensor dht;
BMP_Sensor bmp;
RTC rtc;
SoftwareSerial BTSerial(BT_TX, BT_RX);
DB db;

String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete

DbEntry getDbEntry() {
  DbEntry entry;

  entry.temperature = dht.temperature();
  entry.humidity = dht.humidity();

  entry.temperature1 = bmp.temperature();
  entry.pressure = bmp.pressure();

  entry.timestamp = rtc.unixtime();

  return entry;
}

void printSensorInfo(DbEntry entry) {
  Serial.print(entry.timestamp);
  Serial.print(", ");
  Serial.print(entry.temperature);
  Serial.print("C, ");
  Serial.print(entry.temperature1);
  Serial.print("C, ");
  Serial.print(entry.humidity);
  Serial.print("%, ");
  Serial.print(entry.pressure);
  Serial.println("kPa");
}

void printLast() {
  DbEntry entry = db.last();
  printSensorInfo(entry);
}

void printHistory() {
  DbEntry *entries = db.all();

  for (size_t i = 0; i < IN_MEMORY_DB_SIZE; i++) {
    printSensorInfo(*(entries + i));
  }
}

void commandHandler(String command) {
  command.trim();

  Serial.print("command: ");
  Serial.println(command);

  if (command.equals("last")) {
    printLast();
  } else if (command.equals("history")) {
    printHistory();
  } else {
    Serial.println("unknown command");
  }
}

void setup(void) {
  Serial.begin(9600);
  BTSerial.begin(9600);

  inputString.reserve(200);

  Serial.println("ws01 init");
}

void loop(void) {
  // saving to database
  db.add(getDbEntry());

  // reading commands
  if (stringComplete) {
    commandHandler(inputString);
    inputString = "";
    stringComplete = false;
  }

  // main delay for save
  delay(SENSORS_READ_DELAY);
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char) Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void readFromBt() {
  // read from BLE (HM-10)
  if (BTSerial.available()) {
    Serial.write("ble: ");
    String str = BTSerial.readString();
    Serial.print(str);
    Serial.write('\n');
  }

  // read from USB (Arduino Terminal)
  if (Serial.available()) {
    Serial.write("usb: ");
    String str = Serial.readString();
    BTSerial.print(str);
    Serial.print(str);
    Serial.write('\n');
  }
}
