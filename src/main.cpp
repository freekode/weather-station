#include <Arduino.h>
#include <SoftwareSerial.h>
#include <main.h>

#define SERIAL_BITRATE 9600

void setup(void) {
    initDevices();

    printUploadTime();
    printStarted();
}

void loop(void) {
    unsigned long ms = millis();
    const DateTimeValue &now = timeAdapter.now();

    inputJobExecuter.run(ms);
    btInputJobExecuter.run(ms);
    timeJobExecuter.run(ms);
    environmentJobExecuter.run(ms);

    backlightOnJobExecutor.run(now.hour(), now.minute(), now.second());
    backlightOffJobExecutor.run(now.hour(), now.minute(), now.second());
}

void initDevices() {
    Serial.begin(SERIAL_BITRATE);
    BTSerial.begin(SERIAL_BITRATE);

    timeAdapter.begin();
    screenAdapter.begin();
    environmentAdapter.begin();

}

void printUploadTime() {
    softwareSerial.print(F("Sketch:   "));
    softwareSerial.println(F(__FILE__));
    softwareSerial.print(F("Uploaded: "));
    softwareSerial.print(F(__DATE__));
    softwareSerial.print(F(" "));
    softwareSerial.println(F(__TIME__));
}

void printStarted() {
    softwareSerial.println(F("started"));
}