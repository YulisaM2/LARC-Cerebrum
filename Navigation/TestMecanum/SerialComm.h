#ifndef _SerialComms_H
#define _SerialComm_H

#include "Arduino.h"
#include "Absis.h"
#include "Stack.h"

class SerialComm{
	public:
		SerialComm();
		Absis<Stack> takePictureLeft();
		Absis<Stack> takePictureRight();
	private:
		Absis<Stack> buildingStacks(Absis<char> data);
};

#endif