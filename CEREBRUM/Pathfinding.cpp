#include "Pathfinding.h"

Pathfinding::Pathfinding(){
	robotOrientation = 0;
};


byte Pathfinding::getRobotOrientation(){
	return robotOrientation;
};

void Pathfinding::setRobotOrientation(byte status){
	robotOrientation = status;
};


// Calculate which rod to pick up that takes the least effort
void Pathfinding::calculateNextPath(Field &map){




};

void Pathfinding::executePath(byte path){
	switch(path){
		case pathToPosition1:
			driveTrain.pathToPosition1();
			break;
		case pathToPosition2:
			driveTrain.pathToPosition2();
			break;
		case pathToPosition3:
			driveTrain.pathToPosition3();
			break;
		case pathToPosition4:
			driveTrain.pathToPosition4();
			break;
		case pathToPosition5:
			driveTrain.pathToPosition5();
			break;
		case pathToPosition6:
			driveTrain.pathToPosition6();
			break;
		case pathToPosition7:
			driveTrain.pathToPosition7();
			break;
		case pathToPosition8:
			driveTrain.pathToPosition8();
			break;
		case pathToPosition9:
			driveTrain.pathToPosition9();
			break;
		case pathToPosition10:
			driveTrain.pathToPosition10();
			break;
		case pathToPosition11:
			driveTrain.pathToPosition11();
			break;
		case pathForPictures:
			driveTrain.pathForPictures();
			break;
		case pathToButton:
			driveTrain.pathToButton();
			break;
	}

};