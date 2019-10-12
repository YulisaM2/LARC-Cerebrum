#include "Encoder.h"

Encoder::Encoder(int a, int b){
    pinMode(a, INPUT);
    pinMode(b, INPUT);
};

double Encoder::getRotations(){
    return position / pulsesPerRotation;
};

double Encoder::getPosition(){
    return position;
};

double Encoder::getAngularPosition(){
    return getRotations() * 2 * M_PI;
};

double Encoder::getAngularVelocity(){
    double timeStep = (millis() / 1000.0) - lastTimeRead;

    double angularVelocity = (getAngularPosition() - lastRotations) / timeStep;
    lastRotations = getAngularPosition();

    lastTimeRead = millis() / 1000.0;
    return angularVelocity;
};

int Encoder::getA(){
    return a;
};

int Encoder::getB(){
    return b;
};

void Encoder::setPosition(double position){
    this->position = position;
};

void Encoder::setPulsesPerRotation(int pulsesPerRotation){
    this->pulsesPerRotation = pulsesPerRotation;
};

void Encoder::increase(){
    ++position;
};

void Encoder::decrease(){
    --position;
};