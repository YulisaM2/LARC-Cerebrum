#include "Pathfinding.h"

Pathfinding::Pathfinding(){

};


void Pathfinding::startingRoutine(){
	driveTrain.pathForPictures();
	driveTrain.setCurrPosition(finishedPictures);
	Serial.println("Starting routine completed!");
	Serial.println();
	delay(100);
};

void Pathfinding::closingRoutine(){
	Serial.println();
	driveTrain.pathToCenter();
	driveTrain.setCurrPosition(atCenter);
	Serial.println("Closing routine completed!");
};

void Pathfinding::executePickUp(Field &field, byte stack){
	Serial.print("Entro al pick up ========================= en posicion: ");
	byte pos = field.map[stack].getPosition();
	Serial.println(pos);
	switch(pos){
		case position1:
			driveTrain.pathToPosition1();
			break;
		case position2:
			driveTrain.pathToPosition2();
			break;
		case position3:
			driveTrain.pathToPosition3();
			break;
		case position4:
			driveTrain.pathToPosition4();
			break;
		case position5:
			driveTrain.pathToPosition5();
			break;
		case position6:
			driveTrain.pathToPosition6();
			break;
		case position7:
			driveTrain.pathToPosition7();
			break;
		case position8:
			driveTrain.pathToPosition8();
			break;
		case position9:
			driveTrain.pathToPosition9();
			break;
		case position10:
			driveTrain.pathToPosition10();
			break;
		case position11:
			driveTrain.pathToPosition11();
			break;
		case position12:
			driveTrain.pathToPosition12();
	}
	driveTrain.setCurrPosition(pos);
	driveTrain.pickUpElevator(field.map[stack].getCurrHeight());
	field.map[stack].topRodpickedUp();
	if(field.map[stack].isEmpty()){
		field.updateEmptyStacks();
	}

	Serial.println();
	delay(100);

};

void Pathfinding::executeDropOff(byte path, byte height){
	Serial.println("Entro al drop off ********************************");
	switch(path){
		case atBoatBlueA:
			driveTrain.pathToBoatBlueA();
			break;
		case atBoatBlueB:
			driveTrain.pathToBoatBlueB();
			break;
		case atBoatBlueC:
			driveTrain.pathToBoatBlueC();
			break;
		case atBoatGreenA:
			driveTrain.pathToBoatGreenA();
			break;
		case atBoatGreenB:
			driveTrain.pathToBoatGreenB();
			break;
		case atBoatGreenC:
			driveTrain.pathToBoatGreenC();
			break;
	}
	driveTrain.dropOffElevator(height);
	driveTrain.setCurrPosition(path);
	Serial.println();
	delay(100);
};

double Pathfinding::manhattanDistance(double x1, double y1, double x2, double y2){
	double cost = abs(x1 - x2) + abs(y1 - y2);
	return cost;
};

double Pathfinding::calcRobotCost(double x, double y){
	return manhattanDistance(driveTrain.getCurrPositionX(), driveTrain.getCurrPositionY(), x, y);
};


double Pathfinding::calcColorCost(double stackX, double stackY, double boatX, double boatY){
	return manhattanDistance(stackX, stackY, boatX, boatY);
	
};

double Pathfinding::calcTotalCost(double stackX, double stackY, double boatX, double boatY){
	double robotCost = calcRobotCost(stackX, stackY);
	double colorCost = calcColorCost(stackX, stackY, boatX, boatY);

	// Serial.print("El costo es de : ");
	// Serial.println(robotCost + colorCost);

	return robotCost + colorCost;
};

// Calculate which rod to pick up that takes the least effort and where to drop if off
// 	--------------------------------------
// |	  		  		            	  |
// |	2| |4		6| |8		10|	|12	  |
// |	1| |3		5| |7		 9|	|11   |
//`|									  |
// |	  GB					   BB	  |
// |	 ---		Center		  ---	  |
// | GC	|	| GA	  --	  BA |.  | BC |
// |	|	|.  	 ||||		 |	 | 	  |
// 	--------------------------------------

void Pathfinding::calculateNextPathNoPointers(Field &field){

	Serial.print("Current robot position : ");
	Serial.print(driveTrain.getCurrPosition());
	Serial.print(" 		( ");
	Serial.print(driveTrain.getCurrPositionX());
	Serial.print(" , ");
	Serial.print(driveTrain.getCurrPositionY());
	Serial.println(" ) ");



	if(!field.depositAreas[0].isBoatFull() && !field.depositAreas[1].isBoatFull()){

		Serial.println("Entro a que ambos estan vacios");

		byte lowestGreenStack = 13; // in case that we couldnt find one of this color both the minCost and the lowestStack values will help identify thsi case
		double minCostGreen = 20000;
		double bufferCostGreen = 0;

		for(byte currStack = 0; currStack < 12; ++currStack){
			if(field.map[currStack].getCurrHeight() != 0){
				if(field.map[currStack].getTopRodColor() == (green)){
					bufferCostGreen = calcTotalCost(field.map[currStack].getX(), field.map[currStack].getY(), field.depositAreas[0].getX(),field.depositAreas[0].getY());
					if(bufferCostGreen < minCostGreen){
						Serial.print(field.map[currStack].getX());
						Serial.print("         ");
						Serial.println(field.map[currStack].getY());
						minCostGreen = bufferCostGreen;
						lowestGreenStack = currStack;

					}
				}
			}

			delay(100);
		}

		byte lowestBlueStack = 13;
		double minCostBlue = 20000;
		double bufferCostBlue = 0;

		for(byte currStack = 0; currStack < 12; ++currStack){
			if(field.map[currStack].getCurrHeight() != 0){
				if(field.map[currStack].getTopRodColor() == (blue)){
					bufferCostBlue = calcTotalCost(field.map[currStack].getX(), field.map[currStack].getY(), field.depositAreas[1].getX(),field.depositAreas[1].getY());
					if(bufferCostBlue < minCostBlue){
						Serial.print(field.map[currStack].getX());
						Serial.print("         ");
						Serial.println(field.map[currStack].getY());
						minCostBlue = bufferCostBlue;
						lowestBlueStack = currStack;
					}
				}
			}

			delay(100);
		}

		if(lowestGreenStack == 13 && lowestBlueStack == 13){
			Serial.println();
			Serial.println("Error in class pathfinding : did not find any rod green or blue");
			field.endMatch();
		}else{


			Serial.println("Ya va a checar cual es el minimo ");

			if(minCostGreen < minCostBlue){

				Serial.println("El menor es el verde"); 

				executePickUp(field, lowestGreenStack);

				if(!field.depositAreas[0].isBFull()){

					executeDropOff(atBoatGreenB, field.depositAreas[0].howManyDepositedAtB());
					field.depositAreas[0].updateDepositedStack(atB);
				}else if(!field.depositAreas[0].isAFull()){

					executeDropOff(atBoatGreenA, field.depositAreas[0].howManyDepositedAtA());
					field.depositAreas[0].updateDepositedStack(atA);

				}else{
					executeDropOff(atBoatGreenC, field.depositAreas[0].howManyDepositedAtC());
					field.depositAreas[0].updateDepositedStack(atC);
				}

				if(field.depositAreas[0].isBoatFull()){
					field.updateDepositAreasFilled();
				}

			}else{

				Serial.println("El menor es el azul");
				Serial.println(lowestBlueStack);

				executePickUp(field, lowestBlueStack);

				if(!field.depositAreas[1].isBFull()){

					executeDropOff(atBoatBlueB, field.depositAreas[1].howManyDepositedAtB());
					field.depositAreas[1].updateDepositedStack(atB);
				}else if(!field.depositAreas[1].isAFull()){

					executeDropOff(atBoatBlueA, field.depositAreas[1].howManyDepositedAtA());
					field.depositAreas[1].updateDepositedStack(atA);

				}else{
					executeDropOff(atBoatBlueC, field.depositAreas[1].howManyDepositedAtC());
					field.depositAreas[1].updateDepositedStack(atC);
				}

				if(field.depositAreas[1].isBoatFull()){
					field.updateDepositAreasFilled();
				}

			}
		}

	}else if(!field.depositAreas[1].isBoatFull()){

		byte lowestGreenStack = 13; // in case that we couldnt find one of this color both the minCost and the lowestStack values will help identify thsi case
		double minCostGreen = 20000;
		double bufferCostGreen = 0;

		for(byte currStack = 0; currStack < 12; ++currStack){
			if(field.map[currStack].getCurrHeight() != 0){
				if(field.map[currStack].getTopRodColor() == (green)){
					bufferCostGreen = calcTotalCost(field.map[currStack].getX(), field.map[currStack].getY(), field.depositAreas[0].getX(),field.depositAreas[0].getY());
					if(bufferCostGreen < minCostGreen){
						minCostGreen = bufferCostGreen;
						lowestGreenStack = currStack;
						Serial.print(field.map[currStack].getX());
						Serial.print("         ");
						Serial.println(field.map[currStack].getY());

					}
				}
			}

			delay(100);
		}

		if(lowestGreenStack != 13){
			executePickUp(field, lowestGreenStack);

			if(!field.depositAreas[0].isBFull()){

				executeDropOff(atBoatGreenB, field.depositAreas[0].howManyDepositedAtB());
				field.depositAreas[0].updateDepositedStack(atB);
			}else if(!field.depositAreas[0].isAFull()){

				executeDropOff(atBoatGreenA, field.depositAreas[0].howManyDepositedAtA());
				field.depositAreas[0].updateDepositedStack(atA);

			}else{
				executeDropOff(atBoatGreenC, field.depositAreas[0].howManyDepositedAtC());
				field.depositAreas[0].updateDepositedStack(atC);
			}

			if(field.depositAreas[0].isBoatFull()){
				field.updateDepositAreasFilled();
			}

		}else{
			field.endMatch();
		}

	}else{

		byte lowestBlueStack = 13;
		double minCostBlue = 20000;
		double bufferCostBlue = 0;

		for(byte currStack = 0; currStack < 12; ++currStack){
			if(field.map[currStack].getCurrHeight() != 0){
				if(field.map[currStack].getTopRodColor() == (blue)){
					bufferCostBlue = calcTotalCost(field.map[currStack].getX(), field.map[currStack].getY(), field.depositAreas[1].getX(),field.depositAreas[1].getY());
					if(bufferCostBlue < minCostBlue){
						minCostBlue = bufferCostBlue;
						lowestBlueStack = currStack;
						Serial.print(field.map[currStack].getX());
						Serial.print("         ");
						Serial.println(field.map[currStack].getY());

					}
				}
			}

			delay(100);
		}

		if(lowestBlueStack != 13){

			executePickUp(field, lowestBlueStack);

			if(!field.depositAreas[1].isBFull()){

				executeDropOff(atBoatBlueB, field.depositAreas[1].howManyDepositedAtB());
				field.depositAreas[1].updateDepositedStack(atB);
			}else if(!field.depositAreas[1].isAFull()){

				executeDropOff(atBoatBlueA, field.depositAreas[1].howManyDepositedAtA());
				field.depositAreas[1].updateDepositedStack(atA);

			}else{
				executeDropOff(atBoatBlueC, field.depositAreas[1].howManyDepositedAtC());
				field.depositAreas[1].updateDepositedStack(atC);
			}

			if(field.depositAreas[1].isBoatFull()){
				field.updateDepositAreasFilled();
			}
		}else{
			field.endMatch();
		}

	}

}


void Pathfinding::initializer(Field &field){
	Serial.println("Initializing values ... ");

	for(int i = 0; i < 12; ++i){
		Serial.println(field.map[i].getPosition());
		Serial.println(field.map[i].getCurrHeight());	
	}

	for(byte currStack = 0; currStack < 12; ++currStack){
		if(field.map[currStack].getCurrHeight() == 0){
			field.updateEmptyStacks();
		}
	}

	Serial.print("Total empty stacks (top is red) : ");
	Serial.println(field.howManyStacksEmpty());

};

void Pathfinding::mainAlgorithm(Field &field){
		
	// initializer(field);
	delay(500);

	Serial.println("Starting first path ...");
	startingRoutine();

	while(!field.wasMapCompleted()){
		// calculateNextPath(field);
		calculateNextPathNoPointers(field);
	}
	closingRoutine();
};


// Had to comment this method because the arduino calculates the functions with pointers faster than it is capable of so a lot of buffer errors occur
// In other words, when it works it works, but it isnt reliable (did not want to risk it so created an alternate solution)

// void Pathfinding::calculateNextPath(Field &field){
// 	Serial.println("ENTRO A NEXT PATH");
				
// 	// There are three possible combinations
// 		// Both boats arent full
// 			// Check min for both green and blue and then compare which is the best
// 		// Green boat is not full
// 			// If it could not find green rods, then we are stuck and must end the match
// 		// Blue boat is not full
// 			// if it could not find blue rods, then we are stuck and must end the match


// 	if(!field.depositAreas[0].isBoatFull() && !field.depositAreas[1].isBoatFull()){
// 		Serial.println("Entro a que los dos estan vacios");

// 		double minCostBlue = 2000000;
// 		double minCostGreen = 2000000;

// 		Stack *bufferBlueStack = nullptr;
// 		Stack *bufferGreenStack = nullptr;

// 		Stack *lowestBlueStack = nullptr;
// 		Stack *lowestGreenStack = nullptr;

// 		Rod *bufferBlueRod = nullptr;
// 		Rod *bufferGreenRod = nullptr;

// 		double bufferCostGreen = 0;
// 		double bufferCostBlue = 0;

// 		// First check Green
// 		for(byte currStack = 0; currStack < 12; ++currStack){
// 			bufferGreenStack = field.map[currStack];
// 			bufferGreenRod = bufferGreenStack->getTopRod();
// 			if(bufferGreenRod != nullptr){
// 				if(bufferGreenRod->getColor() == (green)){
// 					bufferCostGreen = calcTotalCost(bufferGreenStack->getX(), bufferGreenStack->getY(), field.depositAreas[0].getX(), field.depositAreas[0].getY());
// 					if(bufferCostGreen < minCostGreen){
// 						minCostGreen = bufferCostGreen;
// 						lowestGreenStack = bufferGreenStack;
// 						delay(1000);
// 					}
// 				}
// 			}
// 		}

// 		delay(100);

// 		// Now check Blue
// 		for(byte currStack = 0; currStack < 12; ++currStack){
// 			bufferBlueStack = field.map[currStack];
// 			bufferBlueRod = bufferBlueStack->getTopRod();
// 			if(bufferBlueRod != nullptr){
// 				if(bufferBlueRod->getColor() == (blue)){
// 					bufferCostBlue = calcTotalCost(bufferBlueStack->getX(), bufferBlueStack->getY(), field.depositAreas[1].getX(), field.depositAreas[1].getY());
// 					if(bufferCostBlue < minCostBlue){
// 						minCostBlue = bufferCostBlue;
// 						lowestBlueStack = bufferBlueStack;
// 						delay(1000);
// 					}
// 				}
// 			}
// 		}

// 		delay(100);


// 		if(lowestBlueStack->isEmpty() && lowestGreenStack->isEmpty()){
// 			Serial.println("Entro a que por alguna razon los dos estan vacios");
// 			field.endMatch();
// 		}else{


// 			// Check which path is shortest and execute it
// 			if(minCostBlue < minCostGreen){

// 				executePickUp(lowestBlueStack, field);

// 				if(!field.depositAreas[1].isBFull()){
// 					executeDropOff(atBoatBlueB, field.depositAreas[1].howManyDepositedAtB());
					
// 					// Update how many rods we have in the stack we selected
// 					field.depositAreas[1].updateDepositedStack(atB);
// 				}else if(!field.depositAreas[1].isAFull()){
// 					executeDropOff(atBoatBlueA, field.depositAreas[1].howManyDepositedAtA());
// 					field.depositAreas[1].updateDepositedStack(atA);
// 				}else{
// 					executeDropOff(atBoatBlueC, field.depositAreas[1].howManyDepositedAtC());
// 					field.depositAreas[1].updateDepositedStack(atC);
// 				}

// 				delay(100);

// 				if(field.depositAreas[1].isBoatFull()){
// 					field.updateDepositAreasFilled();
// 				}

// 			}else{

// 				Serial.print("Afuera del metodo dice que es : ");
// 				Serial.println(lowestGreenStack->getCurrHeight());
// 				Serial.print("Si accedo directo desde el field : ");
// 				Serial.println(field.map[0]->getCurrHeight());
// 				Stack *prueba = field.map[0];
// 				Serial.print("Si lo intento usando un apuntador nuevo es : ");
// 				Serial.println(prueba->getCurrHeight());

// 				if(lowestGreenStack == field.map[0]){
// 					Serial.println("Direccion de lowest y mapa es igual");
// 				}else{
// 					Serial.println("Lowest esta apuntando a un lugar diferente !");
// 				}
// 				if(prueba == field.map[0]){
// 					Serial.println("Direccion de prueba y mapa es igual");
// 				}

// 				executePickUp(lowestGreenStack, field);

// 				if(!field.depositAreas[0].isBFull()){

// 					executeDropOff(atBoatGreenB, field.depositAreas[0].howManyDepositedAtB());
// 					field.depositAreas[0].updateDepositedStack(atB);
// 				}else if(!field.depositAreas[0].isAFull()){

// 					executeDropOff(atBoatGreenA, field.depositAreas[0].howManyDepositedAtA());
// 					field.depositAreas[0].updateDepositedStack(atA);
// 				}else{
// 					executeDropOff(atBoatGreenC, field.depositAreas[0].howManyDepositedAtC());
// 					field.depositAreas[0].updateDepositedStack(atC);
// 				}

// 				delay(100);

// 				if(field.depositAreas[0].isBoatFull()){
// 					field.updateDepositAreasFilled();
// 				}

// 			}
// 		}

// 	}else if(!field.depositAreas[0].isBoatFull()){ // only boat green has space
// 		Serial.println("Entro a que el verde este vacio solamente");

// 		// First calculate which path is the best
// 		double minCost = 2000000; 
// 		Rod *bufferRod = nullptr;
// 		Stack *bufferStack = nullptr;
// 		Stack *lowestStack = nullptr;
// 		Rod *lowestRod = nullptr;
// 		double bufferCost = 0;

// 		for(byte currStack = 0; currStack < 12; ++currStack){
// 			bufferStack = field.map[currStack];
// 			bufferRod = bufferStack->getTopRod();
// 			if(bufferRod != nullptr){
// 				if(bufferRod->getColor() == (green)){
// 					bufferCost = calcTotalCost(bufferStack->getX(), bufferStack->getY(), field.depositAreas[0].getX(), field.depositAreas[0].getY());
// 					if(bufferCost < minCost){
// 						minCost = bufferCost;
// 						lowestStack = bufferStack;
// 						lowestRod = bufferRod;
// 						delay(1000);
// 					}
// 				}
// 			}
// 		}

// 		delay(100);

// 		// If it could not find any greens, then we are stuck and must end match
// 		if(lowestStack->isEmpty()){
// 			field.endMatch();
// 		}else{

// 			// Go pick it up! Execute path
// 			executePickUp(lowestStack, field);

// 			// Now check where to deposit it and execute path
// 			if(!field.depositAreas[0].isBFull()){
// 				executeDropOff(atBoatGreenB, field.depositAreas[0].howManyDepositedAtB());
// 				field.depositAreas[0].updateDepositedStack(atB);
// 			}else if(!field.depositAreas[0].isAFull()){
// 				executeDropOff(atBoatGreenA, field.depositAreas[0].howManyDepositedAtA());
// 				field.depositAreas[0].updateDepositedStack(atA);
// 			}else{
// 				executeDropOff(atBoatGreenC, field.depositAreas[0].howManyDepositedAtC());
// 				field.depositAreas[0].updateDepositedStack(atC);
// 			}

// 			delay(100);

// 			// Check if now the boat is full, if it is, update its status
// 			if(field.depositAreas[0].isBoatFull()){
// 				field.updateDepositAreasFilled();
// 			}
// 		}


// 	}else{ // Only boat blue has space

// 		Serial.println("Entro a que el azul esta vacio");

// 		// First calculate which path is the best
// 		double minCost = 2000000;
// 		Rod *bufferRod = nullptr;
// 		Stack *bufferStack = nullptr;
// 		Stack *lowestStack = nullptr;
// 		Rod *lowestRod = nullptr;
// 		double bufferCost = 0;

// 		for(byte currStack = 0; currStack < 12; ++currStack){
// 			bufferStack = field.map[currStack];
// 			bufferRod = bufferStack->getTopRod();
// 			if(bufferRod != nullptr){
// 				if(bufferRod->getColor() == (blue)){
// 					bufferCost = calcTotalCost(bufferStack->getX(), bufferStack->getY(), field.depositAreas[1].getX(), field.depositAreas[1].getY());
// 					if(bufferCost < minCost){
// 						minCost = bufferCost;
// 						lowestStack = bufferStack;
// 						lowestRod = bufferRod;
// 						delay(10000);
// 					}
// 				}
// 			}
// 		}

// 		delay(100);

// 		if(lowestStack->isEmpty()){
// 			field.endMatch();
// 		}else{

// 			// Go pick it up! Execute path
// 			executePickUp(lowestStack, field);

// 			// Now check where to deposit it and execute path
// 			if(!field.depositAreas[1].isBFull()){
// 				executeDropOff(atBoatBlueB, field.depositAreas[1].howManyDepositedAtB());
// 				field.depositAreas[1].updateDepositedStack(atB);
// 			}else if(!field.depositAreas[1].isAFull()){
// 				executeDropOff(atBoatBlueA, field.depositAreas[1].howManyDepositedAtA());
// 				field.depositAreas[1].updateDepositedStack(atA);
// 			}else{
// 				executeDropOff(atBoatBlueC, field.depositAreas[1].howManyDepositedAtC());
// 				field.depositAreas[1].updateDepositedStack(atC);
// 			}

// 			delay(100);

// 			// Check if now the boat is full, if it is, update its status
// 			if(field.depositAreas[1].isBoatFull()){
// 				field.updateDepositAreasFilled();
// 			}
// 		}

// 	}
// };
