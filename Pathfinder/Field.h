#ifndef _FIELD_H
#define _FIELD_H

#include "Node.h"
#include "Absis.h"

#include <iostream>
using namespace std;
class Field{
    public:
        Field();
        void printField();
        const Absis<Absis<Node*>>& getField();
        void cleanPreviousNodes();
    private:
        Absis<Absis<Node*>> matrix;
};
#endif