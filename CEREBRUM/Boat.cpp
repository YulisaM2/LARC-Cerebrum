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

bool Boat::isAFull(){
	byte check = depositedAtA & maxHeight;
	return check != 0;
};

void Boat::updateDepositedAtA(){
	++depositedAtA;
	if(isAFull() && isBFull() && isCFull()){
		boatFull = boatFilled;
	}
};


byte Boat::howManyDepositedAtB(){
	return depositedAtB;
};

bool Boat::isBFull(){
	byte check = depositedAtB & maxHeight;
	return check != 0;
};

void Boat::updateDepositedAtB(){
	++depositedAtB;
	if(isAFull() && isBFull() && isCFull()){
		boatFull = boatFilled;
	}
};


byte Boat::howManyDepositedAtC(){
	return depositedAtC;
};

bool Boat::isCFull(){
	byte check = depositedAtC & maxHeight;
	return check != 0;
};

void Boat::updateDepositedAtC(){
	++depositedAtC;
	if(isAFull() && isBFull() && isCFull()){
		boatFull = boatFilled;
	}
};

bool Boat::isBoatFull(){
	byte check = boatFull & boatFilled;
	return check != 0;
}