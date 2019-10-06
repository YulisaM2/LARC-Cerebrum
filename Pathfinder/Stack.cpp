#include "Stack.h"

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
                cout << "Green";
                break;
            case Rod::Blue:
                cout << "Blue";
                break;
            case Rod::Red:
                cout << "Red";
                break;
            case Rod::None:
                cout << "None";
                break;
        }
        cout << endl; 
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