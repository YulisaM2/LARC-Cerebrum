#ifndef _STACK_H
#define _STACK_H

#include "Coord.h"
#include "Absis.h"

enum class Rod{
    Green,
    Blue,
    Red,
    None
};

class Stack : public Coord{
    public:
        Stack();
        Stack(Absis<Rod> rods, Coord coord);
        void pickUpRod();
        int getHeight();
        Rod getTopRod();
        void printStack();
        Rod getRodAt(int index);

        void setRods(Absis<Rod> rods);

        void setCostToBlueBoat(int cost);
        int getCostToBlueBoat();

        void setCostToGreenBoat(int cost);
        int getCostToGreenBoat();

    private:
        Absis<Rod> rods;
        int costToBlueBoat = 0;
        int costToGreenBoat = 0;
};
#endif