#ifndef _ROD_h
#define _ROD_h

#include "Masks.h"

// All the rods must be initialized with values equivalent to unpicked and blocked, unless they are the top rod of the stack or they are red
class Rod{
	public:
		Rod();
		Rod(byte bStatus);

		void setStatus(byte bStatus);
		byte getStatus();

		byte getColor();

		// void setNextRod(Rod &rod);
		// Rod* getNextRod();
		
		void printRod(); // for debugging mode
		
		void blockRod();
		bool isBlocked();
		void unblockRod();

		bool wasPickedUp();
		void pickedUpRod();

		// void isTopOf(); // for debugging mode

	private:
		volatile byte status; // red green blue blocked pickedUp (1 indicates that that state is true)
		// Rod* nextRod; // to keep track of the following rod on the stack, it will help to know from which rod to pick up next time (instead of iterating throught the whole stack)
};
#endif
