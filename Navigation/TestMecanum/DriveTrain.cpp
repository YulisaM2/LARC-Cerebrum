#include "DriveTrain.h"

DriveTrain::DriveTrain(Coord coord) : Coord(coord){

};

Orientation DriveTrain::getElevatorFacing(){
    return elevatorFacing;
};

void DriveTrain::setElevatorFacing(Orientation elevatorFacing){
    this->elevatorFacing = elevatorFacing;
};

