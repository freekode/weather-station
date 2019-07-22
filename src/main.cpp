#include <Arduino.h>
#include <SoftwareSerial.h>
#include "config.h"
#include "main.h"

void setup(void)
{
	Serial.begin(SERIAL_BITRATE);
	BTSerial.begin(SERIAL_BITRATE);

	printUploadTime();
	initIntervals();
	sendAtCommand("AT");
	sendAtCommand("AT+NAME");
	sendAtCommand("AT+ADDR");

	// serialHelper.sendAtCommand("AT");
	// rtc->adjust(DateTime(F(__DATE__), F(__TIME__)));

	lcd.begin();
	lcd.backlight();
	lcd.createChar(0, clock);
	lcd.createChar(1, celsius);
	lcd.home();

	softwareSerial.println(F("started"));
}

void loop(void)
{
	saveWeather();
	processIO();
	printTime();

	// main delay for receiving commands
	delay(MAIN_DELAY_MS);
}

void processIO()
{
	String softwareInput = softwareSerial.receive();
	if (softwareInput.length() > 0)
	{
		softwareInput.trim();

		softwareSerial.print(F("input: "));
		softwareSerial.println(softwareInput);

		softwareSerial.print(F("output: "));

		String res = command.runCommand(softwareInput);
		softwareSerial.println(res);
	}
}

void printTime()
{
	if (rtc->unixtime() >= showTimeNextTime)
	{
		lcd.setCursor(0, 0);
		lcd.print(rtc->getDateWithoutYearStr());
		lcd.setCursor(8, 0);
		lcd.print(rtc->getTimeStr());

		showTimeNextTime = rtc->unixtime() + SHOW_TIME_DELAY_SEC;
	}
}

void saveWeather()
{
	if (rtc->unixtime() >= saveWeatherNextTime)
	{
		database->add(getDbEntry());

		printWeather();

		saveWeatherNextTime = rtc->unixtime() + WEATHER_DATA_SAVE_DELAY_SEC;
	}
}

void printWeather()
{
	DbEntry entry = database->last();

	lcd.setCursor(0, 1);
	lcd.print(String((entry.temperature + entry.temperature1) / 2, 1));
	// lcd.write(1);
	lcd.print(" ");
	lcd.print(entry.humidity);
	lcd.print("% ");
	lcd.print(entry.pressure);
	lcd.print("hPa");
}
