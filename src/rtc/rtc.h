#include "RTClib.h"

class RTC {
  public:
    RTC_DS1307 rtc;
    void adjust(const DateTime& dt);
    RTC();
    uint32_t unixtime();
  private:
    char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
};
