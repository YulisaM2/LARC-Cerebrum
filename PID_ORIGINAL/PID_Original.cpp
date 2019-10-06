
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <PID_Original.h>

PID::PID(){
    Limites(0,255);
    miInput = 0;
    miSetPoint = 0;
    miOutput = 0;
    
    
    PID::Limites(0,255);            // Establecer Limites
    PID::Constantes(0,0,0);      // Establecer Constantes
    counter = true;
}

PID::PID(double *input, double *setPoint, double *output,double Kp, double Ki, double Kd, int caso){
    
    Limites(0,255);
    miInput = input;
    miSetPoint = setPoint;
    miOutput = output;
    this->caso = caso;
    
    PID::Limites(0,255);            // Establecer Limites
    PID::Constantes(Kp,Ki,Kd);
    counter = true;                    // Establecer Constantes
}

bool PID::Procesar(){
    if (counter == true){
        ultimoTiempo = millis();
        ultimoInput = *miInput;
    }
    counter = false;
    unsigned long ahora = millis();                     // Tiempo actual
    double cambioTiempo = (ahora-ultimoTiempo)/1000.0;
    double diferenciaInput = abs(*miInput-ultimoInput);
    int errorTemporal;
    /*
    Serial.println("Cambio Tiempo");
    Serial.println(cambioTiempo);
    Serial.println("Dif: ");
    
    Serial.println(diferenciaInput);
    */
    
    if (caso == 0){
        if (ultimoInput>*miInput){
            errorTemporal = ultimoInput-*miInput;
            if (errorTemporal>180){
                diferenciaInput = *miInput-ultimoInput +360;
            }else{
                diferenciaInput = ultimoInput - *miInput;
            }
        }else{
            errorTemporal = *miInput-ultimoInput;
            if (errorTemporal>180){
                diferenciaInput = ultimoInput-*miInput+360;
            }else{
                diferenciaInput = *miInput-ultimoInput;
            }
        }
    }
    
    if (caso == 0){
        
        if (*miInput>*miSetPoint){
            errorTemporal = *miInput-*miSetPoint;
            if (errorTemporal> 180){                    // Es como 350-10
                error = *miSetPoint- *miInput+ 360;
            }else{
                error = *miInput- * miSetPoint;
            }
        }else{
            errorTemporal = *miSetPoint-*miInput;
            if (errorTemporal>180){
                error = *miInput-*miSetPoint+360;
            }else{
                error = *miSetPoint-*miInput;
            }
        }
    }else{
    error = abs(*miInput- *miSetPoint);   // error normal
    }
    errorIntengral += error*cambioTiempo; //Integral suma
    if (diferenciaInput ==0 || cambioTiempo == 0){
        errorDerivada += 0;
    }else{
    errorDerivada += diferenciaInput/cambioTiempo;
    }
  
    
    
    // Derivada suma
    double output2;
    output2 = (Kp*error)+(Ki*errorIntengral)-(Kd*errorDerivada); // Formula
    /*Serial.print("Error Integral");
    Serial.println(Ki*errorIntengral);
    Serial.print("Error Derivada");
    Serial.println(Kd*errorDerivada);
     
      Serial.println(output2);
*/


    
    if (output2>outputMaximo) {
        output2 = outputMaximo;              // Si se pasa de los limites poner
    }else if (output2<outputMinimo){         // los limites como valores
        output2 = outputMinimo;
    }
    
    ultimoTiempo = ahora; // Se ajustan las variables anteriores a las actuales
    ultimoInput = *miInput;
    *miOutput = output2;
    
   /* Serial.print(output2);
    Serial.print(" ");
    Serial.println(error);
    */
}

void PID::quitarIntegral(){
    errorIntengral = 0;
}
void PID::quitarDerivada(){
    errorDerivada = 0;
}

void PID::Limites(double min, double max){
    outputMinimo = min;
    outputMaximo = max;
}

void PID::Constantes(double Kp, double Ki, double Kd){
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}
void PID::counterTrue(){
    this->counter = true;
}

double PID::obtenerKp(){
    return Kp;
}

double PID::obtenerKi(){
    return Ki;
}

double PID::obtenerKd(){
    return Kd;
}


