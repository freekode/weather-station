#ifndef InputJobExecuter_H
#define InputJobExecuter_H

#include <jobexecuter/IntervalJobExecuter.h>
#include "../adapters/SerialAdapter.h"
#include "inputjobexecuter/commandexecuter/CommandExecutorFactory.h"

class InputJobExecuter : public IntervalJobExecuter {
private:
    SerialAdapter &serialAdapter;
    CommandExecutorFactory &commandExecuterFactory;

    static void parseCommand(const String &input, char *params[]);

public:
    InputJobExecuter(
            long interval_ms,
            SerialAdapter &serialAdapter,
            CommandExecutorFactory &commandExecuterFactory) : IntervalJobExecuter(interval_ms),
                                                              serialAdapter(serialAdapter),
                                                              commandExecuterFactory(commandExecuterFactory) {};

protected:
    void runInternally() override;
};

#endif