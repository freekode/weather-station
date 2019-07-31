#ifndef EnvironmentCommandExecuter_H
#define EnvironmentCommandExecuter_H

#include <environmentstatus/EnvironmentStatusRepository.h>
#include "CommandExecutor.h"
#include "../../adapters/SerialAdapter.h"

class EnvironmentCommandExecutor : public CommandExecutor {
private:
    EnvironmentStatusRepository &environmentStatusRepository;

public:
    explicit EnvironmentCommandExecutor(
            EnvironmentStatusRepository &environmentStatusRepository) : environmentStatusRepository(
            environmentStatusRepository) {};

    void execute(SerialAdapter &serialAdapter, char *params[]) override {
        EnvironmentStatus environmentStatus = environmentStatusRepository.getLast();
        serialAdapter.println(environmentStatus.toString());
    };
};

#endif