#ifndef WEATHERSTATUSREPOSITORY_H
#define WEATHERSTATUSREPOSITORY_H

#include <environmentstatus/EnvironmentStatus.h>
#include <environmentstatus/EnvironmentStatusCache.h>
#include <environmentstatus/EnvironmentStatusFactory.h>

class EnvironmentStatusRepository
{
public:
    EnvironmentStatusRepository(
        EnvironmentStatusCache &environmentStatusCache,
        EnvironmentStatusFactory &environmentStatusFactory) : environmentStatusCache(environmentStatusCache),
                                                      environmentStatusFactory(environmentStatusFactory){};
    EnvironmentStatus *getAll();
    EnvironmentStatus getCurrent();
    EnvironmentStatus getLast();

private:
    EnvironmentStatusCache &environmentStatusCache;
    EnvironmentStatusFactory &environmentStatusFactory;
};

#endif