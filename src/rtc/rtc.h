#include "RTClib.h"

class RTC {
  public:
    RTC_DS1307 rtc;
    RTC();
    uint32_t unixtime();
    void adjust(const DateTime& dt);
    char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
};
