#include <RTClib.h>

class RTC {
  public:
    RTC_DS1307 rtc;
    RTC();

    static RTC *getInstance() {
        if (!s_instance) {
          s_instance = new RTC;
        }

        return s_instance;
    };

    void adjust(const DateTime& dt);
    void adjustToUploadDate();

    uint32_t unixtime();
    DateTime now();
    String getDateStr();
    String getDateWithoutYearStr();
    String getTimeStr();
    String getFullDateStr();
    String getDaysOfTheWeek();
  private:
    static RTC *s_instance;
    String addLeadingZero(int t);
    char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
};
