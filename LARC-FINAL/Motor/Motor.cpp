#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Motor.h>

Motor::Motor(int pinA, int pinB){
	pin1 = pinA;
	pin2 = pinB;
	velocidad = 0;
	contador = 0;
}

void Motor::avanzar(int j){
	velocidad = j;
	analogWrite(pin1,velocidad);
	analogWrite(pin2, 0);
}

void Motor::retroceder(int i){
	velocidad = i;
	analogWrite(pin1,0);
	analogWrite(pin2, velocidad);
}
void Motor::detener(){
	velocidad = 0;
	analogWrite(pin1,0);
	analogWrite(pin2,0);
}
void Motor::limpiarEncoder(){
	contador = 0;
}
void Motor::setVelocidad(int velocidad){
	this->velocidad = velocidad;
}
int Motor::getEncoder(){
	return contador;
}
int Motor::getVel(){
	return velocidad;
}
