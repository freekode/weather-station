#ifndef CommandExecuterFactory_H
#define CommandExecuterFactory_H

#include <Arduino.h>
#include "CommandExecuter.h"
#include "../../adapters/SerialAdapter.h"
#include "TestCommandExecuter.h"
#include "RamCommandExecuter.h"
#include "AdjustTimeCommandExecuter.h"

class CommandExecuterFactory
{
private:
    TestCommandExecuter *testCommandExecuter;
    RamCommandExecuter *ramCommandExecuter;
    AdjustTimeCommandExecuter *adjustTimeCommandExecuter;

public:
    CommandExecuterFactory(
        TestCommandExecuter *testCommandExecuter,
        RamCommandExecuter *ramCommandExecuter,
        AdjustTimeCommandExecuter *adjustTimeCommandExecuter) : testCommandExecuter(testCommandExecuter),
                                                                ramCommandExecuter(ramCommandExecuter),
                                                                adjustTimeCommandExecuter(adjustTimeCommandExecuter){};
    CommandExecuter *getExecuter(String command);
};

#endif