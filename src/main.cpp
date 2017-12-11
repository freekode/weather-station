#include <Arduino.h>
#include <SoftwareSerial.h>
#include <AltSoftSerial.h>
#include "config.h"
#include "serial_helper/serial_helper.h"
#include "command/command.h"
#include "dht_sensor/dht_sensor.h"
#include "bmp_sensor/bmp_sensor.h"
#include "rtc/rtc.h"
#include "db/db.h"

AltSoftSerial BTSerial;
DHT_Sensor dht;
BMP_Sensor bmp;
RTC rtc;

SerialHelper serialHelper(Serial, BTSerial);

uint32_t nextOccurence = 0;

DbEntry getDbEntry() {
  return DbEntry(
    rtc.unixtime(),
    dht.temperature(),
    bmp.temperature(),
    dht.humidity(),
    bmp.pressure() / 100
  );
}

void setup(void) {
  Serial.begin(9600);
  BTSerial.begin(9600);

  Serial.print(F("Sketch:   ")); Serial.println(__FILE__);
  Serial.print(F("Uploaded: ")); Serial.println(__DATE__);
  Serial.println(F("ws01 init"));

  serialHelper.sendAtCommand("AT");
}

void loop(void) {
  if (nextOccurence == 0) {
    nextOccurence = rtc.unixtime();
  }

  if (rtc.unixtime() >= nextOccurence) {
    // saving to database
    Database::getInstance()->add(getDbEntry());

    nextOccurence += WEATHER_DATA_SAVE_DELAY_SEC;
  }

  String softwareInput = serialHelper.receiveFromSoftware();
  if (softwareInput.length() > 0) {
    softwareInput.trim();

    Serial.print(F("input: "));
    Serial.println(softwareInput);

    Serial.print(F("output: "));

    String res = runCommand(softwareInput);
    Serial.println(res);
  }

  String btInput = serialHelper.receiveFromBt();
  if (btInput.length() > 0) {
    btInput.trim();

    Serial.print(F("bt input: "));
    Serial.println(btInput);

    String btOutput = runCommand(btInput);
    Serial.print(F("bt output: "));
    Serial.println(btOutput);
    BTSerial.print(btOutput);
  }

  // main delay for receiving commands
  delay(MAIN_DELAY_MS);
}
