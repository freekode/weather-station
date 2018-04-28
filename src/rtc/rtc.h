#include "RTClib.h"

class RTC {
  public:
    RTC_DS1307 rtc;
    RTC();

    void adjust(const DateTime& dt);
    void adjustToUploadDate();

    uint32_t unixtime();
    DateTime now();
    String getDateStr();
    String getTimeStr();
    String getFullDateStr();
    String getDaysOfTheWeek();
  private:
    String addLeadingZero(int t);
    char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
};
