#include "Rod.h"

Rod::Rod(){
	status = 0;
	nextRod = nullptr;
};

Rod::Rod(byte bStatus){
	status = bStatus;
	nextRod = nullptr;
};

void Rod::setStatus(byte bStatus){
	status = bStatus;
};

byte Rod::getStatus(){
	return status;
};

void Rod::setNextRod(Rod &rod){
	nextRod = &rod;
};

Rod* Rod::getNextRod(){
	return nextRod;
};


// R G B Blocked 0 0 0 0
// 128 64 32 16 

void Rod::printRod(){
	// if(status == red){
	// 	Serial.println("Red BLOCKED");		
	// }else{
	// 	if(status == (green)){
	// 		Serial.println("Green unblocked");
	// 	}else if (status == (green | blocked)){
	// 		Serial.println("Green BLOCKED");
	// 	}else if(status == (blue)){
	// 		Serial.println("Blue unblocked");
	// 	}else if(status == (blue | blocked)){
	// 		Serial.println("Blue BLOCKED");
	// 	}else{
	// 		Serial.println("Error: No information saved or Invalid combination");
	// 	}
	// }


	if(status == red){
		Serial.println( "RED BLOCKED NOT TO BE PICKED UP!");
	}else{

		if(status == (green)){
			Serial.println("Green unblocked available");
		}else if(status == (green | blocked | pickedUp)){
			Serial.println("Green BLOCKED PICKED");
		}else if(status == (green | blocked)){
			Serial.println("Green BLOCKED available");
		}else if(status == (green | pickedUp)){
			Serial.println("Green unblocked PICKED");
		}else if(status == (blue)){
			Serial.println("Blue unblocked available");
		}else if(status == (blue | blocked | pickedUp)){
			Serial.println("Blue BLOCKED PICKED");
		}else if(status == (blue | blocked)){
			Serial.println("Blue BLOCKED available");
		}else if(status == (blue | pickedUp)){
			Serial.println("Blue unblocked PICKED");
		}else{
			Serial.println("Error: Invalid combination: ");
			Serial.println(status);
		}

	}

	delay(100);
};

void Rod::blockRod(){
	status = status | blocked;
};

bool Rod::isBlocked(){
	byte check = status & blocked;
	return check != 0;
};

void Rod::unblockRod(){
	if(isBlocked()){
		status = status - blocked;	
	}
	
};

bool Rod::wasPickedUp(){
	byte check = status & pickedUp;
	return check != 0;
};

void Rod::pickedUpRod(){
	if(!wasPickedUp()){
		status = status | pickedUp;
	}
};

void Rod::isTopOf(){
	if(nextRod != nullptr){
		Serial.print("is on top of ");
		nextRod->printRod();
	}else{
		Serial.println("No more connections, might be last rod or misconstructed");
	}
	Serial.println();
	delay(100);
}

