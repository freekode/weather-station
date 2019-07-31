#include "SerialAdapter.h"

String SerialAdapter::receive()
{
	String input = "";
	while (serial.available() > 0)
	{
		input += (char)serial.read();
	}
	input.trim();

	return input;
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
