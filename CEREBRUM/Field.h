#ifndef _FIELD_h
#define _FIELD_h

#include "Stack.h"
#include "Boat.h"

// Field is a matrix representing the collection of stacks in the map
// 	--------------------------------------
// |	  		  		            	  |
// |	1| |3		5| |7		 9|	|11	  |
// |	2| |4		6| |8		10|	|12   |
// |									  |
// 	--------------------------------------
class Field{
	public:
		Field();
		UpdateField(Stack one, Stack two, Stack three, Stack four, Stack five, Stack six, Stack seven, Stack eight, Stack nine, Stack ten, Stack eleven, Stack twelve);
		Field(byte readings[48]);
		
		Field(Stack one, Stack two, Stack three, Stack four, Stack five, Stack six, Stack seven, Stack eight, Stack nine, Stack ten, Stack eleven, Stack twelve);
		
		byte wasMapCompleted();
		void setWasCompleted(byte status);

		void printField(); // for extreme debugging mode! :)

	private:
		
		Stack map[2][6];
		Boat depositAreas[2];
		byte mapCompleted;
};
#endif