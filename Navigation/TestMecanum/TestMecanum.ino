#include "Bicho.h"
#include <math.h>

// Bicho *bicho;
Chassis *chassis;
void setup() {
  Serial.begin(9600);
  chassis = new Chassis();
  chassis->driveXAxisDistance(1.0);
  chassis->driveYAxisDistance(0.2);
  // bicho = new Bicho();
}

void loop() {

}