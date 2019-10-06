
#ifndef Motor_h
#define Motor_h
#define LIBRARY_VERSION 0.1.0

class Motor {
public:

	Motor(int pin1, int pin2);
	void avanzar(int j);
	void retroceder(int i);
	void detener();
	void limpiarEncoder();
	void setVelocidad(int vel); 
	int getMotor();
	int getEncoder();
	int getVel();
	int contador;
private:
	int pin1;
	int pin2;
	int velocidad;

};
#endif
