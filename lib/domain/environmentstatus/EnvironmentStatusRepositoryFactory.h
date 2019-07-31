#ifndef WEATHERSTATUSREPOSITORYFACTORY_H
#define WEATHERSTATUSREPOSITORYFACTORY_H

#include <environmentstatus/EnvironmentStatus.h>
#include <adapters/TimeAdapter.h>
#include <adapters/EnvironmentAdapter.h>
#include <environmentstatus/EnvironmentStatusRepository.h>

class EnvironmentStatusRepositoryFactory
{
public:
    EnvironmentStatusRepositoryFactory(
        TimeAdapter &timeAdapter,
        EnvironmentAdapter &environmentAdapter) : timeAdapter(timeAdapter),
                                          environmentAdapter(environmentAdapter) {}
    EnvironmentStatusRepository *get();

private:
    TimeAdapter &timeAdapter;
    EnvironmentAdapter &environmentAdapter;
};

#endif