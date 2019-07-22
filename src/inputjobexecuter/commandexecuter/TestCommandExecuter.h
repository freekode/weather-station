#ifndef TestCommandExecuter_H
#define TestCommandExecuter_H

#include "CommandExecuter.h"

#include "../../adapters/SerialAdapter.h"

class TestCommandExecuter : public CommandExecuter
{
private:
    SerialAdapter &serialAdapter;

public:
    TestCommandExecuter(SerialAdapter &serialAdapter) : serialAdapter(serialAdapter){};
    virtual void execute(char *params[])
    {
        serialAdapter.println("passed");
    };
};

#endif