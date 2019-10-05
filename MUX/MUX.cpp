#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <MUX.h>

void MUX::inicializarMUX(){
	pinMode(pin1,OUTPUT);
	pinMode(pin2,OUTPUT);
	pinMode(pin3,OUTPUT);
	
}

MUX::valor(int i){
	
    r0 = bitRead(i,0);    // use this with arduino 0013 (and newer versions)     

    r1 = bitRead(i,1);    // use this with arduino 0013 (and newer versions)     

    r2 = bitRead(i,2);    // use this with arduino 0013 (and newer versions)     

    digitalWrite(pin1, r0);

    digitalWrite(pin2, r1);

    digitalWrite(pin3, r2);
    //Serial.print(" i:    ");
    //Serial.println(count);

    val[i] = analogRead(analogico);
    
}

