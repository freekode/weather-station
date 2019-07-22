#ifndef BTAdapter_H
#define BTAdapter_H

#include <Arduino.h>
#include <AltSoftSerial.h>
#include "SerialAdapter.h"

class BTAdapter : public SerialAdapter
{
	String inputString = "";
	boolean inputComplete = false;

public:
	BTAdapter(Stream &serial) : SerialAdapter(serial){};
	void sendAtCommand(const char *command);
	String receive() override;
};

#endif
