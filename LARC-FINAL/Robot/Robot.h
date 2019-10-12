
#ifndef Robot_h
#define Robot_h
#define LIBRARY_VERSION 0.1.0
#include <Motor.h>
class Robot {
public:
	Robot(Motor m1, Motor m2, Motor  m3, Motor  m4) :motorIF(m1),motorDF(m2),motorDA(m3),motorIA(m4) {}
	void avanzar(int);
	void moverIzq(int);
	void moverDer(int);
	void girarDer(int);
	void girarIzq(int);
	void retroceder(int);
	void detener();
	void cambiarVelocidad(int);
	void masDerecha(int,int);
	void masIzquierda(int,int);
	void avanzarEncoder(int,int);

	

private:
	Motor motorIF;
	Motor motorIA;
	Motor motorDF;
	Motor motorDA;
};
#endif
