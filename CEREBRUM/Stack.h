#ifndef _STACK_h
#define _STACK_h

#include "Rod.h"

// A Stack is a column of rods, while a rod is the basic unit/element of the map
// The order of the rods in the stack is:
// TOP 	0	1	2	3	4 BOTTOM
// 		|	|	|	|	|

class Stack{
	public:
		Stack();
		void markEmpty();
		void updateStack(byte first, byte second, byte third, byte fourth);
		Stack(byte first, byte second, byte third, byte fourth);

		byte getStackStatus();
		void setStackStatus(byte bStackStatus);

		void setTopRod(Rod &rod);
		Rod* getTopRod();
		
		void unblockNextRod();

		bool isEmpty();
		void topRodpickedUp();

		void copyStack(const Stack &original); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		void printStack(); // hardocded, for debugging mode
		void printOrder(); // using current top rod as start, for debugging mode
	private:
		Rod stack[4];
		Rod* topRod; // reference to the rod that is currently at the top (the only one eligible for pickup)
		byte stackStatus; // to quickly check if it is empty (B00000100) and not consider it when mapping 
};
#endif