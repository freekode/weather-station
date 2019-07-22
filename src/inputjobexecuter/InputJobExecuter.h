#ifndef InputJobExecuter_H
#define InputJobExecuter_H

#include <IntervalJobExecuter.h>
#include "../adapters/SerialAdapter.h"
#include "commandexecuter/CommandExecuterFactory.h"

class InputJobExecuter : public IntervalJobExecuter
{
private:
    int PARAMS_LENGTH = 30;
    SerialAdapter &serialAdapter;
    CommandExecuterFactory &commandExecuterFactory;
    void parseCommand(String input, char *params[]);

public:
    InputJobExecuter(
        long interval_ms,
        SerialAdapter &serialAdapter,
        CommandExecuterFactory &commandExecuterFactory) : IntervalJobExecuter(interval_ms),
                                                          serialAdapter(serialAdapter),
                                                          commandExecuterFactory(commandExecuterFactory){};

protected:
    virtual void runInternally();
};

#endif