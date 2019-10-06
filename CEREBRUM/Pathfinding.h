#ifndef _PATHFINDING_h
#define _PATHFINDING_h

#include "Masks.h"
#include "DriveTrain.h"
#include "Field.h"

class Pathfinding{
	public:
		Pathfinding();

		void startingRoutine();
		void closingRoutine();

		// The most efficient path is the one with the lowest cost when doing a pickup and drop off
		// Hence, we need to calculate the cost from the current position of the robot to the stacks and the cost from their top rod to their designated drop off
		// The path with the lowest cost is the best one
		double manhattanDistance(double x1, double y1, double x2, double y2);
		double calcRobotCost(double x, double y);
		double calcColorCost(double stackX, double stackY, double boatX, double boatY); 
		double calcTotalCost(double stackX, double stackY, double boatX, double boatY);

		void executePickUp(Field &field, byte stack); // Paths for stacks
		void executeDropOff(byte path, byte height); // Paths for boats/deposit areas

	 	void initializer(Field &field);
		// void calculateNextPath(Field &field); 
		void calculateNextPathNoPointers(Field &field); // Calculate which rod to pick up that takes the least effort
		
		void mainAlgorithm(Field &field); // Loop iterations of path calculation and execution until the map is completed
	private:
		DriveTrain driveTrain; 
};

#endif
