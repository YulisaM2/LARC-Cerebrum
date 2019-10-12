// Ejemplo estructura control mecanum

#ifndef _MECANUM_H
#define _MECANUM_H

#include "MecanumMotorValues.h"
#include "MecanumCurrentState.h"
#include "Twist2D.h"

class Mecanum{
	private:
		double a;
		double b;
		double wheelRadius;

	public:
		Mecanum(double a, double b, double wheelRadius);
		MecanumMotorValues calcInverseKinematics(double vX, double vY, double w);
		Twist2D calcKinematics(MecanumCurrentState state);
};

#endif