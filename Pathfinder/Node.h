#ifndef _NODE_H
#define _NODE_H

#include "Coord.h"
#include "Absis.h"

using namespace std;

class Node : public Coord{
    public:
        Node(int x, int y);

        void setF(int f);
        int getF();

        void setG(int g);
        int getG();

        void setH(int h);
        int getH();
        
        int getNeighborCounter();

        void addNeighbor(Node *neighbor);
        void printNeighbors();
        
        void clean();

        Node* getPrevious();
        void setPrevious(Node* previous);

        const Absis<Node*>& getNeighbors();
    private:
       int f = 0, g = 0, h = 0, neighborCounter = 0;
       Absis<Node*> neighbors;
       Node* previous = nullptr;
};

#endif