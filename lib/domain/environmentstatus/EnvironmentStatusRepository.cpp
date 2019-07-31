#include <environmentstatus/EnvironmentStatusRepository.h>

EnvironmentStatus *EnvironmentStatusRepository::getAll()
{
    return environmentStatusCache.getAll();
}

EnvironmentStatus EnvironmentStatusRepository::getCurrent()
{
    EnvironmentStatus environmentStatus = environmentStatusFactory.get();
    environmentStatusCache.push(environmentStatus);
    return getLast();
}

EnvironmentStatus EnvironmentStatusRepository::getLast()
{
    return environmentStatusCache.getLast();
}
