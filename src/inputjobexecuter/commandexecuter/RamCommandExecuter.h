#ifndef RamCommandExecuter_H
#define RamCommandExecuter_H

#include "CommandExecuter.h"

#include "../../adapters/SerialAdapter.h"

class RamCommandExecuter : public CommandExecuter
{
private:
    SerialAdapter &serialAdapter;
    String getFreeRam()
    {
        extern int __heap_start, *__brkval;
        int v;
        int value = (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);

        return String(value);
    }

public:
    RamCommandExecuter(SerialAdapter &serialAdapter) : serialAdapter(serialAdapter){};
    virtual void execute(char *params[])
    {
        serialAdapter.println(getFreeRam());
    };
};

#endif