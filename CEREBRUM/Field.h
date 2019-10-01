#ifndef _FIELD_h
#define _FIELD_h

#include "Stack.h"
#include "Boat.h"

// Field is a matrix representing the collection of stacks in the map
// 	--------------------------------------
// |	  		  		            	  |
// |	1| |3		5| |7		 9|	|11	  |
// |	2| |4		6| |8		10|	|12   |
//`|									  |
// |	  G2					   B2	  |
// |	 ---		Button		  ---	  |
// | G3	|	| G1	  --	  B1 |.  | B3 |
// |	|	|.  	 ||||		 |	 | 	  |
// 	--------------------------------------
class Field{
	public:
		Field();
		UpdateField(Stack one, Stack two, Stack three, Stack four, Stack five, Stack six, Stack seven, Stack eight, Stack nine, Stack ten, Stack eleven, Stack twelve);
		Field(byte readings[48]);
		
		Field(Stack one, Stack two, Stack three, Stack four, Stack five, Stack six, Stack seven, Stack eight, Stack nine, Stack ten, Stack eleven, Stack twelve);
		
		void updateDepositAreasFilled();
		bool wasMapCompleted(); // the condition for the map to be completed is to deposit the 30 possible rods in their deposit areas (in the boats)
		// void setWasCompleted(byte status);

		void printField(); // for extreme debugging mode! :)

	private:
		
		Stack map[2][6];
		Boat depositAreas[2];
		byte depositAreasFilled;
		// byte mapCompleted;
};
#endif