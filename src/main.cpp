#include <Arduino.h>
#include <SoftwareSerial.h>
#include <AltSoftSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "config.h"
#include "serial_helper/serial_helper.h"
#include "command/command.h"
#include "dht_sensor/dht_sensor.h"
#include "bmp_sensor/bmp_sensor.h"
#include "rtc/rtc.h"
#include "db/db.h"

LiquidCrystal_I2C lcd(0x27, 16, 4);

AltSoftSerial BTSerial;
DHT_Sensor dht;
BMP_Sensor bmp;
RTC rtc;

SerialHelper softwareSerial(Serial);

uint32_t saveWeatherNextTime = 0;
uint32_t showTimeNextTime = 0;

uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};

DbEntry getDbEntry() {
  return DbEntry(
    rtc.unixtime(),
    dht.temperature(),
    bmp.temperature(),
    dht.humidity(),
    bmp.pressure() / 100
  );
}

void saveWeather() {
  if (saveWeatherNextTime == 0) {
    saveWeatherNextTime = rtc.unixtime();
  }

  if (rtc.unixtime() >= saveWeatherNextTime) {
    Database::getInstance()->add(getDbEntry());

    saveWeatherNextTime += WEATHER_DATA_SAVE_DELAY_SEC;
  }
}

void processIO() {
  String softwareInput = softwareSerial.receive();
  if (softwareInput.length() > 0) {
    softwareInput.trim();

    softwareSerial.print(F("input: "));
    softwareSerial.println(softwareInput);

    softwareSerial.print(F("output: "));

    String res = runCommand(softwareInput);
    softwareSerial.println(res);
  }

  // String btInput = serialHelper.receiveFromBt();
  // if (btInput.length() > 0) {
  //   btInput.trim();
  //
  //   Serial.print(F("bt input: "));
  //   Serial.println(btInput);
  //
  //   String btOutput = runCommand(btInput);
  //   Serial.print(F("bt output: "));
  //   Serial.println(btOutput);
  //   BTSerial.print(btOutput);
  // }
}

void printTime() {
  lcd.setCursor(0, 0);
  lcd.write(0);

  if (showTimeNextTime == 0) {
    showTimeNextTime = rtc.unixtime();
  }

  if (rtc.unixtime() >= showTimeNextTime) {
    lcd.setCursor(3, 0);
    lcd.print(rtc.getFullDateStr());

    showTimeNextTime += SHOW_TIME_DELAY_SEC;
  }
}

void setup(void) {
  Serial.begin(SERIAL_BITRATE);
  BTSerial.begin(SERIAL_BITRATE);

  softwareSerial.print(F("Sketch:   ")); softwareSerial.println(__FILE__);
  softwareSerial.print(F("Uploaded: ")); softwareSerial.println(__DATE__);
  softwareSerial.println(F("ws01 init"));

  // serialHelper.sendAtCommand("AT");

	lcd.begin();
  lcd.backlight();
  lcd.createChar(0, clock);
  lcd.home();
}

void loop(void) {
  saveWeather();
  processIO();
  printTime();

  // main delay for receiving commands
  delay(MAIN_DELAY_MS);
}
