#ifndef SerialAdapter_H
#define SerialAdapter_H

#include <Arduino.h>

#define SERIAL_BITRATE 9600

class SerialAdapter
{
public:
	SerialAdapter(Stream &serial);
	void begin();
	virtual String receive();
	size_t print(const __FlashStringHelper *);
	size_t print(const String &);
	size_t println(const __FlashStringHelper *);
	size_t println(const String &);

protected:
	Stream &serial;

private:
	String inputString = "";
	boolean inputComplete = false;
};

#endif
