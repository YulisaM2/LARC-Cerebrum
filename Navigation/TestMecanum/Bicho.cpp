#include "Bicho.h"

Bicho::Bicho(){
    chassis = new Chassis();
    chassis->setTargetHeading(0);
}

void Bicho::followPath(const Path& path){
    for(int i = 0; i < path.getLength(); ++i){
        Coord coord = path.getCoordAt(i);
        double dX = position.getX() - coord.getX();
        double dY = position.getX() - coord.getX();
        int yMult = dY > 0 ? 1 : -1;

        if(abs(dX) > 0){
            if(position.getX() == 1 && coord.getX() == 2){
                moveX(24);
            }else if(position.getX() == 2 && coord.getX() == 3){
                moveX(14);
            }else if(position.getX() == 2 && coord.getX() == 1){
                moveX(-24);
            }else if(position.getX() == 3 && coord.getX() == 2){
                moveX(-14);
            }

            if(position.getX() == 0 && coord.getX() == 1){

            }

        }else if(abs(dY) > 0){
            moveY(yMult);
        }
    }
}

void Bicho::moveX(double distance){
    int multiplier = distance > 0 ? 1 : -1;
    chassis->driveXAxisDistance(distance);
    position.setX(position.getX() + multiplier);    
}

void Bicho::moveY(int units){
    int multiplier = units > 0 ? 1 : -1;

    for(int i = 0; i < units; ++i){
        bool movedUnit = false;
        while(movedUnit){
            if(multiplier > 0){
                movedUnit = rightSideBlackTapeDetected();
            }else{
                movedUnit = leftSideBlackTapeDetected();
            } 
            chassis->setVelocities(0.2 * multiplier, 0);
        }

        while(!movedUnit){
            if(multiplier > 0){
                movedUnit = rightSideBlackTapeDetected();
            }else{
                movedUnit = leftSideBlackTapeDetected();
            }

            chassis->setVelocities(0.2 * multiplier, 0);
        }
        position.setY(position.getY() + multiplier);
    }

    chassis->setVelocities(0, 0);
}
