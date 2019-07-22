#include "InputJobExecuter.h"

void InputJobExecuter::runInternally()
{
    String input = serialAdapter.receive();
    if (input.length() == 0)
    {
        return;
    }

    char *params[PARAMS_LENGTH] = {NULL};
    parseCommand(input, params);

    String command = String(params[0]);

    CommandExecuter *commandExecuter = commandExecuterFactory.getExecuter(command);
    commandExecuter->execute(params);
}

void InputJobExecuter::parseCommand(String inpput, char *params[])
{
    char commandChar[70];
    char delims[] = " ";

    inpput.toCharArray(commandChar, 70);

    int i = 0;
    params[i] = strtok(commandChar, delims);
    while (params[i] != NULL || i == PARAMS_LENGTH)
    {
        params[++i] = strtok(NULL, delims);
    }
}
