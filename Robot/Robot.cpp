#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Robot.h>



void Robot::avanzar(int pwm){
	Serial.println("Avanzar");
	motorIF.avanzar(pwm);
	motorIA.avanzar(pwm);
	motorDF.avanzar(pwm);
	motorDA.avanzar(pwm);
}
void Robot::detener(){
	motorIF.detener();
	motorIA.detener();
	motorDF.detener();
	motorDA.detener();
}
void Robot::moverIzq(int pwm){
	motorIF.retroceder(pwm);
	motorIA.avanzar(pwm);
	motorDF.avanzar(pwm);
	motorDA.retroceder(pwm);
}

void Robot::moverDer(int pwm){
	motorIF.avanzar(pwm);
	motorIA.retroceder(pwm);
	motorDF.retroceder(pwm);
	motorDA.avanzar(pwm);
}

void Robot::retroceder(int pwm){
	motorIF.retroceder(pwm);
	motorIA.retroceder(pwm);
	motorDF.retroceder(pwm);
	motorDA.retroceder(pwm);
}
void Robot::masDerecha(int i, int j){
	motorIF.avanzar(i);
	motorIA.avanzar(i);
	motorDF.avanzar(i+j);
	motorDA.avanzar(i+j);
}
void Robot::masIzquierda(int i, int j){
	motorIF.avanzar(i+j);
	motorIA.avanzar(i+j);
	motorDF.avanzar(i);
	motorDA.avanzar(i);
}

void Robot::avanzarEncoder(int valor ,int pwm ){
	motorDA.limpiarEncoder();
	motorIA.limpiarEncoder();
	motorDF.limpiarEncoder();
	motorIF.limpiarEncoder();
	while(motorIA.contador<valor){
		avanzar(pwm);
		Serial.print(" ENCODER: ");
    	Serial.println(motorIA.contador);
	}
}


