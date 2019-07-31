#ifndef TestCommandExecuter_H
#define TestCommandExecuter_H

#include "CommandExecutor.h"

#include "../../adapters/SerialAdapter.h"

class TestCommandExecutor : public CommandExecutor
{
private:
public:
    virtual void execute(SerialAdapter &serialAdapter, char *params[])
    {
        serialAdapter.println("passed");
    };
};

#endif