#ifndef TestCommandExecuter_H
#define TestCommandExecuter_H

#include "CommandExecutor.h"

#include "../../adapters/SerialAdapter.h"

class TestCommandExecutor : public CommandExecutor {
private:
public:
    void execute(SerialAdapter &serialAdapter, char *params[]) override {
        serialAdapter.println("true");
    };
};

#endif