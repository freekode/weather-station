#ifndef ScreenAdapter_H
#define ScreenAdapter_H

#include <LiquidCrystal_I2C.h>
#include <environmentstatus/EnvironmentStatus.h>
#include <Arduino.h>

class ScreenAdapter
{
private:
    uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
    uint8_t celsius[8] = {0x18, 0x18, 0x7, 0x8, 0x8, 0x8, 0x7};
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

public:
    ScreenAdapter(){};
    void begin();
    void printDateTime(String date, String time);
    void printSatus(EnvironmentStatus environmentStatus);
    void backlight(bool state);
};

#endif