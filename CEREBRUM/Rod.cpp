#include "Rod.h"

Rod::Rod(){
	status = 0;
};

Rod::Rod(byte bStatus){
	status = bStatus;
};

void Rod::setStatus(byte bStatus){
	status = bStatus;
};

byte Rod::getStatus(){
	return status;
};

// R G B Blocked 0 0 0 0
// 128 64 32 16 

// Rod rod2(B01010000); 
// Rod rod3(B01000000);
void Rod::printRod(){
	if(status == red){
		Serial.println("Red NOT accesible");		
	}else{
		if(status == (green)){
			Serial.println("Green accesible");
		}else if (status == (green | blocked)){
			Serial.println("Green NOT accesible");
		}else if(status == (blue)){
			Serial.println("Blue accesible");
		}else if(status == (blue | blocked)){
			Serial.println("Blue NOT accesible");
		}else{
			Serial.println("Error: No information saved or Invalid combination");
		}
	}

	delay(100);
};

bool Rod::isBlocked(){
	byte check = status & blocked;
	return check != 0;
};