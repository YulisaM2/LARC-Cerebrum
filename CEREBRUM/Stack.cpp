#include "Stack.h"

Stack::Stack(){
	stackStatus = 0;
	// topRod = nullptr;
	currHeight = maxHeightStack;
	position = 0;
	x = 0;
	y = 0;
};

void Stack::markEmpty(){
	stackStatus = stackEmpty;
	currHeight = 0;
	// topRod = nullptr;
};

void Stack::updateStack(byte first, byte second, byte third, byte fourth){
	// if the first rod is red, the whole stack is blocked and thus should not be considered as a viable option for rod pickup
	// Hence, treating it as an empty stack should be more efficient 
	
	if(fourth == (red)){ 
		markEmpty();
	}else{

		// stack[0].setStatus(fourth);
		// stack[1].setStatus(second | blocked);
		// stack[2].setStatus(third | blocked);
		// stack[3].setStatus(fourth | blocked);
		
		stack[3].setStatus(fourth);
		stack[2].setStatus(third | blocked);
		stack[1].setStatus(second | blocked);
		stack[0].setStatus(first | blocked);

		// if(second == (red)){

		// 	// stack[0].setStatus(first);
		// 	// stack[1].setStatus(second); // Because it is red, it is marked as blocked by default
		// 	// stack[2].setStatus(third | blocked);
		// 	// stack[3].setStatus(fourth | blocked);

		// 	// stack[0].setNextRod(stack[1]); // The rest shall be nullptrs becasue they are under a red (so that we dont consider them as viable pickups)
			
		// }else if(third == (red)){
		// 	// stack[0].setStatus(first);
		// 	// stack[1].setStatus(second | blocked);
		// 	// stack[2].setStatus(third);
		// 	// stack[3].setStatus(fourth | blocked);


		// 	// stack[0].setNextRod(stack[1]); // TOP ROD


		// 	// stack[1].setNextRod(stack[2]);

		// }else if(fourth == (red)){ 
		// 	// stack[0].setStatus(first);
		// 	// stack[1].setStatus(second | blocked);
		// 	// stack[2].setStatus(third | blocked);
		// 	// stack[3].setStatus(fourth);


		// 	// stack[0].setNextRod(stack[1]);
		// 	// stack[1].setNextRod(stack[2]); // TOP ROD


		// 	// stack[2].setNextRod(stack[3]);
		// }else{
		// 	// stack[0].setStatus(first);
		// 	// stack[1].setStatus(second | blocked);
		// 	// stack[2].setStatus(third | blocked);
		// 	// stack[3].setStatus(fourth | blocked);


		// 	// stack[0].setNextRod(stack[1]);
		// 	// stack[1].setNextRod(stack[2]);
		// 	// stack[2].setNextRod(stack[3]);	// TOP ROD
		// }

		// stack[0].setNextRod(stack[1]);
		// stack[1].setNextRod(stack[2]);
		// stack[2].setNextRod(stack[3]);
		// stack[3].setNextRod(nullptr); // When the object Rod is created, the nextRode is initialized with nullptr so this should be unnecessary

		stackStatus = 0;
		// topRod = &stack[0];
		currHeight = maxHeightStack;
	}

	delay(100);

};


Stack::Stack(byte first, byte second, byte third, byte fourth){
	Stack();
	updateStack(first,second,third,fourth);
}


byte Stack::getStackStatus(){
	return stackStatus;
};

void Stack::setStackStatus(byte bStackStatus){
	stackStatus = bStackStatus;
};


void Stack::setX(double posX){
	x = posX;
};

double Stack::getX(){
	return x;
};

void Stack::setY(double posY){
	y = posY;
};

double Stack::getY(){
	return y;
};

// void Stack::setTopRod(Rod &rod){
// 	topRod = &rod;
// };

// Rod* Stack::getTopRod(){
// 	return topRod;
// };

byte Stack::getTopRodColor(){
	return stack[currHeight - 1].getColor();
}

// Unblock the next rod unless it is red
// Three basic cases:
//		1. We picked up a rod that is followed by green or blue rod
//		2. We picked up a rod that is followed by a red one 
//		3. We picked up the last rod of the stack
void Stack::unblockNextRod(){
	// topRod = topRod->getNextRod();
	// if(topRod != nullptr){ // && topRod->getStatus() != (red)
	// 	topRod->unblockRod();
	// }else{
	// 	markEmpty();
	// }

	if(currHeight > 1 && stack[currHeight - 2].getColor() != (red)){ // consider that when indexing you start at 0 
		stack[currHeight - 2].unblockRod();
	}else{
		markEmpty();
	}
};

bool Stack::isEmpty(){
	byte check = stackStatus & stackEmpty;
	return check != 0;
};

void Stack::topRodpickedUp(){	
	// topRod->pickedUpRod();
	stack[currHeight].pickedUpRod();
	--currHeight;
	unblockNextRod();
};


byte Stack::getCurrHeight(){
	return currHeight;
}

byte Stack::getPosition(){
	return position;
};

void Stack::setPosition(byte status){
	position = status;
	switch(position){
		case position1:
			setX(2);
			setY(2);
			break;
		case position2:
			setX(2);
			setY(3);
			break;
		case position3:
			setX(4);
			setY(2);
			break;
		case position4:
			setX(4);
			setY(3);
			break;
		case position5:
			setX(6);
			setY(2);
			break;
		case position6:
			setX(6);
			setY(3);
			break;
		case position7:
			setX(8);
			setY(2);
			break;
		case position8:
			setX(8);
			setY(3);
			break;
		case position9:
			setX(10);
			setY(2);
			break;
		case position10:
			setX(10);
			setY(3);
			break;
		case position11:
			setX(12);
			setY(2);
			break;
		case position12:
			setX(12);
			setY(3);
			break;
	}
	delay(100);
};

// void Stack::copyStack(const Stack &original){
// 	updateStack(original.stack[0].getStatus(),original.stack[1].getStatus(),original.stack[2].getStatus(),original.stack[3].getStatus());
// };

// Both methods won't print anything if first rod is red because of how the constructor was defined (directly marking stack as empty and defining top rod as nullptr)
// Skipped part of actually introducing anything on the stacks as it isnt relevant because we wont pick up red rods
void Stack::printStack(){
	
	for(int i = 0; i < 4; ++i){
		if(stack[i].getStatus() != 0){
			stack[i].printRod();
		}else{
			Serial.println("Undefined rod: it's after a red one");
		}
	}
};

void Stack::printOrder(){
	// Rod* rod = topRod;

	// while(rod != nullptr){
	// 	rod->printRod();
	// 	rod = rod->getNextRod();
	// }

	if(currHeight > 0){

		byte currRod = currHeight;

		while(currRod > 0){	
			if(stack[currRod - 1].getColor() == (red)){
				break;
			}
			stack[currRod - 1].printRod();
			--currRod;
		}	
	}
	
};
