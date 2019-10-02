#include "Field.h"

Field::Field(){
	depositAreasFilled = 0;
};

Field::UpdateField(Stack one, Stack two, Stack three, Stack four, Stack five, Stack six, Stack seven, Stack eight, Stack nine, Stack ten, Stack eleven, Stack twelve){
	// map[0][0].copyStack(one);
	// map[1][0].copyStack(two);

	// map[0][1].copyStack(three);
	// map[1][1].copyStack(four);

	// map[0][2].copyStack(five);
	// map[1][2].copyStack(six);

	// map[0][3].copyStack(seven);
	// map[1][3].copyStack(eight);

	// map[0][4].copyStack(nine);
	// map[1][4].copyStack(ten);

	// map[0][5].copyStack(eleven);
	// map[1][5].copyStack(twelve);

	map[0].copyStack(one);
	map[1].copyStack(two);

	map[2].copyStack(three);
	map[3].copyStack(four);

	map[4].copyStack(five);
	map[5].copyStack(six);

	map[6].copyStack(seven);
	map[7].copyStack(eight);

	map[8].copyStack(nine);
	map[9].copyStack(ten);

	map[10].copyStack(eleven);
	map[11].copyStack(twelve);
};

Field::Field(byte readings[48]){
	Stack stacks[12];
	byte currReading = 0;
	for(byte currStack = 0; currStack < 12; ++currStack){
		stacks[currStack].updateStack(readings[currReading], readings[currReading + 1], readings[currReading + 2], readings[currReading + 3]);
		currReading += 4;
	}

	UpdateField(stacks[0], stacks[1], stacks[2], stacks[3], stacks[4], stacks[5], stacks[6], stacks[7], stacks[8], stacks[9], stacks[10], stacks[11]);
};

Field::Field(Stack one, Stack two, Stack three, Stack four, Stack five, Stack six, Stack seven, Stack eight, Stack nine, Stack ten, Stack eleven, Stack twelve){
	Field();
	UpdateField(one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve);
};

void Field::updateDepositAreasFilled(){
	++depositAreasFilled;
};

bool Field::wasMapCompleted(){
	return depositAreasFilled  >= 2; // we can only stack 30 rods, so we will run out of places where to drop off rods before having the chance of finishing the map
};

void Field::printField(){
	byte num = 1;
	// for(byte col = 0; col < 6; ++col){
	// 	for(byte row = 0; row < 2; ++row){
	// 		Serial.print("------------------------- NEXT STACK : ");
	// 		Serial.println(num);
	// 		++num;
	// 		map[row][col].printOrder();
	// 	}
	// }

	for(byte currStack = 0; currStack < 12; ++currStack){
		Serial.print("------------------------- NEXT STACK : ");
		Serial.println(num);
		++num;
		map[currStack].printOrder();
	}
	Serial.println("------------------------- End of the field!");
};