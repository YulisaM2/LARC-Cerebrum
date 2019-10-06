#include <Arduino.h>

#include <stdlib.h>
#include <time.h>

#include "Node.h"
#include "Field.h" 
#include "Absis.h"
#include "Coord.h"
#include "AStar.h"
#include "Path.h"
#include "Stack.h"
#include "Boat.h"
#include "DriveTrain.h"
#include "Cerebrum.h"

using namespace std;

void followPath(DriveTrain &driveTrain, const Path &path){
    Serial.println("Following path ... ");
    for(int i = 0; i < path.getLength();++i){
        Serial.print("Move to ");
        Coord coord = path.getCoordAt(i);
        driveTrain.setX(coord.getX());
        driveTrain.setY(coord.getY());
        Serial.print(driveTrain.getX());
        Serial.println(driveTrain.getY());
    }
    Serial.println("Completed path ! :)");
};

void setup(){
    DriveTrain driveTrain(Coord(3,0));
    Cerebrum cerebrum(driveTrain);

    Absis<Rod>rods;
    srand(time(NULL));
    for(int i = 0; i < 48; ++i){
        int dice = rand() % 100;
        if(dice > 50){
            rods.emplace_back(Rod::Green);
        }else{
            rods.emplace_back(Rod::Blue);
        }
    }

    int randRed = rand() % 47;
    rods[randRed] = Rod::Red;

    randRed = rand() % 47;
    rods[randRed] = Rod::Red;

    Absis<Stack> stacks;
    int rodIndex = 0;
    for(int i = 0; i < 12; ++i){
        Absis<Rod> subRods;
        for(int j = rodIndex; j < rodIndex + 4; ++j){
            subRods.emplace_back(rods[j]);
        }
        rodIndex += 4;
        stacks.emplace_back(Stack(subRods, Coord(0,0)));
    }
    
    stacks[0].setCoord(Coord(0,2));
    stacks[1].setCoord(Coord(0,3));

    stacks[2].setCoord(Coord(1,2));
    stacks[3].setCoord(Coord(1,3));

    stacks[4].setCoord(Coord(2,2));
    stacks[5].setCoord(Coord(2,3));

    stacks[6].setCoord(Coord(4,2));
    stacks[7].setCoord(Coord(4,3));

    stacks[8].setCoord(Coord(5,2));
    stacks[9].setCoord(Coord(5,3));

    stacks[10].setCoord(Coord(6,2));
    stacks[11].setCoord(Coord(6,3));

    char op;
    while(!cerebrum.isFinished()){
        if(cerebrum.isRequestingStacks()){
            cerebrum.setStacks(stacks);
        }
        cerebrum.printStacks();
        Action action = cerebrum.getCurrentAction();
        followPath(driveTrain, action.path);
        switch(action.command){
            case Command::TakePictures:
                    Serial.println("Taking a picture !");
                    break;
                case Command::PickUp:
                    Serial.println("Picking up sht mofo!");
                    break;
                case Command::DropOff:
                    Serial.println("Dropping it like it's hot");
                    break;
        }
       delay(1000);     
    }
};

void loop(){
    
}