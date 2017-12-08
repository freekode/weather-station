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
  BTSerial.print(result);
}

void setup(void) {
  Serial.begin(9600);
  BTSerial.begin(9600);

  Serial.print("Sketch:   "); Serial.println(__FILE__);
  Serial.print("Uploaded: "); Serial.println(__DATE__);
  Serial.println("ws01 init");

  serialHelper.sendAtCommand("AT");
}

void loop(void) {
  // saving to database
  Database::getInstance()->add(getDbEntry());

  String input = serialHelper.receiveFromSoftware();
  if (input.length() > 0) {
    input.trim();

    Serial.print("intput: ");
    Serial.println(input);

    Serial.print("output: ");
    Serial.println(runCommand(input));
  }

  // main delay for receiving commands
  delay(MAIN_DELAY_MS);
}
