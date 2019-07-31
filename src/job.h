#ifndef JOB_H
#define JOB_H

#define INPUT_DELAY_MS 200L
#define BT_INPUT_DELAY_MS 500L
#define TIME_DELAY_MS 1000L
#define WEATHER_DELAY_MS 60 * 1000L

#include <adapter.h>

#include "timejobexecuter/TimeJobExecuter.h"
#include "environmentjobexecuter/EnvironmentJobExecuter.h"
#include "inputjobexecuter/InputJobExecuter.h"
#include "inputjobexecuter/commandexecuter/CommandExecutorFactory.h"

EnvironmentStatusRepositoryFactory repositoryFactory = EnvironmentStatusRepositoryFactory(timeAdapter, environmentAdapter);
EnvironmentStatusRepository *repository = repositoryFactory.get();

TestCommandExecutor *testCommandExecuter = new TestCommandExecutor();
RamCommandExecutor *ramCommandExecuter = new RamCommandExecutor();
AdjustTimeCommandExecutor *adjustTimeCommandExecuter = new AdjustTimeCommandExecutor(timeAdapter);
EnvironmentCommandExecutor *environmentCommandExecuter = new EnvironmentCommandExecutor(*repository);
CommandExecutorFactory commandExecuterFactory = CommandExecutorFactory(testCommandExecuter, ramCommandExecuter,
                                                                       adjustTimeCommandExecuter, environmentCommandExecuter);

InputJobExecuter inputJobExecuter(INPUT_DELAY_MS, softwareSerial, commandExecuterFactory);
InputJobExecuter btInputJobExecuter(BT_INPUT_DELAY_MS, bluetoothSerial, commandExecuterFactory);
TimeJobExecuter timeJobExecuter(TIME_DELAY_MS, screenAdapter, timeAdapter);
EnvironmentJobExecuter environmentJobExecuter(WEATHER_DELAY_MS, screenAdapter, *repository);

#endif