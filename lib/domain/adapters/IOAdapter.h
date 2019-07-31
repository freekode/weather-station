#ifndef IOAdapter_H
#define IOAdapter_H

#include <stdint.h>
#include <Arduino.h>

class IOAdapter
{
public:
    IOAdapter(Stream &serial) : serial(serial){};

protected:
    Stream &serial;
};

#endif