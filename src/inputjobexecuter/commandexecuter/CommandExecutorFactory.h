#ifndef CommandExecuterFactory_H
#define CommandExecuterFactory_H

#include <Arduino.h>
#include "CommandExecutor.h"
#include "../../adapters/SerialAdapter.h"
#include "TestCommandExecutor.h"
#include "RamCommandExecutor.h"
#include "AdjustTimeCommandExecutor.h"
#include "EnvironmentCommandExecutor.h"

class CommandExecutorFactory
{
private:
    TestCommandExecutor *testCommandExecuter;
    RamCommandExecutor *ramCommandExecuter;
    AdjustTimeCommandExecutor *adjustTimeCommandExecuter;
    EnvironmentCommandExecutor *environmentCommandExecuter;

public:
    CommandExecutorFactory(
            TestCommandExecutor *testCommandExecuter,
            RamCommandExecutor *ramCommandExecuter,
            AdjustTimeCommandExecutor *adjustTimeCommandExecuter,
            EnvironmentCommandExecutor *environmentCommandExecuter) : testCommandExecuter(testCommandExecuter),
                                                                      ramCommandExecuter(ramCommandExecuter),
                                                                      adjustTimeCommandExecuter(adjustTimeCommandExecuter),
                                                                      environmentCommandExecuter(environmentCommandExecuter){};
    CommandExecutor *getExecutor(const String& command);
};

#endif