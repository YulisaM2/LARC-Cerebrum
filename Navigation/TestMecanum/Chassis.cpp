#include "Chassis.h"

void updateRightEncoder();
void updateLeftEncoder();


Chassis::Chassis(){
    topLeft = new Motor(9,8);
    topRight = new Motor(4,5);
    bottomLeft = new Motor(11, 10, 2, 3);
    bottomRight = new Motor(6, 7, 19, 18);

    bottomLeft->setPulsePerRotation(2249);
    bottomRight->setPulsePerRotation(2249);

    kinematics = new Mecanum(.8, 1, 0.028);
    gyro = &Gyro::getInstance();
    PIDConfig headingControllerConfig;
    headingControllerConfig.p = 0.02;
    headingControllerConfig.d = 0.075;
    headingControllerConfig.maxInput = 180;
    headingControllerConfig.minInput = -180;
    headingControllerConfig.continous = true;
    headingController = new PID(headingControllerConfig);
};

void Chassis::setVelocities(double vX, double vY){
    PIDConfig config = headingController->getPIDConfig();

    if(vY > 0){
        config.p = 0.010;
    }else{
        config.p = 0.030;
    }
    headingController->setPIDConfig(config);
    update();
    writeMotors(kinematics->calcInverseKinematics(vX,vY,currentAngularSpeed));
};

void Chassis::stop(){
    MecanumMotorValues values;
    values.motorBottomLeftSpeed = 0;
    values.motorBottomRightSpeed = 0;
    values.motorTopLeftSpeed = 0;
    values.motorTopRightSpeed = 0;
    writeMotors(values);
}


void Chassis::setTargetHeading(double heading){
    headingController->setSetpoint(heading);
    update();
}

void Chassis::update(){
    headingController->setReference(gyro->getYaw());
    currentAngularSpeed = headingController->getOutput();
}

void Chassis::driveXAxisDistance(double distance){
    bottomLeft->setPosition(0);
    bottomRight->setPosition(0);
    double xDistanceTraveled = 0;
    double multiplier = 1;
    if(distance < 0){
        multiplier = -1;
    }
    while(abs(xDistanceTraveled) < abs(distance)){
        double rotations = (abs(bottomLeft->getRotations()) + abs(bottomRight->getRotations())) / 2.0;
        xDistanceTraveled = rotations * METERS_PER_ROT;

        setVelocities(0.6 * multiplier, 0);
    }
    stop();
}

void Chassis::driveYAxisDistance(double distance){
    bottomLeft->setPosition(0);
    bottomRight->setPosition(0);
    double yDistanceTraveled = 0;
    double multiplier = 1;
    if(distance < 0){
        multiplier = -1;
    }
    while(abs(yDistanceTraveled) < abs(distance)){
        double rotations = (abs(bottomLeft->getRotations()) + abs(bottomRight->getRotations())) / 2.0;
        yDistanceTraveled = (rotations * METERS_PER_ROT);

        setVelocities(0, 0.6 * multiplier);
    }
    stop();
}

void Chassis::writeMotors(MecanumMotorValues values){
  topLeft->set(values.motorTopLeftSpeed);
  topRight->set(values.motorTopRightSpeed);
  bottomLeft->set(values.motorBottomLeftSpeed);
  bottomRight->set(values.motorBottomRightSpeed);
};
