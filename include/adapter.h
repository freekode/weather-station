#ifndef ADAPTER_H
#define ADAPTER_H

#include <WeatherStatusRepositoryFactory.h>
#include "adapters/ScreenAdapter.h"
#include "adapters/SerialAdapter.h"
#include "adapters/BTAdapter.h"
#include "adapters/RTCTimeAdapter.h"
#include "adapters/SensorsWeatherAdapter.h"

ScreenAdapter screenAdapter;

SerialAdapter softwareSerial(Serial);

AltSoftSerial BTSerial;
BTAdapter bluetoothSerial(BTSerial);

RTCTimeAdapter timeAdapter;

SensorsWeatherAdapter weatherAdapter;

#endif