#include "Stack.h"
Rod greenBlocked(B01010000);
Rod blueOkay(B00101000);
Rod blueBlocked(B00110000);

void setup() {

  Serial.begin(9600);
  Serial.println("Starting algorithm...");

  }

void loop() {
	greenBlocked.setNextRod(blueOkay);
	blueOkay.setNextRod(blueBlocked);

	greenBlocked.printRod();
	greenBlocked.isTopOf();

	delay(1000);

	blueOkay.printRod();
	blueOkay.isTopOf();

	delay(1000);

	blueBlocked.printRod();
	blueBlocked.isTopOf();

	delay(20000);
}
