#include "BacklightOffJobExecutor.h"

void BacklightOffJobExecutor::runInternally() {
    screenAdapter.backlight(false);
}