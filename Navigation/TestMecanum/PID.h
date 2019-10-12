#ifndef __PID_H_
#define __PID_H_
#include <Arduino.h>

class PIDConfig {
public:
    double p = 0;
    double i = 0;
    double d = 0;
    double f = 0;

    double iZone = 0;
    double maxAbsoluteItegral = -1;

    bool continous = false;

    double maxInput = 0;
    double minInput = 0;

    bool clamped = false;

    double maxOutput = 0;
    double minOutput = 0;

    double deadband = 0;

    bool operator==(const PIDConfig &rhs) const{
        return
                (p == rhs.p and
            i == rhs.i and
            d == rhs.d and
            f == rhs.f and

            iZone == rhs.iZone and
            maxAbsoluteItegral == rhs.maxAbsoluteItegral and
            continous == rhs.continous and

            maxInput == rhs.maxInput and
            minInput == rhs.minInput and

            clamped == rhs.clamped and

            maxOutput == rhs.maxOutput and
            minOutput == rhs.minOutput and

            deadband == rhs.deadband);
    }

    bool operator!=(const PIDConfig &rhs) const {
        return !(*this == rhs);
    }
};


class PID {
public:
    PID(PIDConfig config);
    void setSetpoint(double value);
    void setReference(double value);
    double getError();
    double getLastError();
    double getIntegral();
    double getOutput();
    const PIDConfig& getPIDConfig();
    void setPIDConfig(PIDConfig config);
private:
    double currentReference = 0;
    double setpoint = 0;
    double errorIntegral = 0;
    double lastError = 0;
    double error = 0;
    double maxError = 0;
    PIDConfig config;

    __ATTR_CONST__ static inline double copysign (double __x, double __y){
        __asm__ (
        "bst	%D2, 7	\n\t"
        "bld	%D0, 7	"
        : "=r" (__x)
        : "0" (__x), "r" (__y) );
        return __x;
    }
};

#endif