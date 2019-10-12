#ifndef __CHASSIS_H_
#define __CHASSIS_H_
#include "Motor.h"
#include "Mecanum.h"
#include "Gyro.h"
#include "PID.h"
#include "Encoder.h"

class Chassis {
public:
    Chassis();
    void setVelocities(double vX, double vY);
    void setTargetHeading(double heading);
    void driveXAxisDistance(double distance);
    void driveYAxisDistance(double distance);
private:
    void writeMotors(MecanumMotorValues values);
    void update();  
    double currentAngularSpeed = 0;
    Motor *topRight, *topLeft, *bottomLeft, *bottomRight;
    Mecanum *kinematics;
    Gyro* gyro;
    PID* headingController;
    const double METERS_PER_ROT = 0.1759291886;
};
#endif