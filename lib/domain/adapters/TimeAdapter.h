#ifndef TIMEADAPTER_H
#define TIMEADAPTER_H

#include <stdint.h>
#include <Arduino.h>

class DateTimeValue {
public:
    DateTimeValue(uint16_t year, uint8_t month, uint8_t day,
             uint8_t hour, uint8_t min, uint8_t sec) :
            y(year), m(month), d(day), hh(hour), mm(min), ss(sec) {};

    uint16_t year() const { return y; }

    uint8_t month() const { return m; }

    uint8_t day() const { return d; }

    uint8_t hour() const { return hh; }

    uint8_t minute() const { return mm; }

    uint8_t second() const { return ss; }

private:
    uint8_t y, m, d, hh, mm, ss;
};

class TimeAdapter {
public:
    virtual uint32_t timestamp() = 0;

    virtual String getDateWithoutYearStr() = 0;

    virtual String getTimeStr() = 0;

    virtual DateTimeValue now();

    virtual void adjust(uint16_t year, uint8_t month, uint8_t day,
                        uint8_t hour, uint8_t min, uint8_t sec) = 0;
};

;

#endif