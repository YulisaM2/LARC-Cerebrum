#ifndef _PATHFINDING_h
#define _PATHFINDING_h

#include "Masks.h"
#include "DriveTrain.h"
#include "Field.h"

class Pathfinding{
	public:
		Pathfinding();

		byte getRobotOrientation();
		void setRobotOrientation(byte status); 

		void calculateNextPath(Field &map); // Calculate which rod to pick up that takes the least effort

		void executePath(byte path);
	private:
		byte robotOrientation = 0; // start with the elevator facing right
		DriveTrain driveTrain; 
};

#endif
