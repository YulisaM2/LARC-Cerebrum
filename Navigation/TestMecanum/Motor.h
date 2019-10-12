#ifndef _MOTOR_H
#define _MOTOR_H

#include <Arduino.h>

class Motor{
	public:
		Motor(int a, int b);
		Motor(int a, int b, int encoderPortA, int encoderPortB);
	
		void set(double value);
	private:
		int a;
		int b;	
		int encoderPortA = 0;
		int encoderPortB = 0;
		int encoderCounter = 0;
};

#endif