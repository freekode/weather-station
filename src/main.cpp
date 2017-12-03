#include <Arduino.h>
#include <SoftwareSerial.h>
#include <AltSoftSerial.h>
#include "config.h"
#include "dht_sensor/dht_sensor.h"
#include "bmp_sensor/bmp_sensor.h"
#include "rtc/rtc.h"
#include "db/db.h"

AltSoftSerial BTSerial;
DHT_Sensor dht;
BMP_Sensor bmp;
RTC rtc;
DB db;

char c=' ';
boolean NL = true;

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
  BTSerial.print("passed");
}

void commandHandler(String command) {
  command.trim();

  Serial.print("command: ");
  Serial.println(command);

  /*
  if (command.equals("last")) {
    commandLast();
  } else if (command.equals("history")) {
    commandHistory();
  } else if (command.equals("test")) {
    commandTest();
  } else {
    Serial.println("unknown command");
  }
  */
}

void setup(void) {
  Serial.begin(9600);
  BTSerial.begin(9600);

  Serial.print("Sketch:   ");   Serial.println(__FILE__);
  Serial.print("Uploaded: ");   Serial.println(__DATE__);
  Serial.println("ws01 init");

  BTSerial.write("AT");
}

void loop(void) {
  // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTSerial.available())
    {
        c = BTSerial.read();
        Serial.write(c);
    }


    // Read from the Serial Monitor and send to the Bluetooth module
    if (Serial.available())
    {
        c = Serial.read();

        // do not send line end characters to the HM-10
        if (c!=10 & c!=13 )
        {
             BTSerial.write(c);
        }

        // Echo the user input to the main window.
        // If there is a new line print the ">" character.
        if (NL) { Serial.print("\r\n>");  NL = false; }
        Serial.write(c);
        if (c==10) { NL = true; }
    }
}

void loop2(void) {
  // saving to database

  // if (BTSerial.available()) {
    // String inputString = BTSerial.readString();
    // commandHandler(inputString);
  // }

  if (BTSerial.available()) {
    String str = BTSerial.readString();
    commandHandler(str);
  }

  db.add(getDbEntry());

  // main delay for save
  delay(SENSORS_READ_DELAY);
}
