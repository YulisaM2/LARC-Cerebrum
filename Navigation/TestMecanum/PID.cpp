#include "PID.h"

PID::PID(PIDConfig config){
    setPIDConfig(config);
}

void PID::setSetpoint(double value){
    this->setpoint = value;
}

void PID::setReference(double value){
    this->currentReference = value;
}

double PID::getError(){
    return error;
}

double PID::getLastError(){
    return lastError;
}

double PID::getIntegral(){
    return errorIntegral;
}

const PIDConfig& PID::getPIDConfig(){
    return config;
}

void PID::setPIDConfig(PIDConfig config){
    this->config = config;
    maxError = (config.maxInput - config.minInput) / 2;
}

double PID::getOutput(){
    double sourceValue = currentReference;

    double rawError = setpoint - sourceValue;

    error = rawError;

    if(config.continous && abs(error) > maxError){
        int loops = floor(abs(error /( maxError * 2.0)))+ 1;
        error -= copysign((maxError * 2.0) * loops, error);
    }

    double errorDelta = (error - lastError);

    if(abs(error) >= config.iZone){
        errorIntegral += error;
    }else{
        errorIntegral = 0;
    }

    if(abs(errorIntegral) > config.maxAbsoluteItegral && config.maxAbsoluteItegral != -1){
        errorIntegral = copysign(config.maxAbsoluteItegral, errorIntegral);
    }

    double outputValue = (config.p * error) + (config.i * errorIntegral) + (config.d * errorDelta) + config.f;

    if(config.clamped && outputValue > config.maxOutput){
        outputValue = copysign(config.maxOutput, outputValue);
    }

    if(abs(outputValue) < config.deadband){
        outputValue = 0.0;
    }

    lastError = error;
    return outputValue;
}