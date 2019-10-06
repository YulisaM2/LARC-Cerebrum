#include "Cerebrum.h"

Cerebrum::Cerebrum(const DriveTrain &driveTrain): greenBoat(Coord(1,0)), blueBoat(Coord(5,0)), driveTrain(driveTrain){
};

bool Cerebrum::isFinished(){
    return finished;
};

Action Cerebrum::getCurrentAction(){
   Action currentAction;
    switch(state){
        case CerebrumState::GoingToStack:{
            bool topRodBlue = false;
            bool topRodGreen = false;

            for(int i = 0; i < 12; ++i){
                if(stacks[i].getTopRod() == Rod::Green){
                    topRodGreen = true;
                }
                if(stacks[i].getTopRod() == Rod::Blue){
                    topRodBlue = true;
                }
            }
            if(blueBoat.isFull()){
                topRodBlue = false;
            }
            if(greenBoat.isFull()){
                topRodGreen = false;
            }
            if((topRodGreen) | (topRodBlue)){
                Stack *targetStack = getTargetStack(topRodBlue, topRodGreen);
                currentAction.command = Command::PickUp;
                currentAction.path = aStar.getPath(driveTrain,*targetStack,field);
                currentRod = targetStack->getTopRod();
                if(currentRod == Rod::Green){
                    cout << "Picked up green rod" << endl;
                }else{
                    cout << "Picked up blue rod" << endl;
                }
                targetStack->pickUpRod();
                state = CerebrumState::GoingToBoat;
            }else{
                state = CerebrumState::Finished;
                currentAction.path = aStar.getPath(driveTrain, Coord(3,0), field);
                currentAction.command = Command::Move;
                finished = true;
            }

            break;
        }
            
        case CerebrumState::GoingToBoat:{
            currentAction.command = Command::DropOff;
            if(currentRod == Rod::Green){
                currentAction.path = aStar.getPath(driveTrain,greenBoat.getDeliveryZone(true),field);
                greenBoat.dropOffRod(true);
                greenBoat.printZones();
            }else{
                currentAction.path = aStar.getPath(driveTrain,blueBoat.getDeliveryZone(false),field);
                blueBoat.dropOffRod(false);
                blueBoat.printZones();
            }
            state = CerebrumState::GoingToStack;

            break;
        }

        case CerebrumState::Initializing:{
             if(photosTaken == 0){
                currentAction.path = aStar.getPath(driveTrain, Coord(6,1), field);
                currentAction.command = Command::TakePictures;
                ++photosTaken;
            }else if(photosTaken == 1){
                currentAction.path = aStar.getPath(driveTrain, Coord(4,1), field);
                currentAction.command = Command::TakePictures;
                ++photosTaken;
            }else if(photosTaken == 2){
                currentAction.path = aStar.getPath(driveTrain, Coord(2,1), field);
                currentAction.command = Command::TakePictures;
                ++photosTaken;
            }else{
                currentAction.path = aStar.getPath(driveTrain, Coord(0,1), field);
                currentAction.command = Command::TakePictures;
                ++photosTaken;
                requestingStacks = true;
                state = CerebrumState::GoingToStack;
            }

            break;
        }
           

        case CerebrumState::WaitingForStacks:{
            if(stacksSet){
                state = CerebrumState::GoingToStack;
            }

            break;
        }
            

        case CerebrumState::Finished:{
            cout << "Finished! Returning to center :)";
            break;
        }
    }

    return currentAction;
};

void Cerebrum::setStacks(Absis<Stack> stacks){
    stacksSet = true;
    requestingStacks = false;
    this->stacks = stacks;

    for(int i = 0; i < 12; ++i){
        Path pathToBlue = aStar.getPath(stacks[i],blueBoat, field);
        Path pathToGreen = aStar.getPath(stacks[i], greenBoat, field);
        stacks[i].setCostToBlueBoat(pathToBlue.getCost());
        stacks[i].setCostToGreenBoat(pathToGreen.getCost());
        // cout << "Stack at " << stacks[i].getX() << " " << stacks[i].getY() << " with cost to blue : " << stacks[i].getCostToBlueBoat() << " and to green : " <<  stacks[i].getCostToGreenBoat() << endl;
    }
};

bool Cerebrum::isRequestingStacks(){
    return requestingStacks;
};

void Cerebrum::printStacks(){
    if(!stacksSet){
        return;
    }
    cout << endl;
    for(int i = 3; i >=0 ; --i){
        for(int j = 0; j < 12; ++j){
            if(stacks[j].getHeight() - 1 >= i){
                switch(stacks[j].getRodAt(i)){
                    case Rod::Red:
                        cout << "R";
                        break;
                    case Rod::Green:
                        cout << "G";
                        break;
                    case Rod::Blue:
                        cout << "B";
                        break;
                    case Rod::None:
                        cout << "-";
                }
            }else{
                cout << " "; 
            }
            cout << '\t';
        }
        cout << endl;
    }
    cout << endl;
};

Stack* Cerebrum::getTargetStack(bool searchBlue, bool searchGreen){
    Absis<int> costs;
    for(int i = 0; i < 12; ++i){
        Path path = aStar.getPath(driveTrain,stacks[i],field);
        if(stacks[i].getTopRod() == Rod::Green && searchGreen){
            costs.emplace_back(path.getCost() + stacks[i].getCostToGreenBoat());
        }else if(stacks[i].getTopRod() == Rod::Blue && searchBlue){
            costs.emplace_back(path.getCost() + stacks[i].getCostToBlueBoat());
        }else{
            costs.emplace_back(255); // if it is red do not consider it an option
        }
    }

    int minorCost = 255;
    int minorIndex = -1;
    for(int i = 0; i < 12; ++i){
        if(costs[i] < minorCost){
            minorIndex = i;
            minorCost = costs[i];
        }
    }

    return &stacks[minorIndex];
};