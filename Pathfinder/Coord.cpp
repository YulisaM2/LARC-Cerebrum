#include "Coord.h"

Coord::Coord(){
    this->x = 0;
    this->y = 0;
}

Coord::Coord(int x, int y){
    this->x = x;
    this->y = y;
};

void Coord::setX(int x){
    this->x = x;
};

int Coord::getX()const{
    return this->x;
};

void Coord::setY(int y){
    this->y = y;
};

int Coord::getY()const{
    return this->y;
};

bool Coord::operator==(const Coord& c){
    return this->x == c.getX() && this->y == c.getY();
};

void Coord::setCoord(Coord coord){
    this->x = coord.getX();
    this->y = coord.getY();
};