#include "CommandExecuterFactory.h"

CommandExecuter *CommandExecuterFactory::getExecuter(String command)
{
    if (command.equals(F("test")))
    {
        return testCommandExecuter;
    }
    else if (command.equals(F("ram")))
    {
        return ramCommandExecuter;
    }
    else if (command.equals(F("settime")))
    {
        return adjustTimeCommandExecuter;
    }

    return 0;
}