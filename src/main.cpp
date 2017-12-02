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

void commandLast() {
  DbEntry entry = db.last();
  printSensorInfo(entry);
}

void commandHistory() {
  DbEntry *entries = db.all();

  for (size_t i = 0; i < IN_MEMORY_DB_SIZE; i++) {
    printSensorInfo(*(entries + i));
  }
}

void commandTest() {
  Serial.println("passed");
  BTSerial.println("passed");
}

void commandHandler(String command) {
  command.trim();

  Serial.print("command: ");
  Serial.println(command);

  if (command.equals("last")) {
    commandLast();
  } else if (command.equals("history")) {
    commandHistory();
  } else if (command.equals("test")) {
    commandTest();
  } else {
    Serial.println("unknown command");
  }
}

void setup(void) {
  Serial.begin(9600);
  BTSerial.begin(9600);

  Serial.println("ws01 init");
}

void loop(void) {
  // saving to database
  db.add(getDbEntry());

  if (BTSerial.available()) {
    String inputString = BTSerial.readString();
    commandHandler(inputString);
  }

  // main delay for save
  delay(SENSORS_READ_DELAY);
}
