#ifndef WEATHERSTATUSREPOSITORY_H
#define WEATHERSTATUSREPOSITORY_H

#include <environmentstatus/EnvironmentStatus.h>
#include <environmentstatus/EnvironmentStatusCache.h>
#include <environmentstatus/EnvironmentStatusFactory.h>

class EnvironmentStatusRepository {
public:
    EnvironmentStatusRepository(
            EnvironmentStatusFactory &environmentStatusFactory) : environmentStatusFactory(environmentStatusFactory) {};

    EnvironmentStatus *getAll();

    EnvironmentStatus getCurrent();

    EnvironmentStatus getLast();

private:
    EnvironmentStatusCache *environmentStatusCache = EnvironmentStatusCache::getInstance();
    EnvironmentStatusFactory &environmentStatusFactory;
};

#endif