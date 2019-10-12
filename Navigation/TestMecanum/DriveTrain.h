#ifndef _DRIVETRAIN_H
#define _DRIVETRAIN_H

#include "Coord.h"

enum class Orientation{
    Right,
    Left,
    Up,
    Down
};

class DriveTrain : public Coord{
    public:
        DriveTrain(Coord coord);
        Orientation getElevatorFacing();
        void setElevatorFacing(Orientation elevatorFacing);
    private:
        Orientation elevatorFacing;
};
#endif