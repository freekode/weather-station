#ifndef RamCommandExecuter_H
#define RamCommandExecuter_H

#include "CommandExecutor.h"

#include "../../adapters/SerialAdapter.h"

class RamCommandExecutor : public CommandExecutor
{
private:
    String getFreeRam()
    {
        extern int __heap_start, *__brkval;
        int v;
        int value = (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);

        return String(value);
    }

public:
    virtual void execute(SerialAdapter &serialAdapter, char *params[])
    {
        serialAdapter.println(getFreeRam());
    };
};

#endif