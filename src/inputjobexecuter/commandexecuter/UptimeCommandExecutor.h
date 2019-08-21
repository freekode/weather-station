#ifndef UptimeCommandExecutor_h
#define UptimeCommandExecutor_h

#include "CommandExecutor.h"
#include <Arduino.h>

#include "../../adapters/SerialAdapter.h"

class UptimeCommandExecutor : public CommandExecutor {
private:
public:
    void execute(SerialAdapter &serialAdapter, char *params[]) override {
        serialAdapter.println(millis() / 1000);
    };
};

#endif