#include <environmentstatus/EnvironmentStatusRepositoryFactory.h>

EnvironmentStatusRepository *EnvironmentStatusRepositoryFactory::get()
{
    EnvironmentStatusFactory *factory = new EnvironmentStatusFactory(timeAdapter, environmentAdapter);
    EnvironmentStatusCache *cache = EnvironmentStatusCache::getInstance();

    EnvironmentStatusRepository *repository = new EnvironmentStatusRepository(*cache, *factory);
    return repository;
}
