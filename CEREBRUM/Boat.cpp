#include "Boat.h"

Boat::Boat(){
	depositedAtA = 0;
	depositedAtB = 0;
};

byte Boat::howManyDepositedAtA(){
	return depositedAtA;
};

void Boat::updateDepositedAtA(){
	++depositedAtA;
};

byte Boat::howManyDepositedAtB(){
	return depositedAtB;
};

void Boat::updateDepositedAtB(){
	++depositedAtB;
};