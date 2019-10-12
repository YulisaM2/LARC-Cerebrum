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
		
		break;
		case 1:
		
		myservo.write(3);
		posicion = 0;


		break;
		case 2:
		myservo.write(48);

		/*for(int pos = posicion*67+5; pos<= (i-1)*67+5;pos+=3){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			Serial.print(" Posicion: ");
			Serial.print(i);
			Serial.print("       ");
			Serial.print(" Angulo: ");
			Serial.println(pos);
			delay(tiempo);
		}*/
		posicion = 1;
		
		break;
		case 3:
		myservo.write(93);
		/*for(int pos = posicion*67+5; pos<= (i-1)*67+5;pos+=3){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			Serial.print(" Posicion: ");
			Serial.print(i);
			Serial.print("       ");
			Serial.print(" Angulo: ");
			Serial.println(pos);
			delay(tiempo);
		}*/
		posicion = 2;
		
		break;
		case 4:
		myservo.write(137);
		/*for(int pos = posicion*67+5; pos<= (i-1)*67+5;pos+=3){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			Serial.print(" Posicion: ");
			Serial.print(i);
			Serial.print("       ");
			Serial.print(" Angulo: ");
			Serial.println(pos);
			delay(tiempo);
		}*/
		posicion = 3;
		
		break;
		case 5:
		myservo.write(180);
		/*for(int pos = posicion*67+5; pos<= (i-1)*67+5;pos+=3){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			Serial.print(" Posicion: ");
			Serial.print(i);
			Serial.print("       ");
			Serial.print(" Angulo: ");
			Serial.println(pos);
			delay(tiempo);
		}*/
		posicion = 4;
		
		break;
	} 
}

void Elevador::descender(int i){
	if (i>posicion){
		Serial.println("error");
		return;
	}
	switch (i){
		
		case 1:
		myservo.write(3);
		/*for(int pos = posicion*67+5; pos>(i-1)*67+5;pos-=3){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			Serial.print(" Posicion: ");
			Serial.print(i);
			Serial.print("       ");
			Serial.print(" Angulo: ");
			Serial.println(posicion);
			delay(tiempo);
		}*/

		posicion = 0;


		break;
		case 2:
		myservo.write(48);
		/*for(int pos = posicion*67+5; pos>(i-1)*67+5;pos-=3){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			Serial.print(" Posicion: ");
			Serial.print(i);
			Serial.print("       ");
			Serial.print(" Angulo: ");
			Serial.println(posicion);
			delay(tiempo);
		}*/
		posicion = 1;
		
		break;
		case 3:
		myservo.write(93);
		/*for(int pos= posicion*67+5; pos> (i-1)*67+5;pos-=3){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			Serial.print(" Posicion: ");
			Serial.print(i);
			Serial.print("       ");
			Serial.print(" Angulo: ");
			Serial.println(pos);
			delay(tiempo);
		}*/
		posicion = 2;
		
		break;
		case 4:
		myservo.write(137);
		/*for(int pos = posicion*67+5; pos> (i-1)*67+5;pos-=3){
			posicionVdd = map(pos,0,270,0,180);
			myservo.write(posicionVdd);
			Serial.print(" Posicion: ");
			Serial.print(i);
			Serial.print("       ");
			Serial.print(" Angulo: ");
			Serial.println(pos);
			delay(tiempo);
		}*/
		posicion = 3;
		
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

void Elevador::activarIman(){
	if (bandera == true){
		Serial.println("Prender");
	digitalWrite(35,HIGH);
	digitalWrite(36,HIGH);
	bandera = false;
	}
	/*digitalWrite(36,HIGH);
	digitalWrite(35,HIGH);*/
	
	
}
void Elevador::apagarIman(){

	if (bandera == false){
	digitalWrite(35,LOW);
	digitalWrite(36,LOW);

		bandera = true;
	}
		
}
