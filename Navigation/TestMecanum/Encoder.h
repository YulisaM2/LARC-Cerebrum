#ifndef __ENCODER_H_
#define __ENCODER_H_
#include <Arduino.h>

class Encoder {
public:
    Encoder(int a, int b);
    double getRotations();
    double getPosition();
    double getAngularPosition();
    double getAngularVelocity();
    int getA();
    int getB();
    void setPosition(double position);
    void setPulsesPerRotation(int pulsesPerRotation);
    void increase();
    void decrease();
private:
    void handleEncoderInterrupt();
    int a = 0;
    int b = 0;
    int position = 0;
    int pulsesPerRotation = 1;
    int lastRotations = 0;
    long lastTimeRead = millis() / 1000.0;
};
#endif