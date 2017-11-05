#include <Arduino.h>
#include "dht_sensor/dht_sensor.h"
#include "bmp_sensor/bmp_sensor.h"
#include "rtc/rtc.h"

DHT_Sensor dht;
BMP_Sensor bmp;
RTC rtc;

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
  Serial.println("start");
}

void loop(void) {
  printSensorInfo();

  uint32_t timestamp = rtc.unixtime();
  Serial.println(timestamp);

  delay(1000);
}
