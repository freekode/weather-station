#ifndef SerialAdapter_H
#define SerialAdapter_H

#include <adapters/IOAdapter.h>

class SerialAdapter : public IOAdapter
{
public:
	SerialAdapter(Stream &serial) : IOAdapter(serial){};
	String receive();
	size_t print(const __FlashStringHelper *);
	size_t print(const String &);
	size_t println(const __FlashStringHelper *);
	size_t println(const String &);
};

#endif
