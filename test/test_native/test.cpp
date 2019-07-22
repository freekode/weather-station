#include <unity.h>
#include <WeatherStatusFactory.h>
#include <WeatherStatusRepository.h>
#include <WeatherStatusCache.h>
#include <WeatherStatusRepositoryFactory.h>
#include "TestAdapters.h"

void test_factory(void)
{
    TimeAdapter *timeAdapter = new TestTimeAdapter(11);
    WeatherAdapter *weatherAdapter = new TestWeatherAdapter(22, 33, 44);

    WeatherStatusRepositoryFactory *repositoryFactory =
        new WeatherStatusRepositoryFactory(*timeAdapter, *weatherAdapter);
    WeatherStatusRepository *repository = repositoryFactory->get();

    WeatherStatus status = repository->getCurrent();

    TEST_ASSERT_EQUAL(11, status.getTimestamp());
    TEST_ASSERT_EQUAL(22, status.getTemperature());
    TEST_ASSERT_EQUAL(44, status.getPressure());
    TEST_ASSERT_EQUAL(33, status.getHumidity());
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_factory);

    UNITY_END();

    return 0;
}
