#include <Arduino.h>
#include <SoftwareSerial.h>
#include <config.h>
#include <main.h>

void setup(void)
{
	initDevices();

	// bluetoothSerial.println("AT");
	// bluetoothSerial.println("AT+VERSION");
	// bluetoothSerial.println("AT+PIN");
	delay(200);

	printUploadTime();
	printStarted();

}

void loop(void)
{
    unsigned long ms = millis();

	inputJobExecuter.run(ms);
	btInputJobExecuter.run(ms);
	timeJobExecuter.run(ms);
	environmentJobExecuter.run(ms);
}

void initDevices()
{
	Serial.begin(SERIAL_BITRATE);
	BTSerial.begin(SERIAL_BITRATE);

	timeAdapter.begin();
	screenAdapter.begin();
	environmentAdapter.begin();

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