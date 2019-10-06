#include "Boat.h"
#include <Arduino.h>

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
    Serial.print(zone.getX());
    Serial.print(" ");
    Serial.print(zone.getY());
    Serial.print(zone.getRodCount());
    Serial.println();
};

void Boat::printZones(){
    Serial.print("Boat (");
    Serial.print(getX());
    Serial.print(getY());
    Serial.print(") Zones: ");
    Serial.print(leftZone.getRodCount());
    Serial.print(" ");
    Serial.print(topZone.getRodCount());
    Serial.print(" ");
    Serial.print(rightZone.getRodCount());
    Serial.println();
}
