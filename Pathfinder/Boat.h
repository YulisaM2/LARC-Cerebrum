#ifndef _BOAT_H
#define _BOAT_H

#include "Coord.h"
#include <iostream>
using namespace std;

struct Zone : public Coord{
    bool isFull()const{return rodCount >= 5;};
    int getRodCount(){return rodCount;};
    void dropOffRod(){++rodCount;};
    private: 
        int rodCount = 0;
};

class Boat : public Coord{
    public:
        Boat(Coord center);
        bool isFull();
        void dropOffRod(bool order);
        Zone& getDeliveryZone(bool order); // true for green and false for blue
        void printZones(){
            cout << "Boat (" << getX() << " " << getY() << ") Zones: " << leftZone.getRodCount() << " " << topZone.getRodCount() << " " << rightZone.getRodCount() << endl;
        }
    private:
        Zone topZone;
        Zone leftZone;
        Zone rightZone; 
};
#endif