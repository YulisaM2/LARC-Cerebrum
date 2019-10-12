#include "SerialComm.h"

SerialComm::SerialComm(){

};

Absis<Stack> SerialComm::buildingStacks(Absis<char> data){
	Stack stackClose;
	Stack stackFar;
	Absis<Rod> rodsClose;
	Absis<Rod> rodsFar;

	if(data.size() < 10){
		// Serial.write("size menor a 10\n");
		for(int i = 1; i < 5; ++i){
			rodsClose.emplace_back(Rod::Red);
			rodsFar.emplace_back(Rod::Red);
		}

	}else{
		// Serial.write("size correcto, ejecutando build\n");

		for(int i = 1; i <  5; ++i){
			char currRod = data[i];
			if(currRod == 'r'){
				rodsClose.emplace_back(Rod::Red);	
			}else if(currRod == 'g'){
				rodsClose.emplace_back(Rod::Green);
			}else{
				rodsClose.emplace_back(Rod::Blue);
			}
		}

		for(int i = 5; i < 8; ++i){
			char currRod = data[i];
			if(currRod == 'r'){
				rodsFar.emplace_back(Rod::Red);	
			}else if(currRod == 'g'){
				rodsFar.emplace_back(Rod::Green);
			}else{
				rodsFar.emplace_back(Rod::Blue);
			}
		}

	}

	// Serial.write("Setting rods and emplacing stacks ...\n");

	stackClose.setRods(rodsClose);
	stackFar.setRods(rodsFar);

	Absis<Stack> stacks;
	stacks.emplace_back(stackClose);
	stacks.emplace_back(stackFar);

	// for(int i = 0; i < 2; ++i){
	// 	for(int j = 0; j < 4; ++j){
	// 		Rod translator = stacks[i].getRodAt(j);
	// 		if(translator == Rod::Red){
	// 			Serial.write("Red\n");
	// 		}else if(translator == Rod::Green){
	// 			Serial.write("Green\n");
	// 		}else{
	// 			Serial.write("Blue\n");
	// 		}
	// 	}
	// 	// Serial.write("SEGUNDO STACK \n");
	// }

	// Serial.write("Returning stacks\n");

	return stacks;
}

Absis<Stack> SerialComm::takePictureLeft(){
	Serial.write("pl\n");
	Absis<char> check;

	bool foundMessage = false;
	
	while(!foundMessage){
		while(!Serial.available()){
		delay(100);
		}
		while(Serial.available()){
			check.emplace_back(Serial.read());
		}

		for(int i = 0; i < check.size(); ++i){
			Serial.write(check[i]);
		}	

		if(check[0] == '$' && check[9] == '\n'){
			foundMessage = true;
		}
	}
	

	return buildingStacks(check);
	
};


Absis<Stack> SerialComm::takePictureRight(){
	Serial.write("pr\n");
	Absis<char> check;

	bool foundMessage = false;
	
	while(!foundMessage){
		while(!Serial.available()){
		delay(100);
		}
		while(Serial.available()){
			check.emplace_back(Serial.read());
		}

		for(int i = 0; i < check.size(); ++i){
			Serial.write(check[i]);
		}	

		if(check[0] == '$' && check[9] == '\n'){
			foundMessage = true;
		}
	}
	

	return buildingStacks(check);
};