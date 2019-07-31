#include <environmentstatus/EnvironmentStatusFactory.h>

EnvironmentStatus EnvironmentStatusFactory::get() const {
    return EnvironmentStatus(
            timeAdapter.timestamp(),
            environmentAdapter.temperature(),
            environmentAdapter.humidity(),
            environmentAdapter.pressure());
}
