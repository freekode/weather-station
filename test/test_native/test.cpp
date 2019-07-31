#include <unity.h>
#include <environmentstatus/EnvironmentStatusRepositoryFactory.h>
#include <environmentstatus/EnvironmentStatusRepository.h>
#include <environmentstatus/EnvironmentStatusCache.h>
#include <environmentstatus/EnvironmentStatusRepositoryFactory.h>
#include "TestAdapters.h"

#define PARAMS_LENGTH 30

void parseCommand(String input, char *params[]) {
    char commandChar[70];
    char delims[] = " ";

    input.toCharArray(commandChar, 70);

    int i = 0;
    params[i] = strtok(commandChar, delims);
    while (params[i] != NULL || i == PARAMS_LENGTH) {
        params[++i] = strtok(NULL, delims);
    }
}


void test_repository(void) {
    // given
    TimeAdapter *timeAdapter = new TestTimeAdapter(11);
    EnvironmentAdapter *environmentAdapter = new TestEnvironmentAdapter(22, 33, 44);

    // when
    EnvironmentStatusRepositoryFactory repositoryFactory = EnvironmentStatusRepositoryFactory(*timeAdapter,
                                                                                              *environmentAdapter);
    EnvironmentStatusRepository *pRepository = repositoryFactory.get();
    EnvironmentStatusRepository &repository = *pRepository;

    EnvironmentStatus status = repository.getCurrent();

    // then
    TEST_ASSERT_EQUAL(11, status.getTimestamp());
    TEST_ASSERT_EQUAL(22, status.getTemperature());
    TEST_ASSERT_EQUAL(33, status.getHumidity());
    TEST_ASSERT_EQUAL(44, status.getPressure());
}

void test_cache(void) {
    // given
    EnvironmentStatusCache *cache = EnvironmentStatusCache::getInstance();
    EnvironmentStatus status1 = EnvironmentStatus(1, 2, 3, 4);
    EnvironmentStatus status2 = EnvironmentStatus(2, 2, 3, 4);
    EnvironmentStatus status3 = EnvironmentStatus(3, 2, 3, 4);
    EnvironmentStatus status4 = EnvironmentStatus(4, 2, 3, 4);
    EnvironmentStatus status5 = EnvironmentStatus(5, 2, 3, 4);
    EnvironmentStatus status6 = EnvironmentStatus(6, 2, 3, 4);
    EnvironmentStatus status7 = EnvironmentStatus(7, 2, 3, 4);

    // then
    cache->push(status1);
    EnvironmentStatus statusFromCache1 = cache->getLast();
    TEST_ASSERT_EQUAL(status1.getTimestamp(), statusFromCache1.getTimestamp());

    cache->push(status2);
    EnvironmentStatus statusFromCache2 = cache->getLast();
    TEST_ASSERT_EQUAL(status2.getTimestamp(), statusFromCache2.getTimestamp());

    cache->push(status3);
    EnvironmentStatus statusFromCache3 = cache->getLast();
    TEST_ASSERT_EQUAL(status3.getTimestamp(), statusFromCache3.getTimestamp());

    cache->push(status4);
    EnvironmentStatus statusFromCache4 = cache->getLast();
    TEST_ASSERT_EQUAL(status4.getTimestamp(), statusFromCache4.getTimestamp());

    cache->push(status5);
    EnvironmentStatus statusFromCache5 = cache->getLast();
    TEST_ASSERT_EQUAL(status5.getTimestamp(), statusFromCache5.getTimestamp());

    cache->push(status6);
    EnvironmentStatus statusFromCache6 = cache->getLast();
    TEST_ASSERT_EQUAL(status6.getTimestamp(), statusFromCache6.getTimestamp());

    cache->push(status7);
    EnvironmentStatus statusFromCache7 = cache->getLast();
    TEST_ASSERT_EQUAL(status7.getTimestamp(), statusFromCache7.getTimestamp());
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_repository);
    RUN_TEST(test_cache);

    UNITY_END();

    return 0;
}
