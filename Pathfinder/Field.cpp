#include "Field.h"
#include <Arduino.h>


Field::Field(){
    for(int i = 0; i < 3; ++i){
        matrix.emplace_back(Absis<Node*>());
        for(int j = 0; j <= 3; ++j){
            matrix[i].emplace_back(new Node(i, j));
        }
    }

    matrix.emplace_back(Absis<Node*>());
    matrix[3].emplace_back(new Node(3,0));

    for(int i = 4; i < 7; ++i){
        matrix.emplace_back(Absis<Node*>());
        for(int j = 0; j <= 3; ++j){
            matrix[i].emplace_back(new Node(i, j));
        }
    }     

    for(int i = 0; i < 7; ++i){
        for(int j = 0; j < 1; ++j){


            if(i - 1 == 3 && j == 0 ){
                continue;

            }

           if(i + 1 == 3 && j == 0 ){
                continue;

            }

            if(i - 1 >= 0){
                Serial.println("En el del uno ");
                Serial.print(i - 1);
                Serial.print(" ");
                Serial.println(j);

                matrix[i][j]->addNeighbor(matrix[i - 1][j]);
            }

            if(i + 1 <= 6){
                Serial.println(" EN el del seis ");
                Serial.print(i + 1);
                Serial.print(" ");
                Serial.println(j);

                matrix[i][j]->addNeighbor(matrix[i + 1][j]);
            }
        }
    }

    for(int i = 0; i < 7; ++i){
        if(i != 1 && i != 3 && i!= 5){
            for(int j = 0; j < 4; ++j){
                if(j - 1 >= 0){
                    matrix[i][j]->addNeighbor(matrix[i][j - 1]);
                }

                if(j + 1 <= 3){
                    matrix[i][j]->addNeighbor(matrix[i][j + 1]);
                }
            }
        }
    }


    matrix[0][1]->addNeighbor(matrix[2][1]);
    matrix[2][1]->addNeighbor(matrix[0][1]);

    // matrix[2][1]->addNeighbor(matrix[3][0]);
    // matrix[3][0]->addNeighbor(matrix[2][1]);

    matrix[2][1]->addNeighbor(matrix[1][2]);
    matrix[1][2]->addNeighbor(matrix[2][1]);

    matrix[2][1]->addNeighbor(matrix[4][1]);
    matrix[4][1]->addNeighbor(matrix[2][1]);

    matrix[1][2]->addNeighbor(matrix[1][3]);
    matrix[1][3]->addNeighbor(matrix[1][2]);

    // matrix[3][0]->addNeighbor(matrix[4][1]);
    // matrix[4][1]->addNeighbor(matrix[3][0]);

    matrix[4][1]->addNeighbor(matrix[6][1]);
    matrix[6][1]->addNeighbor(matrix[4][1]);

    matrix[4][1]->addNeighbor(matrix[5][2]);
    matrix[5][2]->addNeighbor(matrix[4][1]);

    matrix[5][3]->addNeighbor(matrix[5][2]);
    matrix[5][2]->addNeighbor(matrix[5][3]);


    printField();
};

void Field::printField(){
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            if(matrix[i][j] != nullptr){
                Serial.print(matrix[i][j]->getX());
                Serial.print(" ");
                Serial.print(matrix[i][j]->getY());
            } 
        }
        Serial.println();
    }

    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            if(matrix[i][j] != nullptr){
                matrix[i][j]->printNeighbors();
            } 
        }
        Serial.println();
    }
};

const Absis<Absis<Node*>>& Field::getField(){
    return matrix;      
};

void Field::cleanPreviousNodes(){
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            matrix[i][j]->clean();
        }
    }
};