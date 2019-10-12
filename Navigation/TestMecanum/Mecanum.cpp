#include "Mecanum.h"


Mecanum::Mecanum(double a,double b, double wheelRadius){
	this->a = a; // .8
	this->b = b; // 1
	this->wheelRadius = wheelRadius;
};

// Por simpleza utilizar -1 y 1 para los valores
// -1 para atras
// 1 para adelante
// Si algun valor se pasa normalizarlo para que sea consitente : Ahorita no se incluye eso pero se podria implementar
MecanumMotorValues Mecanum::calcInverseKinematics(double vX, double vY, double w){
	MecanumMotorValues values;

	values.motorTopRightSpeed = vX - vY + w;
	values.motorTopLeftSpeed = vX + vY - w;
	values.motorBottomRightSpeed = vX + vY + w;
	values.motorBottomLeftSpeed = vX - vY - w;
	return values;

};

Twist2D Mecanum::calcKinematics(MecanumCurrentState state){
	Twist2D twist;
	twist.dX = (wheelRadius / 4) * (state.topRightAngular + state.topLeftAngular + state.bottomRightAngular + state.bottomLeftAngular);
	twist.dY = (wheelRadius / 4) * (state.topRightAngular - state.topLeftAngular - state.bottomRightAngular + state.bottomLeftAngular);
	twist.dTheta = (wheelRadius * (state.topRightAngular - state.topLeftAngular + state.bottomRightAngular - state.bottomLeftAngular))  / (4 * (a + b));
}
