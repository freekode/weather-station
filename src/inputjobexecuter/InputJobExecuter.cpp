#include "InputJobExecuter.h"

#define PARAMS_LENGTH 30

void InputJobExecuter::runInternally() {
    String input = serialAdapter.receive();
    if (input.length() == 0) {
        return;
    }

    // debug
    Serial.print("input=");
    Serial.println(input);

    char *params[PARAMS_LENGTH] = {nullptr};
    parseCommand(input, params);

    String command = String(params[0]);

    CommandExecutor *commandExecutor = commandExecuterFactory.getExecutor(command);
    if (commandExecutor != nullptr) {
        commandExecutor->execute(serialAdapter, params);
    }
}


void InputJobExecuter::parseCommand(const String &input, char *params[]) {
    char commandChar[70];
    char delims[] = " ";

    input.toCharArray(commandChar, 70);

    int i = 0;
    params[i] = strtok(commandChar, delims);
    while (params[i] != nullptr || i == PARAMS_LENGTH) {
        params[++i] = strtok(nullptr, delims);
    }
}
