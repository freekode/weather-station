#ifndef EnvironmentAdapter_H
#define EnvironmentAdapter_H

class EnvironmentAdapter
{
public:
    virtual float temperature() = 0;
    virtual float humidity() = 0;
    virtual float pressure() = 0;
};

#endif