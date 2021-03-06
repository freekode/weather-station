#ifndef AdjustTimeCommandExecuter_H
#define AdjustTimeCommandExecuter_H

#include "CommandExecutor.h"
#include "../../adapters/SerialAdapter.h"
#include "../../adapters/RTCTimeAdapter.h"

class AdjustTimeCommandExecutor : public CommandExecutor {
private:
    TimeAdapter &timeAdapter;

public:
    explicit AdjustTimeCommandExecutor(TimeAdapter &timeAdapter) : timeAdapter(timeAdapter) {};

    void execute(SerialAdapter &serialAdapter, char *params[]) override {
        uint16_t year = (uint16_t) atoi(params[1]);
        uint8_t month = (uint8_t) atoi(params[2]);
        uint8_t day = (uint8_t) atoi(params[3]);
        uint8_t hour = (uint8_t) atoi(params[4]);
        uint8_t min = (uint8_t) atoi(params[5]);
        uint8_t sec = (uint8_t) atoi(params[6]);

        timeAdapter.adjust(year, month, day, hour, min, sec);
    };
};

#endif