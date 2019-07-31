#include "EnvironmentJobExecuter.h"

void EnvironmentJobExecuter::runInternally()
{
    EnvironmentStatus environmentStatus = environmentStatusRepository.getCurrent();
    screenAdapter.printSatus(environmentStatus);
}