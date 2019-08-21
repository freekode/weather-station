#ifndef CommandExecuterFactory_H
#define CommandExecuterFactory_H

#include <Arduino.h>
#include "CommandExecutor.h"
#include "../../adapters/SerialAdapter.h"
#include "TestCommandExecutor.h"
#include "RamCommandExecutor.h"
#include "AdjustTimeCommandExecutor.h"
#include "EnvironmentCommandExecutor.h"
#include "UptimeCommandExecutor.h"

class CommandExecutorFactory {
private:
    TestCommandExecutor *testCommandExecuter;
    RamCommandExecutor *ramCommandExecuter;
    AdjustTimeCommandExecutor *adjustTimeCommandExecuter;
    EnvironmentCommandExecutor *environmentCommandExecuter;
    UptimeCommandExecutor *uptimeCommandExecutor;

public:
    CommandExecutorFactory(
            TestCommandExecutor *testCommandExecuter,
            RamCommandExecutor *ramCommandExecuter,
            AdjustTimeCommandExecutor *adjustTimeCommandExecuter,
            EnvironmentCommandExecutor *environmentCommandExecuter,
            UptimeCommandExecutor *uptimeCommandExecutor) :
            testCommandExecuter(testCommandExecuter),
            ramCommandExecuter(ramCommandExecuter),
            adjustTimeCommandExecuter(adjustTimeCommandExecuter),
            environmentCommandExecuter(environmentCommandExecuter),
            uptimeCommandExecutor(uptimeCommandExecutor) {};

    CommandExecutor *getExecutor(const String &);
};

#endif