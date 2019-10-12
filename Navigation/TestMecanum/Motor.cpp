#include "Motor.h"

Motor::Motor(int a, int b){
	this->a = a;
	this->b = b;
	pinMode(a, OUTPUT);
	pinMode(b, OUTPUT);

	analogWrite(a, 0);
	analogWrite(b, 0);
};

Motor::Motor(int a, int b, int encoderA, int encoderB){
	this->a = a;
	this->b = b;
	pinMode(a, OUTPUT);
	pinMode(b, OUTPUT);

	analogWrite(a, 0);
	analogWrite(b, 0);
	encoder = new Encoder(encoderA, encoderB);
}

int Motor::getPosition(){
	if(encoder == nullptr){
		return 0;
	}
	return encoder->read();
}

void Motor::setPosition(int pos){
	if(encoder == nullptr){
		return;
	}
	encoder->write(pos);
}

void Motor::set(double value){
	if(value < -1){
		value = -1;
	}

	if(value > 1){
		value = 1;
	}

	if(value > 0){
		analogWrite(a, value * 255);
		analogWrite(b, 0);
	}else{
		analogWrite(a, 0);
		analogWrite(b, abs(value * 255));
	}
};

double Motor::getRotations(){
	return (double) getPosition() / pulsePerRot;
}

void Motor::setPulsePerRotation(int pulsePerRot){
	this->pulsePerRot = pulsePerRot;
}
