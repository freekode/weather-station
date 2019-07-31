#ifndef TIMEADAPTER_H
#define TIMEADAPTER_H

#include <stdint.h>
#include <Arduino.h>

class TimeAdapter
{
public:
    virtual uint32_t timestamp() = 0;
    virtual String getDateWithoutYearStr() = 0;
    virtual String getTimeStr() = 0;
    virtual void adjust(uint16_t year, uint8_t month, uint8_t day,
                        uint8_t hour = 0, uint8_t min = 0, uint8_t sec = 0) = 0;
};

#endif