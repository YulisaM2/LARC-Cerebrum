#include "Node.h"

Node::Node(int x, int y): Coord(x,y){
    f = 0;
    g = 0;
    h = 0;
    previous = nullptr;
};

void Node::setF(int f){
    this->f = f;
};

int Node::getF(){
    return this->f;
};

void Node::setG(int g){
    this->g = g;
};

int Node::getG(){
    return this->g;
};

void Node::setH(int h){
    this->h = h;
};

int Node::getH(){
    return this->h;
};

int Node::getNeighborCounter(){
    return this->neighborCounter;
};

void Node::addNeighbor(Node *neighbor){
    if(neighborCounter < 6){
        neighbors.emplace_back(neighbor);
        ++neighborCounter; 
    }
};
void Node::printNeighbors(){
    cout << "Neighbors of " << getX() << " " << getY() << endl;
    for(int i = 0; i < neighborCounter; ++i){
        cout << neighbors[i]->getX() << " " << neighbors[i]->getY() << " | ";
    }
    cout << endl;
};

Node* Node::getPrevious(){
    return this->previous;
};

void Node::setPrevious(Node* previous){
    this->previous = previous;
};

const Absis<Node*>& Node::getNeighbors(){
    return neighbors;
}

void Node::clean(){
    f = 0;
    g = 0;
    h = 0;
    previous = nullptr;
}
