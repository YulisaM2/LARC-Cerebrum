#include "Mecanum.h"


Mecanum::Mecanum(double a,double b){
	this->a = a; // .8
	this->b = b; // 1
};

// Por simpleza utilizar -1 y 1 para los valores
// -1 para atras
// 1 para adelante
// Si algun valor se pasa normalizarlo para que sea consitente : Ahorita no se incluye eso pero se podria implementar
MecanumMotorValues Mecanum::calcInverseKinematics(double vX, double vY, double w){
	MecanumMotorValues values;

	// values.motorTopRightSpeed = vX + vY + (a*w)+ (b*w);
	// values.motorTopLeftSpeed = vX - vY - (a*w) - (b*w);
	// values.motorBottomRightSpeed = vX - vY + (a*w) + (b*w);
	// values.motorBottomLeftSpeed = vX + vY - (a*w) - (b*w);;

	values.motorBottomRightSpeed = vY + vX + (a*w)+ (b*w);
	values.motorBottomLeftSpeed = vY - vX - (a*w) - (b*w);
	values.motorTopRightSpeed = vY - vX + (a*w) + (b*w);
	values.motorTopLeftSpeed = vY + vX - (a*w) - (b*w);;
	return values;

};
