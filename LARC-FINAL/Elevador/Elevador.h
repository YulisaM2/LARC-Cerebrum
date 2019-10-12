#ifndef Elevador_h
#define Elevador_h
#define LIBRARY_VERSION 0.1.0
#include <Servo.h>
class Elevador {
public:
	Elevador(Servo &s):myservo(s){} //PIN
	void inicializarServo(int,int,int); 
	void ascender(int);
	void descender(int);
	void setTiempo(int);
	int getPosicion();
	int getTiempo();
	void activarIman();
	void apagarIman();
private:
	int posicionVdd;
	Servo myservo;
	int tiempo;
	int posicion;
	bool bandera = true;

};
#endif
