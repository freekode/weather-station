#ifndef RTCTimeAdapter_H
#define RTCTimeAdapter_H

#include <adapters/TimeAdapter.h>
#include <rtc/rtc.h>

class RTCTimeAdapter : public TimeAdapter {
public:
    void begin();

    uint32_t timestamp() override;

    String getDateWithoutYearStr() override;

    String getTimeStr() override;

    DateTimeValue now() override;

    void adjust(uint16_t year, uint8_t month, uint8_t day,
                        uint8_t hour, uint8_t min, uint8_t sec) override;

    void adjust(const DateTime &dt);

private:
    RTC rtc;
};

#endif