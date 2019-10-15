#ifndef _CEREBRUM_H
#define _CEREBRUM_H

#include "Coord.h"
#include "DriveTrain.h"
#include "Boat.h"
#include "AStar.h"
#include "Field.h"
#include "Stack.h"

enum class Command{
    PickUp,
    DropOff,
    TakePictures,
    Move
};

struct Action{
    Path path;
    Coord destination;
    Coord currPosition;
    Command command;
    int height = 0;
};

enum class CerebrumState {
    Initializing,
    WaitingForStacks,
    GoingToStack,
    GoingToBoat,
    Finished
};

class Cerebrum{
    public:
        Cerebrum(const DriveTrain &driveTrain);
        Action getCurrentAction();
        bool isFinished();
        void setStacks(Absis<Stack> stacks);
        bool isRequestingStacks();
        void printStacks();

    private:
        Command command;
        CerebrumState state = CerebrumState::Initializing;
        int photosTaken = 0;
        const DriveTrain &driveTrain;
        Boat greenBoat;
        Boat blueBoat;
        Field field;
        AStar aStar;
        Absis<Stack> stacks;
        bool stacksSet = false;
        bool requestingStacks = false;
        bool finished = false;
        Rod currentRod;

        Stack* getTargetStack(bool greenSearch, bool blueSearch);

};
#endif
