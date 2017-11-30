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

void printSensorInfo() {
  float temp = dht.temperature();
  float hum = dht.humidity();

  float temp1 = bmp.temperature();
  float pressure = bmp.pressure();

  Serial.print(temp);
  Serial.print("C, ");
  Serial.print(hum);
  Serial.print("%, ");
  Serial.print(temp1);
  Serial.print("C, ");
  Serial.print(pressure);
  Serial.println("kPa");
}


void setup(void) {
  Serial.begin(9600);
  BTSerial.begin(9600);

  Serial.println("ws01 init");

  DbEntry r;
  r.humidity = 0;

  db.add(r);
}

void loop(void) {
  printSensorInfo();

  uint32_t timestamp = rtc.unixtime();
  Serial.println(timestamp);

  delay(SENSORS_READ_DELAY);
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
