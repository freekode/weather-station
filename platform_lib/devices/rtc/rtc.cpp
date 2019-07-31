#include "rtc.h"

void RTC::begin()
{
	rtc.begin();
}

uint32_t RTC::unixtime()
{
	DateTime now = rtc.now();
	return now.unixtime();
}

void RTC::adjust(const DateTime &dt)
{
	rtc.adjust(dt);
}

DateTime RTC::now()
{
	return rtc.now();
}

String RTC::getDateStr()
{
	DateTime dateTime = now();

	String date =
		getDateWithoutYearStr() +
		'/' +
		String(dateTime.yearShort());

	return date;
}

String RTC::getDateWithoutYearStr()
{
	DateTime dateTime = now();

	String date =
		addLeadingZero(dateTime.day()) +
		'/' +
		addLeadingZero(dateTime.month());

	return date;
}

String RTC::getTimeStr()
{
	DateTime dateTime = now();

	String timeStr =
		addLeadingZero(dateTime.hour()) +
		':' +
		addLeadingZero(dateTime.minute()) +
		':' +
		addLeadingZero(dateTime.second());

	return timeStr;
}

String RTC::getFullDateStr()
{
	return getDateStr() + " " + getTimeStr();
}

String RTC::getDaysOfTheWeek()
{
	DateTime dateTime = now();

	return String(daysOfTheWeek[dateTime.dayOfTheWeek()]);
}

String RTC::addLeadingZero(int t)
{
	return t < 10 ? "0" + String(t) : String(t);
}
