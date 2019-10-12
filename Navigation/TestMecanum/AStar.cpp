#include "AStar.h"
#include <Arduino.h>

int AStar::heuristic(Coord start, Coord end){
    return abs(start.getX() - end.getX()) + abs(start.getY() - end.getY());
}

Path AStar::getPath(Coord startCoord, Coord endCoord, Field& field){
    Absis<Node*> openSet, closedSet;
    field.cleanPreviousNodes();
    Absis<Absis<Node*>> maze = field.getField();
    Node *start = maze[startCoord.getX()][startCoord.getY()], *end = maze[endCoord.getX()][endCoord.getY()];

    Absis<Node*> endNeighbors;
    for(int i = 0; i < end->getNeighborCounter(); ++i){
        endNeighbors.emplace_back(end->getNeighbors()[i]);
    }
    openSet.push_back(start);

    Path pathFinal;
    
    while(openSet.size() > 0){
        int lowestIndex = 0;
        for(int i = 0; i < openSet.size(); ++i){
            //cout << "F for " << openSet[i]->getF() << " of (" << openSet[i]->getX() << " " << openSet[i]->getY() << ")" << endl;

            if(openSet[i]->getF() < openSet[lowestIndex]->getF()){
                lowestIndex = i;
            }
        }

        Node *current = openSet[lowestIndex];
        if(current == end){
          
            Absis<Coord> temp, path;
            int cost = 0;
            while(current->getPrevious() != nullptr){
                cost += 1;
                temp.push_back(Coord(current->getX(), current->getY()));
                current = current->getPrevious();
            }

            for(int i = temp.size()-1; i >= 0; --i){
                path.push_back(temp[i]);
            }

            pathFinal = Path(path);
            pathFinal.setCost(cost);
            pathFinal.setValid(true);
            return pathFinal;
        }

        //cout << "Before= " << openSet.size() << endl;
        closedSet.push_back(current);

        //cout << countsOnVector(closedSet, current) <<  endl;
        openSet.remove(current);
        //cout << "After= " << openSet.size() << endl;

       Node* neighbors[6];
        int amountNeighbors = current->getNeighborCounter();
         for(int i = 0; i < amountNeighbors;++i){
            neighbors[i] = (current->getNeighbors()[i]);
        }

        for(int i = 0; i < amountNeighbors; ++i){
             Node* neighbor = neighbors[i];
             if(closedSet.count(neighbor) == 0){
                int tempG = current->getG() + 1;

                if(openSet.count(neighbor)>= 1){
                    if(tempG < neighbor->getG()){
                        neighbor->setG(tempG);
                    }
                }else{
                    neighbor->setG(tempG);
                    openSet.push_back(neighbor);
                }
                neighbor->setH(heuristic(*neighbor, *end));
                neighbor->setF( neighbor->getG() + neighbor->getH());
                //cout << "F " << neighbor->getF() << " of (" << neighbor->getX() << " " << neighbor->getY() << ")" << endl;
                neighbor->setPrevious(current);
            }
        }
    }
    Serial.println("No solution");
    return pathFinal;
}