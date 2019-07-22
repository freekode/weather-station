#include "SerialAdapter.h"

SerialAdapter::SerialAdapter(Stream &serial) : serial(serial)
{
	inputString.reserve(10);
}

void SerialAdapter::begin() {
}

String SerialAdapter::receive()
{
	if (serial.available())
	{
		char inChar = serial.read();
		inputString += inChar;
		if (inChar == '\n')
		{
			inputComplete = true;
		}
	}

	if (inputComplete)
	{
		String input = String(inputString);

		inputString = "";
		inputComplete = false;

		input.trim();

		return input;
	}

	return "";
}

size_t SerialAdapter::print(const __FlashStringHelper *ifsh)
{
	return serial.print(ifsh);
}

size_t SerialAdapter::print(const String &s)
{
	return serial.print(s);
}

size_t SerialAdapter::println(const __FlashStringHelper *ifsh)
{
	return serial.println(ifsh);
}

size_t SerialAdapter::println(const String &s)
{
	return serial.println(s);
}
