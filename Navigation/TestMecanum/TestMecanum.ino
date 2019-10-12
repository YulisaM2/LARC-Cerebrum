#include "Bicho.h"
#include <math.h>

// Bicho *bicho;
Chassis *chassis;
void setup() {
  Serial.begin(9600);
  chassis = new Chassis();
  // bicho = new Bicho();
}

void loop() {
  double vX = cos((millis() / 1000.0) * 2);
  double vY = sin((millis() / 1000.0) * 2);

  chassis->setVelocities(0, vY);
}