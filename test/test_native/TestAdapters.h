#ifndef TESTADAPTERS_H
#define TESTADAPTERS_H

#include <adapters/TimeAdapter.h>
#include <adapters/EnvironmentAdapter.h>

class TestEnvironmentAdapter : public EnvironmentAdapter
{
private:
    float value1;
    float value2;
    float value3;

public:
    TestEnvironmentAdapter(float value1,
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
    virtual void adjust(uint16_t year, uint8_t month, uint8_t day,
                        uint8_t hour, uint8_t min, uint8_t sec)
    {
    }
};

#endif