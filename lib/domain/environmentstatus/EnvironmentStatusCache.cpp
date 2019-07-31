#include <environmentstatus/EnvironmentStatusCache.h>
#include <Arduino.h>

EnvironmentStatusCache *EnvironmentStatusCache::instance = nullptr;

EnvironmentStatusCache *EnvironmentStatusCache::getInstance() {
    {
        if (!instance) {
            instance = new EnvironmentStatusCache;
        }
        return instance;
    };
}

void EnvironmentStatusCache::push(EnvironmentStatus environmentStatus) {
    if (currentIndex >= (IN_MEMORY_DB_SIZE - 1)) {
        currentIndex = -1;
    }

    currentIndex++;
    storage[currentIndex] = environmentStatus;
}

EnvironmentStatus EnvironmentStatusCache::getLast() {
    return storage[currentIndex];
}

EnvironmentStatus *EnvironmentStatusCache::getAll() {
    return storage;
}