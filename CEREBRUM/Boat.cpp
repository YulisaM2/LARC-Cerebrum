#include "Boat.h"

Boat::Boat(){
	depositedAtA = 0;
	depositedAtB = 0;
	depositedAtC = 0;
	boatFull = 0;
};

byte Boat::howManyDepositedAtA(){
	return depositedAtA;
};

void Boat::updateDepositedAtA(){
	++depositedAtA;
	if(depositedAtA == (maxHeight) && depositedAtB == (maxHeight) && depositedAtC == (maxHeight)){
		boatFull = boatFilled;
	}
};

byte Boat::howManyDepositedAtB(){
	return depositedAtB;
};

void Boat::updateDepositedAtB(){
	++depositedAtB;
	if(depositedAtB == (maxHeight) && depositedAtA == (maxHeight) && depositedAtC == (maxHeight)){
		boatFull = boatFilled;
	}
};

byte Boat::howManyDepositedAtC(){
	return depositedAtC;
};

void Boat::updateDepositedAtC(){
	++depositedAtC;
	if(depositedAtC == (maxHeight) && depositedAtB == (maxHeight) && depositedAtA == (maxHeight)){
		boatFull = boatFilled;
	}
};

bool Boat::isBoatFull(){
	byte check = boatFull & boatFilled;
	return check != 0;
}