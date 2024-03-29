#include "Path.h"
#include <Arduino.h>


Path::Path(){

}

Path::Path(Absis<Coord> path){
    this->path = path;
}

Coord Path::getCoordAt(int index)const{
    if(index >= 0 && index < path.size()){
        return path[index];
    }
}

int Path::getLength()const{
    return path.size();
}

int Path::getCost(){
    return cost;
}

int Path::setCost(int cost){
    this->cost  = cost;
}

void Path::setValid(bool valid){
    this->valid = valid;
}

bool Path::getValid(){
    return valid;
}

Absis<Coord> Path::getPath(){
    return path;
}

void Path::print(){
    for(int i = 0; i < path.size(); ++i){
        Serial.println();
        Serial.print("x: ");
        Serial.print(path[i].getX());
        Serial.print("\ty: ");
        Serial.print(path[i].getY());
        Serial.println();
    }
}