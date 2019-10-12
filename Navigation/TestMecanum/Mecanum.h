// Ejemplo estructura control mecanum

#ifndef _MECANUM_H
#define _MECANUM_H

#include "MecanumMotorValues.h"

class Mecanum{
	private:
		double a;
		double b;

	public:
		Mecanum(double a, double b);
		MecanumMotorValues calcInverseKinematics(double vX, double vY, double w);
};

#endif