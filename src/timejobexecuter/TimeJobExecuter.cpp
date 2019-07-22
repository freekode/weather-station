#include "TimeJobExecuter.h"

void TimeJobExecuter::runInternally()
{
    screenAdapter.printDateTime(timeAdapter.getDateWithoutYearStr(), timeAdapter.getTimeStr());
}