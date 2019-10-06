#include "Stack.h"
#include <Arduino.h>

Stack::Stack(){

}

Stack::Stack(Absis<Rod> rods, Coord coord):Coord(coord){
    this->rods = rods;
};

void Stack::pickUpRod(){
    rods.remove(rods[rods.size() - 1]);
};

int Stack::getHeight(){
    return this->rods.size();
};

Rod Stack::getTopRod(){
    if(rods.size() > 0){
        return rods[rods.size() - 1];
    }
    return Rod::None;
    
};

void Stack::setRods(Absis<Rod> rods){
    this->rods = rods;
};

void Stack::printStack(){
    for(int i = 0; i < rods.size();++i){
        switch(rods[i]){
            case Rod::Green:
                Serial.print("Green");
                break;
            case Rod::Blue:
                Serial.print("Blue");
                break;
            case Rod::Red:
                Serial.print("Red");
                break;
            case Rod::None:
                Serial.print("None");
                break;
        }
        Serial.println(); 
    }
};

Rod Stack::getRodAt(int index){
    return rods[index];
};

void Stack::setCostToBlueBoat(int cost){
    this->costToBlueBoat = cost;
};

int Stack::getCostToBlueBoat(){
    return this->costToBlueBoat;
};

void Stack::setCostToGreenBoat(int cost){
    this->costToGreenBoat = cost;
};

int Stack::getCostToGreenBoat(){
    return this->costToGreenBoat;
};