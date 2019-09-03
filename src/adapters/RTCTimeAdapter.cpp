#include "RTCTimeAdapter.h"

void RTCTimeAdapter::begin() {
    rtc.begin();
}

uint32_t RTCTimeAdapter::timestamp() {
    return rtc.unixtime();
}

String RTCTimeAdapter::getDateWithoutYearStr() {
    return rtc.getDateWithoutYearStr();
}

String RTCTimeAdapter::getTimeStr() {
    return rtc.getTimeStr();
}

DateTimeValue RTCTimeAdapter::now() {
    const DateTime &time = rtc.now();
    return {time.year(), time.month(), time.day(), time.hour(), time.minute(), time.second()};
}

void RTCTimeAdapter::adjust(uint16_t year, uint8_t month, uint8_t day,
                            uint8_t hour, uint8_t min, uint8_t sec) {
    DateTime dt(year, month, day, hour, min, sec);
    rtc.adjust(dt);
}

void RTCTimeAdapter::adjust(const DateTime &dt) {
    rtc.adjust(dt);
}
