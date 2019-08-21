#include "CommandExecutorFactory.h"

CommandExecutor *CommandExecutorFactory::getExecutor(const String &command) {
    if (command.equals(F("test"))) {
        return testCommandExecuter;
    } else if (command.equals(F("ram"))) {
        return ramCommandExecuter;
    } else if (command.equals(F("settime"))) {
        return adjustTimeCommandExecuter;
    } else if (command.equals(F("environment"))) {
        return environmentCommandExecuter;
    } else if (command.equals(F("uptime"))) {
        return environmentCommandExecuter;
    }

    return nullptr;
}