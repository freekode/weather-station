#include "rtc.h"

RTC::RTC() {
  rtc.begin();
}

uint32_t RTC::unixtime() {
  DateTime now = rtc.now();
  return now.unixtime();
}