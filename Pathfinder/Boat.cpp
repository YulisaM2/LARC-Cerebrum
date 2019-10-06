#include "Boat.h"
#include <iostream>

using namespace std;

Boat::Boat(Coord center) : Coord(center){
    topZone.setX(center.getX());
    topZone.setY(center.getY());

    leftZone.setX(center.getX() - 1);
    leftZone.setY(center.getY());

    rightZone.setX(center.getX() + 1);
    rightZone.setY(center.getY());
};

bool Boat::isFull(){
    if((topZone.isFull() && leftZone.isFull()) && rightZone.isFull()){
        return true;
    }
    return false;
};

Zone& Boat::getDeliveryZone(bool order){
    if(order){
        if(!topZone.isFull()){
        return topZone;
        }else if(!rightZone.isFull()){
            return rightZone;
        }else{
            return leftZone;
        }
    }else{
        if(!topZone.isFull()){
            return topZone;
        }else if(!leftZone.isFull()){
            return leftZone;
        }else{
            return rightZone;
        }
    }
    
};

void Boat::dropOffRod(bool order){
    Zone &zone = getDeliveryZone(order);
    zone.dropOffRod();
    cout << zone.getX() << " " << zone.getY() << " " << zone.getRodCount() << endl;
};
