#ifndef _MOTOR_H
#define _MOTOR_H

#include <Arduino.h>

class Motor{
	public:
		Motor(int a, int b);

		void set(double value);
	private:
		int a;
		int b;	
};

#endif