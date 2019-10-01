#ifndef _DRIVETRAIN_h
#define _DRIVETRAIN_h

#include "Masks.h"

// This class will be used to simulate the robot
// With this object we will execute the routine to follow a path depending on the decision made by Pathfinding
// 	--------------------------------------
// |	  		  		            	  |
// |	1| |3		5| |7		 9|	|11	  |
// |	2| |4		6| |8		10|	|12   |
//`|									  |
// |	  G2					  B2	  |
// |	 ---		Center		  ---	  |
// | G3	|	| G1	  --	  B1 |.  | B3 |
// |	|	|.  	 ||||		 |	 | 	  |
// 	--------------------------------------

class DriveTrain{
	public:

		DriveTrain();

		// Calculate where the robot is now with motors, spins, lines crossed, etc.
		void calPosition();
		byte getCurrPosition();
		void setCurrPosition(byte status); // for debugging 

		// Starting routine for taking pictures
		void pathForPictures();

		// Path to stacks that can be accessed with the elevator in the right
		void pathToPosition1();
		void pathToPosition2();

		void pathToPosition5();
		void pathToPosition6();

		void pathToPosition9();
		void pathToPosition10();

		// Path to stacks that can be accessed with the elevator in the left
		void pathToPosition3();
		void pathToPosition4();

		void pathToPosition7();
		void pathToPosition8();

		void pathToPosition11();
		void pathToPosition12();

		// Path to Boats
		void pathToBoatBlueA();
		void pathToBoatBlueB();
		void pathToBoatBlueC();
		void pathToBoatGreenA();
		void pathToBoatGreenB();
		void pathToBoatGreenC();

		// Path to center 
		void pathToCenter();

	private: 
		byte currPosition; // Used to estimate which stack is closest to the current position of the robot

};

#endif