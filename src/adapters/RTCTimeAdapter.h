#ifndef RTCTimeAdapter_H
#define RTCTimeAdapter_H

#include <adapters/TimeAdapter.h>
#include <rtc/rtc.h>

class RTCTimeAdapter : public TimeAdapter
{
public:
    void begin();
    virtual uint32_t timestamp();
    virtual String getDateWithoutYearStr();
    virtual String getTimeStr();
    virtual void adjust(uint16_t year, uint8_t month, uint8_t day,
                        uint8_t hour = 0, uint8_t min = 0, uint8_t sec = 0);
    void adjust(const DateTime &dt);

private:
    RTC rtc;
};

#endif