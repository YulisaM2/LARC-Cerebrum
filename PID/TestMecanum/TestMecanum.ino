#include "Motor.h"
#include "Mecanum.h"
#include "Gyro.h"
#include <math.h>
Mecanum *kinematics;
Motor *motorTopLeft, *motorTopRight, *motorBottomLeft, *motorBottomRight;
Gyro* gyro;


void setup() {

  motorTopLeft = new Motor(9,8);
  motorTopRight = new Motor(4,5);
  motorBottomLeft = new Motor(11,10);
  motorBottomRight = new Motor(6,7);

  kinematics = new Mecanum(.8, 1);
  gyro = &Gyro::getInstance();
}


void motorWrite(MecanumMotorValues values){
  motorTopLeft->set(values.motorTopLeftSpeed);
  motorTopRight->set(values.motorTopRightSpeed);
  motorBottomLeft->set(values.motorBottomLeftSpeed);
  motorBottomRight->set(values.motorBottomRightSpeed);
}


// Gira en un circulo 
// La x & y son relativas al frente del robot (positivas a la derecha y arriba, negativos a izquiera y abajo)
void loop() {

  MecanumMotorValues values;

  double vX = sin(millis()/1000.0) * 0.5;
  double vY = cos(millis()/1000.0) * 0.5;
  values = kinematics->calcInverseKinematics(vX,vY,(gyro->getYaw() - 0) * 0.03);
  motorWrite(values);

}