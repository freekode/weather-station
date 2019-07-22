#include "ScreenAdapter.h"

void ScreenAdapter::begin()
{
    lcd.begin();
    lcd.backlight();
    lcd.createChar(0, clock);
    lcd.createChar(1, celsius);
    lcd.home();
}

void ScreenAdapter::printDateTime(String date, String time)
{
    lcd.setCursor(0, 0);
    lcd.print(date);
    lcd.setCursor(8, 0);
    lcd.print(time);
}

void ScreenAdapter::printSatus(WeatherStatus weatherStatus)
{
    lcd.setCursor(0, 1);
    lcd.print(String(weatherStatus.getTemperature(), 1));
    lcd.write(1);
    lcd.print(F(" "));
    lcd.print((int)weatherStatus.getHumidity());
    lcd.print(F("%  "));
    lcd.print(String(weatherStatus.getPressure() / 100, 1));
    // lcd.print(F("hPa"));
}

void ScreenAdapter::backlight(bool state)
{
    if (state)
    {
        lcd.backlight();
    }
    else
    {
        lcd.noBacklight();
    }
}