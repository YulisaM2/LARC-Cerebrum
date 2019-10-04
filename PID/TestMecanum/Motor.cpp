#include "Motor.h"

Motor::Motor(int a, int b){
	this->a = a;
	this->b = b;
	pinMode(a, OUTPUT);
	pinMode(b, OUTPUT);

	analogWrite(a, 0);
	analogWrite(b, 0);
};

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