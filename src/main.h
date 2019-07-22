#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <AltSoftSerial.h>
#include "db/db.h"
#include "serial_helper/serial_helper.h"
#include "dht_sensor/dht_sensor.h"
#include "bmp_sensor/bmp_sensor.h"
#include "rtc/rtc.h"
#include "command/command.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

AltSoftSerial BTSerial;
DHT_Sensor dht;
BMP_Sensor bmp;
RTC* rtc = RTC::getInstance();
Command command;
Database* database = Database::getInstance();

SerialHelper softwareSerial(Serial);
SerialHelper bluetoothSerial(BTSerial);

uint32_t saveWeatherNextTime;
uint32_t showTimeNextTime;

uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
uint8_t celsius[8] = {0x18, 0x18, 0x7, 0x8, 0x8, 0x8, 0x7};

void setup(void);
void loop(void);

void processIO();
void printTime();
void printWeather();
void saveWeather();

DbEntry getDbEntry() {
  return DbEntry(
    rtc->unixtime(),
    dht.temperature(),
    bmp.temperature(),
    dht.humidity(),
    bmp.pressure() / 100
  );
}

void initIntervals() {
  saveWeatherNextTime = rtc->unixtime();
  showTimeNextTime = rtc->unixtime();
}

void printUploadTime() {
  Serial.print(F("Sketch:   ")); Serial.println(F(__FILE__));
  Serial.print(F("Uploaded: ")); Serial.print(F(__DATE__)); Serial.print(" "); Serial.println(F(__TIME__));
}

void sendAtCommand(const char* command) {
  Serial.print("BT input: ");
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

  Serial.println(F("BT output:"));
  Serial.print(reply);
  Serial.println(F("BT output end"));
}
