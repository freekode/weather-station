#ifndef ADAPTER_H
#define ADAPTER_H

#include <AltSoftSerial.h>
#include <environmentstatus/EnvironmentStatusRepositoryFactory.h>
#include "adapters/ScreenAdapter.h"
#include "adapters/SerialAdapter.h"
#include "adapters/RTCTimeAdapter.h"
#include "adapters/SensorsEnvironmentAdapter.h"

ScreenAdapter screenAdapter = ScreenAdapter();

SerialAdapter softwareSerial = SerialAdapter(Serial);

AltSoftSerial BTSerial = AltSoftSerial();
SerialAdapter bluetoothSerial = SerialAdapter(BTSerial);

RTCTimeAdapter timeAdapter = RTCTimeAdapter();

SensorsEnvironmentAdapter environmentAdapter = SensorsEnvironmentAdapter();

#endif