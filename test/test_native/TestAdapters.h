#ifndef TESTADAPTERS_H
#define TESTADAPTERS_H

#include <adapters/TimeAdapter.h>
#include <adapters/WeatherAdapter.h>

class TestWeatherAdapter : public WeatherAdapter
{
private:
    float value1;
    float value2;
    float value3;

public:
    TestWeatherAdapter(float value1,
                       float value2,
                       float value3) : value1(value1),
                                       value2(value2),
                                       value3(value3) {}
    virtual float temperature()
    {
        return this->value1;
    };
    virtual float humidity()
    {
        return this->value2;
    };
    virtual float pressure()
    {
        return this->value3;
    };
};

class TestTimeAdapter : public TimeAdapter
{
private:
    float value;

public:
    TestTimeAdapter(uint32_t value) : value(value) {}
    virtual uint32_t timestamp()
    {
        return this->value;
    }
    virtual String getDateWithoutYearStr()
    {
        return "";
    }
    virtual String getTimeStr()
    {
        return "";
    }
    virtual void adjust(int year, int month, int day,
                        int hour, int minute, int second)
    {
    }
};

#endif