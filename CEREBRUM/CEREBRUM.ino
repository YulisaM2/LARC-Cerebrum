#include "Rod.h"

Rod rod2(B10010000); 
Rod rod3(B00000000);

void setup() {

  Serial.begin(9600);
  Serial.println("Starting algorithm...");

}

void loop() {
  
  Serial.println("FIRST ROD....");

  rod2.printRod();
  if(rod2.isBlocked()){
  	Serial.println("BLOCKEEEED");
  }
  
  Serial.println("SECOND ROD....");

  rod3.printRod();
  if(rod3.isBlocked()){
  	Serial.println("BLOCKEEEED");
  }

}
