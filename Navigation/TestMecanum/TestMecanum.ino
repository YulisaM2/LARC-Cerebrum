#include "Bicho.h"
#include <math.h>

// Bicho *bicho;
Chassis *chassis;
void setup() {
  Serial.begin(9600);
  chassis = new Chassis();
  chassis->turnToAngle(0);
  chassis->turnToAngle(-90);
  chassis->turnToAngle(90);
    chassis->turnToAngle(0);
  // bicho = new Bicho();
}

void loop() {

}