#ifndef _DRIVETRAIN_h
#define _DRIVETRAIN_h

// This class will be used to simulate the robot
// With this object we will execute the routine to follow a path depending on the decision made by Pathfinding
// 	--------------------------------------
// |	  		  		            	  |
// |	1| |3		5| |7		 9|	|11	  |
// |	2| |4		6| |8		10|	|12   |
//`|									  |
// |	  B2					   A2	  |
// |	 ---		Button		  ---	  |
// |	|	| B1	  --	  A1 |.  |	  |
// |	|	|.  	 ||||		 |	 | 	  |
// 	--------------------------------------

class DriveTrain{
	public:

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
		void pathToBoatA1();
		void pathToBoatA2();
		void pathToBoatB1();
		void pathToBoatB2();

		// Path to button 
		void pathToButton();

	private: 

};

#endif