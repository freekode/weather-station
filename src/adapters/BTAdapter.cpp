#include "BTAdapter.h"

void BTAdapter::sendAtCommand(const char *command)
{
	serial.println(command);
	delay(100);
}

String BTAdapter::receive()
{
	char reply[100];
	int i = 0;
	while (serial.available())
	{
		reply[i] = serial.read();
		i += 1;
	}

	reply[i] = '\0';

	return String(reply);
}
