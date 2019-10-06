#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Elevador.h>


void Elevador::inicializarServo(int i,int j,int l){
	myservo.attach(i,j,l);
}
void Elevador::ascender(int i){
	switch (i){
		case 0:
		posicion = 0;
		myservo.write(0);
		
		break;
		case 1:
		for(int pos = posicion*54; pos<= i*54;pos++){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			delay(tiempo);
		}
		posicion = 1;


		break;
		case 2:
		for(int pos = posicion*54; pos<= i*54;pos++){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			delay(tiempo);
		}
		posicion = 2;
		
		break;
		case 3:
		for(int pos = posicion*54; pos<= i*54;pos++){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			delay(tiempo);
		}
		posicion = 3;
		
		break;
		case 4:
		for(int pos = posicion*54; pos<= i*54;pos++){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			delay(tiempo);
		}
		posicion = 4;
		
		break;
		case 5:
		for(int pos = posicion*54; pos<= i*54;pos++){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			delay(tiempo);
		}
		posicion = 5;
		
		break;
	} 
}

void Elevador::descender(int i){
	if (i>posicion){
		Serial.println("error");
		return;
	}
	switch (i){
		case 0:
		posicion = 0;
		myservo.write(0);
		
		break;
		case 1:
		for(int pos = posicion*54; pos>i*54;pos--){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			delay(tiempo);
		}
		posicion = 1;


		break;
		case 2:
		for(int pos = posicion*54; pos> i*54;pos--){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			delay(tiempo);
		}
		posicion = 2;
		
		break;
		case 3:
		for(int pos= posicion*54; pos> i*54;pos--){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			delay(tiempo);
		}
		posicion = 3;
		
		break;
		case 4:
		for(int pos = posicion*54; pos> i*54;pos--){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			delay(tiempo);
		}
		posicion = 4;
		
		break;
		case 5:
		for(int pos = posicion*54; pos> i*54;pos--){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			delay(tiempo);
		}
		posicion = 5;
		
		break;
	} 
}

void Elevador::setTiempo(int tiempo){
	this->tiempo = tiempo;
}


int Elevador::getTiempo(){
	return tiempo;
}
int Elevador::getPosicion(){
	return posicion;
}
