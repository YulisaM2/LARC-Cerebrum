#include "Field.h"

Field::Field(){
	// mapCompleted = 0;
	depositAreasFilled = 0;
};

Field::UpdateField(Stack one, Stack two, Stack three, Stack four, Stack five, Stack six, Stack seven, Stack eight, Stack nine, Stack ten, Stack eleven, Stack twelve){
	map[0][0].copyStack(one);
	map[1][0].copyStack(two);

	map[0][1].copyStack(three);
	map[1][1].copyStack(four);

	map[0][2].copyStack(five);
	map[1][2].copyStack(six);

	map[0][3].copyStack(seven);
	map[1][3].copyStack(eight);

	map[0][4].copyStack(nine);
	map[1][4].copyStack(ten);

	map[0][5].copyStack(eleven);
	map[1][5].copyStack(twelve);
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
	// byte check = mapCompleted & mapEmpty;
	// return check != 0;
	return depositAreasFilled  >= 2;
};

// void Field::setWasCompleted(byte status){
// 	mapCompleted = status;
// };

void Field::printField(){
	byte num = 1;
	for(byte col = 0; col < 6; ++col){
		for(byte row = 0; row < 2; ++row){
			Serial.print("------------------------- NEXT STACK : ");
			Serial.println(num);
			++num;
			map[row][col].printOrder();
		}
	}
	Serial.println("------------------------- End of the field!");
};