
#ifndef MUX_h
#define MUX_h
#define LIBRARY_VERSION 0.1.0

class MUX{

public:
	MUX(int i ,int j ,int k ,int l): pin1(i),pin2(j),pin3(k),analogico(l){}
	void inicializarMUX();
	void valor(int);
	int val[6] = {};

private:
	int pin1,pin2,pin3,r0,r1,r2;
	int analogico;


};
#endif