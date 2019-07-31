#ifndef WEATHERSTATUSCACHE_H
#define WEATHERSTATUSCACHE_H

#include <environmentstatus/EnvironmentStatus.h>
#include <stdint.h>
#include <stdlib.h>

#define IN_MEMORY_DB_SIZE 10

class EnvironmentStatusCache {
public:
    static EnvironmentStatusCache *getInstance();

    void push(EnvironmentStatus environmentStatus);

    EnvironmentStatus getLast();

    EnvironmentStatus *getAll();

private:
    int currentIndex = -1;
    EnvironmentStatus storage[IN_MEMORY_DB_SIZE];
    static EnvironmentStatusCache *instance;
};

#endif