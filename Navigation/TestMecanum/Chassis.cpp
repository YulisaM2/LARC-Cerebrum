#include "Chassis.h"

void updateRightEncoder();
void updateLeftEncoder();

Encoder *rightEncoder;
Encoder *leftEncoder; 

Chassis::Chassis(){
    topLeft = new Motor(9,8);
    topRight = new Motor(4,5);
    bottomLeft = new Motor(11,10);
    bottomRight = new Motor(6,7);

    rightEncoder = new Encoder(2, 3);
    leftEncoder = new Encoder(19, 18); 

    attachInterrupt(rightEncoder->getA(),updateRightEncoder,FALLING);
    attachInterrupt(leftEncoder->getA(),updateLeftEncoder,FALLING);

    kinematics = new Mecanum(.8, 1, 0.028);
    gyro = &Gyro::getInstance();
    PIDConfig headingControllerConfig;
    headingControllerConfig.p = 0.03;
    headingControllerConfig.maxInput = 180;
    headingControllerConfig.minInput = -180;
    headingControllerConfig.continous = true;
    headingController = new PID(headingControllerConfig);
};

void Chassis::setVelocities(double vX, double vY){
    update();
    writeMotors(kinematics->calcInverseKinematics(vX,vY,currentAngularSpeed));
};

void Chassis::setTargetHeading(double heading){
    headingController->setSetpoint(heading);
    update();
}

void Chassis::update(){
    headingController->setReference(gyro->getYaw());
    currentAngularSpeed = headingController->getOutput();
}

void Chassis::driveXAxisDistance(double distance){
    leftEncoder->setPosition(0);
    rightEncoder->setPosition(0);
    double xDistanceTraveled = 0;
    double multiplier = 1;
    if(distance < 0){
        multiplier = -1;
    }
    while(abs(xDistanceTraveled) < abs(distance)){
        double rotations = (abs(leftEncoder->getRotations()) + abs(rightEncoder->getRotations())) / 2.0;
        xDistanceTraveled = rotations * METERS_PER_ROT;

        setVelocities(0.3 * multiplier, 0);
    }
    setVelocities(0, 0);
}

void Chassis::driveYAxisDistance(double distance){
    leftEncoder->setPosition(0);
    rightEncoder->setPosition(0);
    double yDistanceTraveled = 0;
    double multiplier = 1;
    if(distance < 0){
        multiplier = -1;
    }
    while(abs(yDistanceTraveled) < abs(distance)){
        double rotations = (abs(leftEncoder->getRotations()) + abs(rightEncoder->getRotations())) / 2.0;
        yDistanceTraveled = (rotations * METERS_PER_ROT) / 2.0;

        setVelocities(0, 0.3 * multiplier);
    }
    setVelocities(0, 0);
}

void Chassis::writeMotors(MecanumMotorValues values){
  topLeft->set(values.motorTopLeftSpeed);
  topRight->set(values.motorTopRightSpeed);
  bottomLeft->set(values.motorBottomLeftSpeed);
  bottomRight->set(values.motorBottomRightSpeed);
};

void Chassis::moveXUntilBlack(bool untilBlackIsFound){

}

void Chassis::moveYUntilBlack(bool untilBlackIsFound){

}

void updateRightEncoder(){
    if(digitalRead(rightEncoder->getA()) == HIGH){
        if(digitalRead(rightEncoder->getB()) == LOW){
            rightEncoder->decrease();
        }
        else{
            rightEncoder->increase();
        }
    }else{
        if(digitalRead(rightEncoder->getB()) == LOW){
            rightEncoder->increase();
        }
        else{
            rightEncoder->decrease();
        }
    }
}

void updateLeftEncoder(){
    if(digitalRead(leftEncoder->getA()) == HIGH){
        if(digitalRead(leftEncoder->getB()) == LOW){
            leftEncoder->decrease();
        }
        else{
            leftEncoder->increase();            
        }
    }else{
        if(digitalRead(leftEncoder->getB()) == LOW){
            leftEncoder->increase();
        }
        else{
            leftEncoder->decrease();
        }
    }
}