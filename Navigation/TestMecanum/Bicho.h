#ifndef __BICHO_H_
#define __BICHO_H_
#include "Chassis.h"
#include "Coord.h"
#include "Path.h"

class Bicho {
public:
    Bicho();
    void followPath(const Path& path);
    void moveX(double units);
    void moveY(int units);

    bool rightSideBlackTapeDetected();
    bool leftSideBlackTapeDetected();

    bool frontSideBlackTapeDetected();
    bool backSideBlackTapeDetected();     
      
private:
    Chassis* chassis;
    Coord position = Coord(0, 1);
};

#endif