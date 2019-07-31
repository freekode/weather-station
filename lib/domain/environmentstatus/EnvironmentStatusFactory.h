#ifndef WEATHERSTATUSFACTORY_H
#define WEATHERSTATUSFACTORY_H

#include <environmentstatus/EnvironmentStatus.h>
#include <adapters/TimeAdapter.h>
#include <adapters/EnvironmentAdapter.h>

class EnvironmentStatusFactory
{
public:
    EnvironmentStatusFactory(
        TimeAdapter &timeAdapter,
        EnvironmentAdapter &environmentAdapter) : timeAdapter(timeAdapter),
                                          environmentAdapter(environmentAdapter) {}
    EnvironmentStatus get() const;

private:
    TimeAdapter &timeAdapter;
    EnvironmentAdapter &environmentAdapter;
};

#endif