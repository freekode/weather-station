#include "BacklightOnJobExecutor.h"

void BacklightOnJobExecutor::runInternally() {
    screenAdapter.backlight(true);
}