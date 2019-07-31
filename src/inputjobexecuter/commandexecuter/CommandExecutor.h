#ifndef CommandExecuter_H
#define CommandExecuter_H

#include "../../adapters/SerialAdapter.h"

class CommandExecutor
{
public:
    virtual void execute(SerialAdapter &serialAdapter, char *params[]) = 0;
};

#endif