#ifndef _MOTOR_H
#define _MOTOR_H

#include <Arduino.h>
#include <Encoder.h>

class Motor{
	public:
		Motor(int a, int b);
		Motor(int a, int b, int encoderPortA, int encoderPortB);
		void set(double value);
		int getPosition();
		void setPosition(int pos);
		double getRotations();
		void setPulsePerRotation(int pulsePerRot);
	private:
		int a;
		int b;	
		int pulsePerRot = 1;
		Encoder *encoder = nullptr;
};

#endif