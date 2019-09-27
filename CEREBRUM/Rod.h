#ifndef _ROD_h
#define _ROD_h

#include "Masks.h"

class Rod{
	public:
		Rod();
		Rod(byte bStatus);

		void setStatus(byte bStatus);
		byte getStatus();

		void setNextRod(Rod rod);
		Rod* getNextRod();
		
		void printRod(); // for debug mode
		
		void blockRod();
		bool isBlocked();
		void unblockRod();

		bool wasPickedUp();
		void rodPickedUp();

		void isTopOf(); // for debug mode

	private:
		byte status; // red green blue blocked pickedUp (1 indicates that that state is true)
		Rod* nextRod; // to keep track of the following rod on the stack, it will help to know from which rod to pick up next time (instead of iterating throught the whole stack)

};
#endif
