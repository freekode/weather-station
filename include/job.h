#ifndef JOB_H
#define JOB_H

#define INPUT_DELAY_MS 200L
#define TIME_DELAY_MS 1000L
#define WEATHER_DELAY_MS 60 * 1000L

#include <adapter.h>

#include "timejobexecuter/TimeJobExecuter.h"
#include "weatherjobexecuter/WeatherJobExecuter.h"
#include "inputjobexecuter/InputJobExecuter.h"
#include "inputjobexecuter/commandexecuter/CommandExecuterFactory.h"

WeatherStatusRepositoryFactory repositoryFactory(timeAdapter, weatherAdapter);
WeatherStatusRepository *repository = repositoryFactory.get();

TestCommandExecuter *testCommandExecuter = new TestCommandExecuter(softwareSerial);
RamCommandExecuter *ramCommandExecuter = new RamCommandExecuter(softwareSerial);
AdjustTimeCommandExecuter *adjustTimeCommandExecuter = new AdjustTimeCommandExecuter(softwareSerial, timeAdapter);
CommandExecuterFactory commandExecuterFactory(testCommandExecuter, ramCommandExecuter, adjustTimeCommandExecuter);

InputJobExecuter inputJobExecuter(INPUT_DELAY_MS, softwareSerial, commandExecuterFactory);
TimeJobExecuter timeJobExecuter(TIME_DELAY_MS, screenAdapter, timeAdapter);
WeatherJobExecuter weatherJobExecuter(WEATHER_DELAY_MS, screenAdapter, *repository);

#endif