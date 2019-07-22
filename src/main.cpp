#include <Arduino.h>
#include <SoftwareSerial.h>
#include <config.h>
#include <main.h>

void setup(void)
{
	initDevices();

	printUploadTime();
	printStarted();
}

void loop(void)
{
	long ms = millis();

	inputJobExecuter.run(ms);
	timeJobExecuter.run(ms);
	weatherJobExecuter.run(ms);
}

void initDevices()
{
	Serial.begin(SERIAL_BITRATE);
	BTSerial.begin(SERIAL_BITRATE);

	screenAdapter.begin();
	weatherAdapter.begin();
}

void printUploadTime()
{
	softwareSerial.print(F("Sketch:   "));
	softwareSerial.println(F(__FILE__));
	softwareSerial.print(F("Uploaded: "));
	softwareSerial.print(F(__DATE__));
	softwareSerial.print(F(" "));
	softwareSerial.println(F(__TIME__));
}

void printStarted()
{
	softwareSerial.println(F("started"));
}