#include "DriveTrain.h"

DriveTrain::DriveTrain(){
	currPosition = atCenter;
};

void DriveTrain::calPosition(){
	Serial.println("Calculating position ... ... ... ");
};

byte DriveTrain::getCurrPosition(){
	return currPosition;
};

void DriveTrain::setCurrPosition(byte status){
	currPosition = status;
};

// Starting routine for taking pictures
void DriveTrain::pathForPictures(){
	Serial.println("Taking pictures !");
};

// Path to stacks that can be accessed with the elevator in the right
void DriveTrain::pathToPosition1(){
	Serial.println("Going to stack 1");
};

void DriveTrain::pathToPosition2(){
	Serial.println("Going to stack 2");
};

void DriveTrain::pathToPosition5(){
	Serial.println("Going to stack 5");
};

void DriveTrain::pathToPosition6(){
	Serial.println("Going to stack 6");
};

void DriveTrain::pathToPosition9(){
	Serial.println("Going to stack 9");
};

void DriveTrain::pathToPosition10(){
	Serial.println("Going to stack 10");
};

// Path to stacks that can be accessed with the elevator in the left
void DriveTrain::pathToPosition3(){
	Serial.println("Going to stack 3");
};

void DriveTrain::pathToPosition4(){
	Serial.println("Going to stack 4");
};

void DriveTrain::pathToPosition7(){
	Serial.println("Going to stack 7");
};

void DriveTrain::pathToPosition8(){
	Serial.println("Going to stack 8");
};

void DriveTrain::pathToPosition11(){
	Serial.println("Going to stack 11");
};

void DriveTrain::pathToPosition12(){
	Serial.println("Going to stack 12");
};

// Path to Boats
void DriveTrain::pathToBoatBlueA(){
	Serial.println("DEPOSIT AT BOAT BLUE ZONE A");
};

void DriveTrain::pathToBoatBlueB(){
	Serial.println("DEPOSIT AT BOAT BLUE ZONE B");
};

void DriveTrain::pathToBoatBlueC(){
	Serial.println("DEPOSIT AT BOAT BLUE ZONE C");
};

void DriveTrain::pathToBoatGreenA(){
	Serial.println("DEPOSIT AT BOAT GREEN ZONE A");
};

void DriveTrain::pathToBoatGreenB(){
	Serial.println("DEPOSIT AT BOAT GREEN ZONE A");
};

void DriveTrain::pathToBoatGreenC(){
	Serial.println("DEPOSIT AT BOAT GREEN ZONE C");
};

// Path to center 
void DriveTrain::pathToCenter(){
	Serial.println("Returning to the center");
};